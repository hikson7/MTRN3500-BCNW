# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.18.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.18.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Hikari/Documents/GitHub/MTRN3500-BCNW/examples/cmake/project_root

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Hikari/Documents/GitHub/MTRN3500-BCNW/examples/cmake/project_root/build

# Include any dependencies generated for this target.
include modules/module_B/CMakeFiles/module_B.dir/depend.make

# Include the progress variables for this target.
include modules/module_B/CMakeFiles/module_B.dir/progress.make

# Include the compile flags for this target's objects.
include modules/module_B/CMakeFiles/module_B.dir/flags.make

modules/module_B/CMakeFiles/module_B.dir/mainB.cpp.o: modules/module_B/CMakeFiles/module_B.dir/flags.make
modules/module_B/CMakeFiles/module_B.dir/mainB.cpp.o: ../modules/module_B/mainB.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Hikari/Documents/GitHub/MTRN3500-BCNW/examples/cmake/project_root/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object modules/module_B/CMakeFiles/module_B.dir/mainB.cpp.o"
	cd /Users/Hikari/Documents/GitHub/MTRN3500-BCNW/examples/cmake/project_root/build/modules/module_B && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/module_B.dir/mainB.cpp.o -c /Users/Hikari/Documents/GitHub/MTRN3500-BCNW/examples/cmake/project_root/modules/module_B/mainB.cpp

modules/module_B/CMakeFiles/module_B.dir/mainB.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/module_B.dir/mainB.cpp.i"
	cd /Users/Hikari/Documents/GitHub/MTRN3500-BCNW/examples/cmake/project_root/build/modules/module_B && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Hikari/Documents/GitHub/MTRN3500-BCNW/examples/cmake/project_root/modules/module_B/mainB.cpp > CMakeFiles/module_B.dir/mainB.cpp.i

modules/module_B/CMakeFiles/module_B.dir/mainB.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/module_B.dir/mainB.cpp.s"
	cd /Users/Hikari/Documents/GitHub/MTRN3500-BCNW/examples/cmake/project_root/build/modules/module_B && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Hikari/Documents/GitHub/MTRN3500-BCNW/examples/cmake/project_root/modules/module_B/mainB.cpp -o CMakeFiles/module_B.dir/mainB.cpp.s

modules/module_B/CMakeFiles/module_B.dir/__/__/common_src/common_source_file1.cpp.o: modules/module_B/CMakeFiles/module_B.dir/flags.make
modules/module_B/CMakeFiles/module_B.dir/__/__/common_src/common_source_file1.cpp.o: ../common_src/common_source_file1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Hikari/Documents/GitHub/MTRN3500-BCNW/examples/cmake/project_root/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object modules/module_B/CMakeFiles/module_B.dir/__/__/common_src/common_source_file1.cpp.o"
	cd /Users/Hikari/Documents/GitHub/MTRN3500-BCNW/examples/cmake/project_root/build/modules/module_B && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/module_B.dir/__/__/common_src/common_source_file1.cpp.o -c /Users/Hikari/Documents/GitHub/MTRN3500-BCNW/examples/cmake/project_root/common_src/common_source_file1.cpp

modules/module_B/CMakeFiles/module_B.dir/__/__/common_src/common_source_file1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/module_B.dir/__/__/common_src/common_source_file1.cpp.i"
	cd /Users/Hikari/Documents/GitHub/MTRN3500-BCNW/examples/cmake/project_root/build/modules/module_B && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Hikari/Documents/GitHub/MTRN3500-BCNW/examples/cmake/project_root/common_src/common_source_file1.cpp > CMakeFiles/module_B.dir/__/__/common_src/common_source_file1.cpp.i

modules/module_B/CMakeFiles/module_B.dir/__/__/common_src/common_source_file1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/module_B.dir/__/__/common_src/common_source_file1.cpp.s"
	cd /Users/Hikari/Documents/GitHub/MTRN3500-BCNW/examples/cmake/project_root/build/modules/module_B && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Hikari/Documents/GitHub/MTRN3500-BCNW/examples/cmake/project_root/common_src/common_source_file1.cpp -o CMakeFiles/module_B.dir/__/__/common_src/common_source_file1.cpp.s

