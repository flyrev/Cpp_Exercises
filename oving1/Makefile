# Based on an original Makefile by http://stackoverflow.com/users/460741/fiz
# See the original question on http://stackoverflow.com/questions/14844268/makefile-template-for-large-c-project

# Put CppUTest in the libs folder if you want to use it, or remove the references from this file (as indicated below).
# Having put CppuTest there, go into it and type "make". Then this will all work (hopefully).

# Project Name (executable)
PROJECT = oving1

# Compiler
CXX = clang++

# Run Options       
COMMANDLINE_OPTIONS = /dev/ttyS0

# Remove this line if you're not using CppUTest
CPPUTEST_HOME=../libs/CppUTest

# Compiler options during compilation
COMPILE_OPTIONS = -ansi -pedantic -Wall -Weffc++

#Header include directories
#If not using CppUTest, change this to
#HEADERS = 
HEADERS = -I$(CPPUTEST_HOME)/include

#Libraries for linking
#If not using CppUTest, change this to
#LIBS = 
LIBS = -L$(CPPUTEST_HOME)/lib -lCppUTest 

# Dependency options
DEPENDENCY_OPTIONS = -MM $(HEADERS)

#-- Do not edit below this line --

# Subdirs to search for additional source files
SUBDIRS := $(shell ls -F | grep "\/" )
DIRS := ./ $(SUBDIRS)
SOURCE_FILES := $(foreach d, $(DIRS), $(wildcard $(d)*.cpp) )

# Create an object file of every cpp file
OBJECTS = $(patsubst %.cpp, %.o, $(SOURCE_FILES))

# Dependencies
DEPENDENCIES = $(patsubst %.cpp, %.d, $(SOURCE_FILES))

# Create .d files
%.d: %.cpp
	$(CXX) $(DEPENDENCY_OPTIONS) $< -MT "$*.o $*.d" -MF $*.d

# Make $(PROJECT) the default target
all: $(DEPENDENCIES) $(PROJECT)

$(PROJECT): $(OBJECTS)
	$(CXX) -o $(PROJECT) $(OBJECTS) $(LIBS)

# Include dependencies (if there are any)
ifneq "$(strip $(DEPENDENCIES))" ""
include $(DEPENDENCIES)
endif

# Compile every cpp file to an object
%.o: %.cpp
	$(CXX) -c $(COMPILE_OPTIONS) -o $@ $< $(HEADERS) 

# Build & Run Project
run: $(PROJECT)
	./$(PROJECT) $(COMMANDLINE_OPTIONS)

# Clean & Debug
.PHONY: makefile-debug
makefile-debug:

.PHONY: clean
clean:
	rm -f $(PROJECT) $(OBJECTS) $(DEPENDENCIES)

.PHONY: depclean
depclean:
	rm -f $(DEPENDENCIES)

clean-all: clean depclean
