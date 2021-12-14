#pragma once

#include <iostream>
#include <string>
#include <cstdio>

// for sleep function
#include <chrono>
#include <thread>

#if defined(WIN32) || defined(WIN64)
	#include <windows.h>  // for WinAPI
	#include <conio.h>    // for getch() and kbhit()

	namespace consoleUtils {
		static WORD DefaultAttributes;
		inline int Init() {
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			CONSOLE_SCREEN_BUFFER_INFO csbi;
			GetConsoleScreenBufferInfo(hConsole, &csbi);
			DefaultAttributes = csbi.wAttributes;
			return 0;
		}

		inline int getChar(void) { return _getch(); }
		inline int kbhit(void) { return _kbhit(); }
	}

#else
	#include <termios.h>
	#include <unistd.h>
	#include <sys/ioctl.h>

	namespace consoleUtils {
		inline int Init() { return 0; }

		/// Get character without waiting for Return to be pressed.
		/// Windows has this in conio.h
		inline int getChar(void) {
			struct termios oldt, newt;
			int ch;
			tcgetattr(STDIN_FILENO, &oldt); /* grab old terminal i/o settings */
			newt = oldt; /* make new settings same as old settings */
			newt.c_lflag &= ~(ICANON | ECHO); /* disable buffered i/o and set no echo mode */
			tcsetattr(STDIN_FILENO, TCSANOW, &newt); /* use these new terminal i/o settings now */
			ch = getchar();
			tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
			return ch;
		}

		// TODO: latency here to fix
		// Determines if keyboard has been hit.
		// Windows has this in conio.h
		inline int kbhit(void) {
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
			struct timeval tv;
			tv.tv_sec  = 0;
			tv.tv_usec = 100;
			select(STDIN_FILENO+1, NULL, NULL, NULL, &tv); // A small time delay
			tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
			return cnt; // Return number of characters
		}
	}

#endif // _WIN32

namespace consoleUtils {

	const int init_error = Init();

	inline void sleep(const unsigned int& ms) { std::this_thread::sleep_for(std::chrono::milliseconds(ms)); }
	// https://docs.microsoft.com/en-us/windows/console/console-screen-buffers#character-attributes
	enum class Color { BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, GREY, DARKGREY, LIGHTBLUE, LIGHTGREEN, LIGHTCYAN, LIGHTRED, LIGHTMAGENTA, YELLOW, WHITE };
	enum class BackgroundColor { BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE };

	inline const char* ansiFromColor(const Color c) {
		switch (c) {
			case Color::BLACK       : return "\033[22;30m";
			case Color::BLUE        : return "\033[22;31m";
			case Color::GREEN       : return "\033[22;32m";
			case Color::CYAN        : return "\033[22;32m";
			case Color::RED         : return "\033[22;34m";
			case Color::MAGENTA     : return "\033[22;35m";
			case Color::BROWN       : return "\033[22;36m";
			case Color::GREY        : return "\033[22;37m";
			case Color::DARKGREY    : return "\033[01;30m";
			case Color::LIGHTBLUE   : return "\033[01;31m";
			case Color::LIGHTGREEN  : return "\033[01;32m";
			case Color::LIGHTCYAN   : return "\033[01;33m";
			case Color::LIGHTRED    : return "\033[01;34m";
			case Color::LIGHTMAGENTA: return "\033[01;35m";
			case Color::YELLOW      : return "\033[01;36m";
			case Color::WHITE       : return "\033[01;37m";
			default: return "";
		}
	}

	inline const char* ansiFromBackgroundColor(const BackgroundColor c) {
		switch (c) {
			case BackgroundColor::BLACK : return "\033[40m";
			case BackgroundColor::RED : return "\033[41m";
			case BackgroundColor::GREEN : return "\033[42m";
			case BackgroundColor::YELLOW : return "\033[43m";
			case BackgroundColor::BLUE : return "\033[44m";
			case BackgroundColor::MAGENTA : return "\033[45m";
			case BackgroundColor::CYAN : return "\033[46m";
			case BackgroundColor::WHITE : return "\033[47m";
			default: return "";
		}
	}

	// Consts: ANSI escape strings
	const char* ANSI_CLS                = "\033[2J\033[3J";
	const char* ANSI_CONSOLE_TITLE_PRE  = "\033]0;";
	const char* ANSI_CONSOLE_TITLE_POST = "\007";
	const char* ANSI_ATTRIBUTE_RESET    = "\033[0m";
	const char* ANSI_CURSOR_HIDE        = "\033[?25l";
	const char* ANSI_CURSOR_SHOW        = "\033[?25h";
	const char* ANSI_CURSOR_HOME        = "\033[H";

	/// Non-blocking getch(). Returns 0 if no key was pressed.
	inline int nb_getChar(void) {
		if (kbhit()) return getChar();
		else return 0;
	}

	inline void setColor(const Color c) {
#if defined(WIN32) || defined(WIN64)
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(hConsole, &csbi);
		SetConsoleTextAttribute(hConsole, (csbi.wAttributes & 0xFFF0) | (WORD)c); // Foreground colors take up the least significant byte
#else
		std::cout << ansiFromColor(c);
#endif
	}

	inline void setBackgroundColor(const BackgroundColor c) {
#if defined(WIN32) || defined(WIN64)
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(hConsole, &csbi);
		SetConsoleTextAttribute(hConsole, (csbi.wAttributes & 0xFF0F) | (((WORD)c) << 4)); // Background colors take up the second-least significant byte
#else
		std::cout << ansiFromBackgroundColor(c);
#endif
	}

	inline void resetColors() {
	#if defined(WIN32) || defined(WIN64)
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, DefaultAttributes);
#else
		std::cout << ANSI_ATTRIBUTE_RESET;
#endif
	}


	// Clears screen, resets all attributes and moves cursor home.
	inline void clear(void) {
#if defined(WIN32) || defined(WIN64)
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
		std::cout << ANSI_CLS << ANSI_CURSOR_HOME;
#endif
	}

	inline void setCursorPos(const short int x, const short int y) {
#if defined(WIN32) || defined(WIN64)
		// Windows uses 0-based coordinates
		COORD coord;
		coord.X = (SHORT)(x - 1);
		coord.Y = (SHORT)(y - 1);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
#else
		std::cout << "\033[" << y << ";" << x << "H";
#endif
	}
}