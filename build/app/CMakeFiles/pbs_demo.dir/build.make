# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/2.8.10.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/2.8.10.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/local/Cellar/cmake/2.8.10.2/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/scottklum/cse870

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/scottklum/cse870/build

# Include any dependencies generated for this target.
include app/CMakeFiles/pbs_demo.dir/depend.make

# Include the progress variables for this target.
include app/CMakeFiles/pbs_demo.dir/progress.make

# Include the compile flags for this target's objects.
include app/CMakeFiles/pbs_demo.dir/flags.make

app/CMakeFiles/pbs_demo.dir/main.cpp.o: app/CMakeFiles/pbs_demo.dir/flags.make
app/CMakeFiles/pbs_demo.dir/main.cpp.o: ../app/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/scottklum/cse870/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object app/CMakeFiles/pbs_demo.dir/main.cpp.o"
	cd /Users/scottklum/cse870/build/app && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/pbs_demo.dir/main.cpp.o -c /Users/scottklum/cse870/app/main.cpp

app/CMakeFiles/pbs_demo.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pbs_demo.dir/main.cpp.i"
	cd /Users/scottklum/cse870/build/app && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/scottklum/cse870/app/main.cpp > CMakeFiles/pbs_demo.dir/main.cpp.i

app/CMakeFiles/pbs_demo.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pbs_demo.dir/main.cpp.s"
	cd /Users/scottklum/cse870/build/app && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/scottklum/cse870/app/main.cpp -o CMakeFiles/pbs_demo.dir/main.cpp.s

app/CMakeFiles/pbs_demo.dir/main.cpp.o.requires:
.PHONY : app/CMakeFiles/pbs_demo.dir/main.cpp.o.requires

app/CMakeFiles/pbs_demo.dir/main.cpp.o.provides: app/CMakeFiles/pbs_demo.dir/main.cpp.o.requires
	$(MAKE) -f app/CMakeFiles/pbs_demo.dir/build.make app/CMakeFiles/pbs_demo.dir/main.cpp.o.provides.build
.PHONY : app/CMakeFiles/pbs_demo.dir/main.cpp.o.provides

app/CMakeFiles/pbs_demo.dir/main.cpp.o.provides.build: app/CMakeFiles/pbs_demo.dir/main.cpp.o

# Object files for target pbs_demo
pbs_demo_OBJECTS = \
"CMakeFiles/pbs_demo.dir/main.cpp.o"

# External object files for target pbs_demo
pbs_demo_EXTERNAL_OBJECTS =

app/pbs_demo: app/CMakeFiles/pbs_demo.dir/main.cpp.o
app/pbs_demo: app/CMakeFiles/pbs_demo.dir/build.make
app/pbs_demo: /usr/local/Cellar/qt5/5.0.1/lib/QtConcurrent.framework/QtConcurrent
app/pbs_demo: /usr/local/Cellar/qt5/5.0.1/lib/QtCore.framework/QtCore
app/pbs_demo: /usr/local/Cellar/qt5/5.0.1/lib/QtGui.framework/QtGui
app/pbs_demo: /usr/local/Cellar/qt5/5.0.1/lib/QtNetwork.framework/QtNetwork
app/pbs_demo: /usr/local/Cellar/qt5/5.0.1/lib/QtSql.framework/QtSql
app/pbs_demo: /usr/local/Cellar/qt5/5.0.1/lib/QtSvg.framework/QtSvg
app/pbs_demo: /usr/local/Cellar/qt5/5.0.1/lib/QtWidgets.framework/QtWidgets
app/pbs_demo: /usr/local/Cellar/qt5/5.0.1/lib/QtXml.framework/QtXml
app/pbs_demo: sdk/libpbs.a
app/pbs_demo: /usr/local/Cellar/qt5/5.0.1/lib/QtConcurrent.framework/QtConcurrent
app/pbs_demo: /usr/local/Cellar/qt5/5.0.1/lib/QtNetwork.framework/QtNetwork
app/pbs_demo: /usr/local/Cellar/qt5/5.0.1/lib/QtSql.framework/QtSql
app/pbs_demo: /usr/local/Cellar/qt5/5.0.1/lib/QtSvg.framework/QtSvg
app/pbs_demo: /usr/local/Cellar/qt5/5.0.1/lib/QtWidgets.framework/QtWidgets
app/pbs_demo: /usr/local/Cellar/qt5/5.0.1/lib/QtGui.framework/QtGui
app/pbs_demo: /usr/local/Cellar/qt5/5.0.1/lib/QtXml.framework/QtXml
app/pbs_demo: /usr/local/Cellar/qt5/5.0.1/lib/QtCore.framework/QtCore
app/pbs_demo: app/CMakeFiles/pbs_demo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable pbs_demo"
	cd /Users/scottklum/cse870/build/app && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pbs_demo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
app/CMakeFiles/pbs_demo.dir/build: app/pbs_demo
.PHONY : app/CMakeFiles/pbs_demo.dir/build

app/CMakeFiles/pbs_demo.dir/requires: app/CMakeFiles/pbs_demo.dir/main.cpp.o.requires
.PHONY : app/CMakeFiles/pbs_demo.dir/requires

app/CMakeFiles/pbs_demo.dir/clean:
	cd /Users/scottklum/cse870/build/app && $(CMAKE_COMMAND) -P CMakeFiles/pbs_demo.dir/cmake_clean.cmake
.PHONY : app/CMakeFiles/pbs_demo.dir/clean

app/CMakeFiles/pbs_demo.dir/depend:
	cd /Users/scottklum/cse870/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/scottklum/cse870 /Users/scottklum/cse870/app /Users/scottklum/cse870/build /Users/scottklum/cse870/build/app /Users/scottklum/cse870/build/app/CMakeFiles/pbs_demo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : app/CMakeFiles/pbs_demo.dir/depend
