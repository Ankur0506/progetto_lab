# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_COMMAND = /home/ankur/Scrivania/clion-2017.1.1/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/ankur/Scrivania/clion-2017.1.1/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ankur/CLionProjects/FileIni

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ankur/CLionProjects/FileIni/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/FileIni.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/FileIni.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FileIni.dir/flags.make

CMakeFiles/FileIni.dir/main.cpp.o: CMakeFiles/FileIni.dir/flags.make
CMakeFiles/FileIni.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ankur/CLionProjects/FileIni/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/FileIni.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FileIni.dir/main.cpp.o -c /home/ankur/CLionProjects/FileIni/main.cpp

CMakeFiles/FileIni.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FileIni.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ankur/CLionProjects/FileIni/main.cpp > CMakeFiles/FileIni.dir/main.cpp.i

CMakeFiles/FileIni.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FileIni.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ankur/CLionProjects/FileIni/main.cpp -o CMakeFiles/FileIni.dir/main.cpp.s

CMakeFiles/FileIni.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/FileIni.dir/main.cpp.o.requires

CMakeFiles/FileIni.dir/main.cpp.o.provides: CMakeFiles/FileIni.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/FileIni.dir/build.make CMakeFiles/FileIni.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/FileIni.dir/main.cpp.o.provides

CMakeFiles/FileIni.dir/main.cpp.o.provides.build: CMakeFiles/FileIni.dir/main.cpp.o


# Object files for target FileIni
FileIni_OBJECTS = \
"CMakeFiles/FileIni.dir/main.cpp.o"

# External object files for target FileIni
FileIni_EXTERNAL_OBJECTS =

FileIni: CMakeFiles/FileIni.dir/main.cpp.o
FileIni: CMakeFiles/FileIni.dir/build.make
FileIni: CMakeFiles/FileIni.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ankur/CLionProjects/FileIni/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable FileIni"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FileIni.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FileIni.dir/build: FileIni

.PHONY : CMakeFiles/FileIni.dir/build

CMakeFiles/FileIni.dir/requires: CMakeFiles/FileIni.dir/main.cpp.o.requires

.PHONY : CMakeFiles/FileIni.dir/requires

CMakeFiles/FileIni.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FileIni.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FileIni.dir/clean

CMakeFiles/FileIni.dir/depend:
	cd /home/ankur/CLionProjects/FileIni/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ankur/CLionProjects/FileIni /home/ankur/CLionProjects/FileIni /home/ankur/CLionProjects/FileIni/cmake-build-debug /home/ankur/CLionProjects/FileIni/cmake-build-debug /home/ankur/CLionProjects/FileIni/cmake-build-debug/CMakeFiles/FileIni.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/FileIni.dir/depend
