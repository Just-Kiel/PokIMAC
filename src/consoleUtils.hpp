#pragma once

#include <iostream>
#include <string>
#include <cstdio>

// for sleep function
#include <chrono>
#include <thread>

#if defined(_WIN32) || defined(_WIN64)
	#include <windows.h>  // for WinAPI
	#include <conio.h>    // for getch() and kbhit()
#else
	#include <termios.h>
	#include <unistd.h>
	#include <sys/ioctl.h>
	#include <sys/socket.h>
#endif

class ConsoleUtils {

	public:

	// https://docs.microsoft.com/en-us/windows/console/console-screen-buffers#character-attributes
	enum Color { BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, YELLOW, WHITE, GREY, LIGHTBLUE, LIGHTGREEN, LIGHTCYAN, LIGHTRED, LIGHTMAGENTA, LIGHTYELLOW, LIGHTWHITE };
	enum BackgroundColor { BG_BLACK, BG_BLUE, BG_GREEN, BG_CYAN, BG_RED, BG_MAGENTA, BG_YELLOW, BG_WHITE };

	static const int KEY_UP = 65;
	static const int KEY_DOWN = 66;
	static const int KEY_RIGHT = 67;
	static const int KEY_LEFT = 68;

	static int getOneChar(void) {
#if defined(_WIN32) || defined(_WIN64)
		return _getch();
#else
		struct termios oldt, newt;
		int ch;
		tcgetattr(STDIN_FILENO, &oldt); /* grab old terminal i/o settings */
		newt = oldt; /* make new settings same as old settings */
		newt.c_lflag &= ~(ICANON | ECHO); /* disable buffered i/o and set no echo mode */
		tcsetattr(STDIN_FILENO, TCSANOW, &newt); /* use these new terminal i/o settings now */
		ch = getchar();
		tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
		return ch;
#endif
	}

	static int getChar(bool* special = nullptr) {
		if (special != nullptr) *special = false;
		int c = getOneChar();
#if defined(_WIN32) || defined(_WIN64)
		// https://www.it-swarm-fr.com/fr/c/codes-getch-et-arrow/1067145997/
		if (c == 0 || c == 224) { // special case with conio.h lib
			if (special != nullptr) *special = true;
			c = getOneChar();
			// fix for arrows keys windows api
			switch (c) {
				case 72: c = KEY_UP; break;
				case 80: c = KEY_DOWN; break;
				case 77: c = KEY_RIGHT; break;
				case 75: c = KEY_LEFT; break;
			}
		}
#else
		if (c == 27) { // '\033' check if the first value is ANSI esc (for escape complete sequence "\033[")
			c = getOneChar();
			if (c == 91) { // '['
				if (special != nullptr) *special = true;
			}
			c = getOneChar();
		}else if (c == 195) { // check UTF-8 char prefixe
			if (special != nullptr) *special = true;
			c = getOneChar();
		}
#endif
		return c;
	}

	static int kbhit() {
#if defined(_WIN32) || defined(_WIN64)
		return _kbhit();
#else
		static struct termios oldt, newt;
		int cnt = 0;
		tcgetattr(STDIN_FILENO, &oldt);
		newt = oldt;
		newt.c_lflag    &= ~(ICANON | ECHO);
		newt.c_iflag     = 0; // input mode
		newt.c_oflag     = 0; // output mode
		newt.c_cc[VMIN]  = 1; // minimum time to wait
		newt.c_cc[VTIME] = 1; // minimum characters to wait for
		tcsetattr(STDIN_FILENO, TCSANOW, &newt);
		ioctl(0, FIONREAD, &cnt); // Read count
		struct timeval tv = {0, 100};
		select(STDIN_FILENO+1, NULL, NULL, NULL, &tv); // A small time delay
		tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
		return cnt; // Return number of characters
#endif
	}

