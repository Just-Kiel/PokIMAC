APPNAME := app

# Set proper RM on Windows
ifeq ($(OS),Windows_NT)
	RM := del /q /s
else
	RM := rm -rf 
endif

# Fix APPNAME on Windows
ifeq ($(OS),Windows_NT)
	APPNAME := $(APPNAME).exe
endif

# The directories where files will be stored
SRCDIR := src
OBJDIR := objs

# List of source .cpp files used with the project
SRCFILES = $(wildcard $(SRCDIR)/*.cpp)

# Replace .cpp extension on SRCFILES to get OBJFILES using gnu make pattern rules and substitution references.
# See https://www.gnu.org/software/make/manual/html_node/Pattern-Intro.html#Pattern-Intro for pattern rules and 
# https://www.gnu.org/software/make/manual/html_node/Substitution-Refs.html#Substitution-Refs for substitution references overview
OBJFILES = $(subst $(SRCDIR),$(OBJDIR), $(SRCFILES:.cpp=.o))
# Same for dep files
DEPFILES = $(OBJFILES:%.o=%.d)

# Flags passed to automatically build dependencies when compiling
# See https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html for detail about variable names
# -MP : https://man7.org/linux/man-pages/man1/g++.1.html#:~:text=updating%20of%20makefiles.-,%2DMP,-This%20option%20instructs
# -MT : force target name 
# DEPFLAGS = -MT $@ -MMD -MP
DEPFLAGS = -MMD -MP

# Add all warnings. This is not required but is a best practice
CPPFLAGS += -Wall -Wextra

all: $(APPNAME)
# Build the application by running the link step with all objfile inputs
$(APPNAME): $(OBJFILES)
	g++ $^ -o $(APPNAME)

# Define a rule to build object files based on .c or dependency files by making the associated dependency file
# a prerequisite of the target. Make the DEPDIR an order only prerequisite of the target, so it will be created when needed, meaning
# the targets won't get rebuilt when the timestamp on DEPDIR changes
# See https://www.gnu.org/software/make/manual/html_node/Prerequisite-Types.html for order only prerequesites overview.
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(OBJDIR)/%.d | $(OBJDIR)
	g++ $(DEPFLAGS) $(CPPFLAGS) -c $< -o $@

# Create the directory when it doesn't exist
$(OBJDIR): ; @mkdir -p $@

$(DEPFILES): # Mention each of the dependency files as a target, so make won't fail if the file doesn't exist

# Include all dependency files which exist, to include the relevant targets.
# See https://www.gnu.org/software/make/manual/html_node/Wildcard-Function.html for wildcard function documentation
include $(wildcard $(DEPFILES))

# Remove all build intermediates and output file
clean: ; $(RM) $(APPNAME) $(OBJDIR)

########   HELP   ########

# $@ references the target file of the rule and will be "main.o" when compiling "main.c"
# $* references the stem of the rule, and will be "main" when target is "main.o"
# $< the name of the first dependency
# $^ the list of all dependencies
