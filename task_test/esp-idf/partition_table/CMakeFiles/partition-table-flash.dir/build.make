# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/vsirvent/src/mia/task_test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vsirvent/src/mia/task_test

# Utility rule file for partition-table-flash.

# Include the progress variables for this target.
include esp-idf/partition_table/CMakeFiles/partition-table-flash.dir/progress.make

esp-idf/partition_table/CMakeFiles/partition-table-flash:
	cd /home/vsirvent/src/esp-idf/components/partition_table && /usr/bin/cmake -D IDF_PATH="/home/vsirvent/src/esp-idf" -D SERIAL_TOOL="python /home/vsirvent/src/esp-idf/components/esptool_py/esptool/esptool.py --chip esp32" -D SERIAL_TOOL_ARGS="--before=default_reset --after=hard_reset write_flash @partition-table-flash_args" -D WORKING_DIRECTORY="/home/vsirvent/src/mia/task_test" -P /home/vsirvent/src/esp-idf/components/esptool_py/run_serial_tool.cmake

partition-table-flash: esp-idf/partition_table/CMakeFiles/partition-table-flash
partition-table-flash: esp-idf/partition_table/CMakeFiles/partition-table-flash.dir/build.make

.PHONY : partition-table-flash

# Rule to build all files generated by this target.
esp-idf/partition_table/CMakeFiles/partition-table-flash.dir/build: partition-table-flash

.PHONY : esp-idf/partition_table/CMakeFiles/partition-table-flash.dir/build

esp-idf/partition_table/CMakeFiles/partition-table-flash.dir/clean:
	cd /home/vsirvent/src/mia/task_test/esp-idf/partition_table && $(CMAKE_COMMAND) -P CMakeFiles/partition-table-flash.dir/cmake_clean.cmake
.PHONY : esp-idf/partition_table/CMakeFiles/partition-table-flash.dir/clean

esp-idf/partition_table/CMakeFiles/partition-table-flash.dir/depend:
	cd /home/vsirvent/src/mia/task_test && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vsirvent/src/mia/task_test /home/vsirvent/src/esp-idf/components/partition_table /home/vsirvent/src/mia/task_test /home/vsirvent/src/mia/task_test/esp-idf/partition_table /home/vsirvent/src/mia/task_test/esp-idf/partition_table/CMakeFiles/partition-table-flash.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : esp-idf/partition_table/CMakeFiles/partition-table-flash.dir/depend
