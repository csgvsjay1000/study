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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/feng/study/chat_06

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/feng/study/chat_06

# Include any dependencies generated for this target.
include CMakeFiles/websrv.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/websrv.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/websrv.dir/flags.make

CMakeFiles/websrv.dir/main.o: CMakeFiles/websrv.dir/flags.make
CMakeFiles/websrv.dir/main.o: main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/feng/study/chat_06/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/websrv.dir/main.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/websrv.dir/main.o -c /home/feng/study/chat_06/main.cpp

CMakeFiles/websrv.dir/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/websrv.dir/main.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/feng/study/chat_06/main.cpp > CMakeFiles/websrv.dir/main.i

CMakeFiles/websrv.dir/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/websrv.dir/main.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/feng/study/chat_06/main.cpp -o CMakeFiles/websrv.dir/main.s

CMakeFiles/websrv.dir/main.o.requires:
.PHONY : CMakeFiles/websrv.dir/main.o.requires

CMakeFiles/websrv.dir/main.o.provides: CMakeFiles/websrv.dir/main.o.requires
	$(MAKE) -f CMakeFiles/websrv.dir/build.make CMakeFiles/websrv.dir/main.o.provides.build
.PHONY : CMakeFiles/websrv.dir/main.o.provides

CMakeFiles/websrv.dir/main.o.provides.build: CMakeFiles/websrv.dir/main.o

# Object files for target websrv
websrv_OBJECTS = \
"CMakeFiles/websrv.dir/main.o"

# External object files for target websrv
websrv_EXTERNAL_OBJECTS =

websrv: CMakeFiles/websrv.dir/main.o
websrv: CMakeFiles/websrv.dir/build.make
websrv: CMakeFiles/websrv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable websrv"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/websrv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/websrv.dir/build: websrv
.PHONY : CMakeFiles/websrv.dir/build

CMakeFiles/websrv.dir/requires: CMakeFiles/websrv.dir/main.o.requires
.PHONY : CMakeFiles/websrv.dir/requires

CMakeFiles/websrv.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/websrv.dir/cmake_clean.cmake
.PHONY : CMakeFiles/websrv.dir/clean

CMakeFiles/websrv.dir/depend:
	cd /home/feng/study/chat_06 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/feng/study/chat_06 /home/feng/study/chat_06 /home/feng/study/chat_06 /home/feng/study/chat_06 /home/feng/study/chat_06/CMakeFiles/websrv.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/websrv.dir/depend