	static const char* ansiFromColor(const Color c) {
		switch(c) {
			case Color::BLACK : return "\033[22;30m";
			case Color::BLUE : return "\033[22;34m";
			case Color::GREEN : return "\033[22;32m";
			case Color::CYAN : return "\033[22;36m";
			case Color::RED : return "\033[22;31m";
			case Color::MAGENTA : return "\033[22;35m";
			case Color::YELLOW : return "\033[22;33m";
			case Color::WHITE : return "\033[22;37m";
			case Color::GREY : return "\033[01;30m";
			case Color::LIGHTBLUE : return "\033[01;34m";
			case Color::LIGHTGREEN : return "\033[01;32m";
			case Color::LIGHTCYAN : return "\033[01;36m";
			case Color::LIGHTRED : return "\033[01;31m";
			case Color::LIGHTMAGENTA : return "\033[01;35m";
			case Color::LIGHTYELLOW : return "\033[01;33m";
			case Color::LIGHTWHITE : return "\033[01;37m";
			default: return "";
		}
	}

	static const char* ansiFromBackgroundColor(const BackgroundColor c) {
		switch (c) {
			case BackgroundColor::BG_BLACK : return "\033[40m";
			case BackgroundColor::BG_BLUE : return "\033[44m";
			case BackgroundColor::BG_GREEN : return "\033[42m";
			case BackgroundColor::BG_CYAN : return "\033[46m";
			case BackgroundColor::BG_RED : return "\033[41m";
			case BackgroundColor::BG_MAGENTA : return "\033[45m";
			case BackgroundColor::BG_YELLOW : return "\033[43m";
			case BackgroundColor::BG_WHITE : return "\033[47m";
			default: return "";
		}
	}

	static void setColor(const Color c) {
#if defined(_WIN32) || defined(_WIN64)
		getInstance();
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(hConsole, &csbi);
		SetConsoleTextAttribute(hConsole, (csbi.wAttributes & 0xFFF0) | (WORD)c); // Foreground colors take up the least significant byte
#else
		std::cout << ansiFromColor(c);
#endif
	}

	static void setBackgroundColor(const BackgroundColor c) {
#if defined(_WIN32) || defined(_WIN64)
		getInstance();
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(hConsole, &csbi);
		SetConsoleTextAttribute(hConsole, (csbi.wAttributes & 0xFF0F) | (((WORD)c) << 4)); // Background colors take up the second-least significant byte
#else
		std::cout << ansiFromBackgroundColor(c);
#endif
	}

	static void resetColors() {
	#if defined(_WIN32) || defined(_WIN64)
		ConsoleUtils& instance = getInstance();
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, instance.defaultAttributes);
#else
		// ANSI_ATTRIBUTE_RESET
		std::cout << "\033[0m";
#endif
	}

	// Clears screen, resets all attributes and moves cursor home.
	static void clear(void) {
#if defined(_WIN32) || defined(_WIN64)
		getInstance();
		// Based on https://msdn.microsoft.com/en-us/library/windows/desktop/ms682022%28v=vs.85%29.aspx
		const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		const COORD coordScreen = {0, 0};
		DWORD cCharsWritten;
		CONSOLE_SCREEN_BUFFER_INFO csbi;

		GetConsoleScreenBufferInfo(hConsole, &csbi);
		const DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
		FillConsoleOutputCharacter(hConsole, (TCHAR)' ', dwConSize, coordScreen, &cCharsWritten);

		GetConsoleScreenBufferInfo(hConsole, &csbi);
		FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);

		SetConsoleCursorPosition(hConsole, coordScreen);
#else	
		// ANSI_CLS << ANSI_CURSOR_HOME
		std::cout << "\033[2J\033[3J" << "\033[H";
#endif
	}

	// uses 0-based coordinates
	static void setCursorPos(const short int x, const short int y) {
#if defined(_WIN32) || defined(_WIN64)
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {x, y});
#else
		// ANSI escape uses 1-based coordinates
		std::cout << "\033[" << y+1 << ";" << x+1 << "H";
#endif
	}

	private:

#if defined(_WIN32) || defined(_WIN64)
	static ConsoleUtils& getInstance() {
		static ConsoleUtils instance;
		return instance;
    }
#endif

	ConsoleUtils() {
#if defined(_WIN32) || defined(_WIN64)
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(hConsole, &csbi);
		defaultAttributes = csbi.wAttributes;
#endif
	}

	ConsoleUtils(ConsoleUtils const&) = delete;
    ConsoleUtils& operator=(ConsoleUtils const&) = delete;

#if defined(_WIN32) || defined(_WIN64)
	WORD defaultAttributes;
#endif

};
