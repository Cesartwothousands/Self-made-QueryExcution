# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /common/home/zc366/Documents/CS539_A2/Query_Excution

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /common/home/zc366/Documents/CS539_A2/Query_Excution/build

# Include any dependencies generated for this target.
include CMakeFiles/seq-scan-test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/seq-scan-test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/seq-scan-test.dir/flags.make

CMakeFiles/seq-scan-test.dir/test/seq_scan_test.cpp.o: CMakeFiles/seq-scan-test.dir/flags.make
CMakeFiles/seq-scan-test.dir/test/seq_scan_test.cpp.o: ../test/seq_scan_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/common/home/zc366/Documents/CS539_A2/Query_Excution/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/seq-scan-test.dir/test/seq_scan_test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/seq-scan-test.dir/test/seq_scan_test.cpp.o -c /common/home/zc366/Documents/CS539_A2/Query_Excution/test/seq_scan_test.cpp

CMakeFiles/seq-scan-test.dir/test/seq_scan_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/seq-scan-test.dir/test/seq_scan_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /common/home/zc366/Documents/CS539_A2/Query_Excution/test/seq_scan_test.cpp > CMakeFiles/seq-scan-test.dir/test/seq_scan_test.cpp.i

CMakeFiles/seq-scan-test.dir/test/seq_scan_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/seq-scan-test.dir/test/seq_scan_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /common/home/zc366/Documents/CS539_A2/Query_Excution/test/seq_scan_test.cpp -o CMakeFiles/seq-scan-test.dir/test/seq_scan_test.cpp.s

# Object files for target seq-scan-test
seq__scan__test_OBJECTS = \
"CMakeFiles/seq-scan-test.dir/test/seq_scan_test.cpp.o"

# External object files for target seq-scan-test
seq__scan__test_EXTERNAL_OBJECTS =

seq-scan-test: CMakeFiles/seq-scan-test.dir/test/seq_scan_test.cpp.o
seq-scan-test: CMakeFiles/seq-scan-test.dir/build.make
seq-scan-test: src/libEXECUTOR.a
seq-scan-test: CMakeFiles/seq-scan-test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/common/home/zc366/Documents/CS539_A2/Query_Excution/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable seq-scan-test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/seq-scan-test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/seq-scan-test.dir/build: seq-scan-test

.PHONY : CMakeFiles/seq-scan-test.dir/build

CMakeFiles/seq-scan-test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/seq-scan-test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/seq-scan-test.dir/clean

CMakeFiles/seq-scan-test.dir/depend:
	cd /common/home/zc366/Documents/CS539_A2/Query_Excution/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /common/home/zc366/Documents/CS539_A2/Query_Excution /common/home/zc366/Documents/CS539_A2/Query_Excution /common/home/zc366/Documents/CS539_A2/Query_Excution/build /common/home/zc366/Documents/CS539_A2/Query_Excution/build /common/home/zc366/Documents/CS539_A2/Query_Excution/build/CMakeFiles/seq-scan-test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/seq-scan-test.dir/depend

