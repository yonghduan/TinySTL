# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Administrator\Desktop\TinySTL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Administrator\Desktop\TinySTL\cmake-build-debug

# Include any dependencies generated for this target.
include list/CMakeFiles/test.dir/depend.make
# Include the progress variables for this target.
include list/CMakeFiles/test.dir/progress.make

# Include the compile flags for this target's objects.
include list/CMakeFiles/test.dir/flags.make

list/CMakeFiles/test.dir/test.cpp.obj: list/CMakeFiles/test.dir/flags.make
list/CMakeFiles/test.dir/test.cpp.obj: list/CMakeFiles/test.dir/includes_CXX.rsp
list/CMakeFiles/test.dir/test.cpp.obj: ../list/test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Administrator\Desktop\TinySTL\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object list/CMakeFiles/test.dir/test.cpp.obj"
	cd /d C:\Users\Administrator\Desktop\TinySTL\cmake-build-debug\list && E:\MinGw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\test.dir\test.cpp.obj -c C:\Users\Administrator\Desktop\TinySTL\list\test.cpp

list/CMakeFiles/test.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/test.cpp.i"
	cd /d C:\Users\Administrator\Desktop\TinySTL\cmake-build-debug\list && E:\MinGw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Administrator\Desktop\TinySTL\list\test.cpp > CMakeFiles\test.dir\test.cpp.i

list/CMakeFiles/test.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/test.cpp.s"
	cd /d C:\Users\Administrator\Desktop\TinySTL\cmake-build-debug\list && E:\MinGw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Administrator\Desktop\TinySTL\list\test.cpp -o CMakeFiles\test.dir\test.cpp.s

# Object files for target test
test_OBJECTS = \
"CMakeFiles/test.dir/test.cpp.obj"

# External object files for target test
test_EXTERNAL_OBJECTS =

../bin/test.exe: list/CMakeFiles/test.dir/test.cpp.obj
../bin/test.exe: list/CMakeFiles/test.dir/build.make
../bin/test.exe: list/CMakeFiles/test.dir/linklibs.rsp
../bin/test.exe: list/CMakeFiles/test.dir/objects1.rsp
../bin/test.exe: list/CMakeFiles/test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Administrator\Desktop\TinySTL\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ..\..\bin\test.exe"
	cd /d C:\Users\Administrator\Desktop\TinySTL\cmake-build-debug\list && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\test.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
list/CMakeFiles/test.dir/build: ../bin/test.exe
.PHONY : list/CMakeFiles/test.dir/build

list/CMakeFiles/test.dir/clean:
	cd /d C:\Users\Administrator\Desktop\TinySTL\cmake-build-debug\list && $(CMAKE_COMMAND) -P CMakeFiles\test.dir\cmake_clean.cmake
.PHONY : list/CMakeFiles/test.dir/clean

list/CMakeFiles/test.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Administrator\Desktop\TinySTL C:\Users\Administrator\Desktop\TinySTL\list C:\Users\Administrator\Desktop\TinySTL\cmake-build-debug C:\Users\Administrator\Desktop\TinySTL\cmake-build-debug\list C:\Users\Administrator\Desktop\TinySTL\cmake-build-debug\list\CMakeFiles\test.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : list/CMakeFiles/test.dir/depend