modules/module_B/CMakeFiles/module_B.dir/__/__/common_src/common_source_file2.cpp.o: modules/module_B/CMakeFiles/module_B.dir/flags.make
modules/module_B/CMakeFiles/module_B.dir/__/__/common_src/common_source_file2.cpp.o: ../common_src/common_source_file2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Hikari/Documents/GitHub/MTRN3500-BCNW/examples/cmake/project_root/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object modules/module_B/CMakeFiles/module_B.dir/__/__/common_src/common_source_file2.cpp.o"
	cd /Users/Hikari/Documents/GitHub/MTRN3500-BCNW/examples/cmake/project_root/build/modules/module_B && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/module_B.dir/__/__/common_src/common_source_file2.cpp.o -c /Users/Hikari/Documents/GitHub/MTRN3500-BCNW/examples/cmake/project_root/common_src/common_source_file2.cpp

modules/module_B/CMakeFiles/module_B.dir/__/__/common_src/common_source_file2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/module_B.dir/__/__/common_src/common_source_file2.cpp.i"
	cd /Users/Hikari/Documents/GitHub/MTRN3500-BCNW/examples/cmake/project_root/build/modules/module_B && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Hikari/Documents/GitHub/MTRN3500-BCNW/examples/cmake/project_root/common_src/common_source_file2.cpp > CMakeFiles/module_B.dir/__/__/common_src/common_source_file2.cpp.i

modules/module_B/CMakeFiles/module_B.dir/__/__/common_src/common_source_file2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/module_B.dir/__/__/common_src/common_source_file2.cpp.s"
	cd /Users/Hikari/Documents/GitHub/MTRN3500-BCNW/examples/cmake/project_root/build/modules/module_B && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Hikari/Documents/GitHub/MTRN3500-BCNW/examples/cmake/project_root/common_src/common_source_file2.cpp -o CMakeFiles/module_B.dir/__/__/common_src/common_source_file2.cpp.s

# Object files for target module_B
module_B_OBJECTS = \
"CMakeFiles/module_B.dir/mainB.cpp.o" \
"CMakeFiles/module_B.dir/__/__/common_src/common_source_file1.cpp.o" \
"CMakeFiles/module_B.dir/__/__/common_src/common_source_file2.cpp.o"

# External object files for target module_B
module_B_EXTERNAL_OBJECTS =

../bin/module_B: modules/module_B/CMakeFiles/module_B.dir/mainB.cpp.o
../bin/module_B: modules/module_B/CMakeFiles/module_B.dir/__/__/common_src/common_source_file1.cpp.o
../bin/module_B: modules/module_B/CMakeFiles/module_B.dir/__/__/common_src/common_source_file2.cpp.o
../bin/module_B: modules/module_B/CMakeFiles/module_B.dir/build.make
../bin/module_B: modules/module_B/CMakeFiles/module_B.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Hikari/Documents/GitHub/MTRN3500-BCNW/examples/cmake/project_root/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ../../../bin/module_B"
	cd /Users/Hikari/Documents/GitHub/MTRN3500-BCNW/examples/cmake/project_root/build/modules/module_B && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/module_B.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
modules/module_B/CMakeFiles/module_B.dir/build: ../bin/module_B

.PHONY : modules/module_B/CMakeFiles/module_B.dir/build

modules/module_B/CMakeFiles/module_B.dir/clean:
	cd /Users/Hikari/Documents/GitHub/MTRN3500-BCNW/examples/cmake/project_root/build/modules/module_B && $(CMAKE_COMMAND) -P CMakeFiles/module_B.dir/cmake_clean.cmake
.PHONY : modules/module_B/CMakeFiles/module_B.dir/clean

modules/module_B/CMakeFiles/module_B.dir/depend:
	cd /Users/Hikari/Documents/GitHub/MTRN3500-BCNW/examples/cmake/project_root/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Hikari/Documents/GitHub/MTRN3500-BCNW/examples/cmake/project_root /Users/Hikari/Documents/GitHub/MTRN3500-BCNW/examples/cmake/project_root/modules/module_B /Users/Hikari/Documents/GitHub/MTRN3500-BCNW/examples/cmake/project_root/build /Users/Hikari/Documents/GitHub/MTRN3500-BCNW/examples/cmake/project_root/build/modules/module_B /Users/Hikari/Documents/GitHub/MTRN3500-BCNW/examples/cmake/project_root/build/modules/module_B/CMakeFiles/module_B.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : modules/module_B/CMakeFiles/module_B.dir/depend

