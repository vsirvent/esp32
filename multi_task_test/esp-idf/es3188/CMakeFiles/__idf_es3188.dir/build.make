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
CMAKE_SOURCE_DIR = /home/vsirvent/src/mia/multi_task_test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vsirvent/src/mia/multi_task_test

# Include any dependencies generated for this target.
include esp-idf/es3188/CMakeFiles/__idf_es3188.dir/depend.make

# Include the progress variables for this target.
include esp-idf/es3188/CMakeFiles/__idf_es3188.dir/progress.make

# Include the compile flags for this target's objects.
include esp-idf/es3188/CMakeFiles/__idf_es3188.dir/flags.make

esp-idf/es3188/CMakeFiles/__idf_es3188.dir/es8311.c.obj: esp-idf/es3188/CMakeFiles/__idf_es3188.dir/flags.make
esp-idf/es3188/CMakeFiles/__idf_es3188.dir/es8311.c.obj: /home/vsirvent/src/esp-idf/components/es3188/es8311.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vsirvent/src/mia/multi_task_test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object esp-idf/es3188/CMakeFiles/__idf_es3188.dir/es8311.c.obj"
	cd /home/vsirvent/src/mia/multi_task_test/esp-idf/es3188 && /home/vsirvent/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/__idf_es3188.dir/es8311.c.obj   -c /home/vsirvent/src/esp-idf/components/es3188/es8311.c

esp-idf/es3188/CMakeFiles/__idf_es3188.dir/es8311.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/__idf_es3188.dir/es8311.c.i"
	cd /home/vsirvent/src/mia/multi_task_test/esp-idf/es3188 && /home/vsirvent/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/vsirvent/src/esp-idf/components/es3188/es8311.c > CMakeFiles/__idf_es3188.dir/es8311.c.i

esp-idf/es3188/CMakeFiles/__idf_es3188.dir/es8311.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/__idf_es3188.dir/es8311.c.s"
	cd /home/vsirvent/src/mia/multi_task_test/esp-idf/es3188 && /home/vsirvent/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/vsirvent/src/esp-idf/components/es3188/es8311.c -o CMakeFiles/__idf_es3188.dir/es8311.c.s

esp-idf/es3188/CMakeFiles/__idf_es3188.dir/es8311.c.obj.requires:

.PHONY : esp-idf/es3188/CMakeFiles/__idf_es3188.dir/es8311.c.obj.requires

esp-idf/es3188/CMakeFiles/__idf_es3188.dir/es8311.c.obj.provides: esp-idf/es3188/CMakeFiles/__idf_es3188.dir/es8311.c.obj.requires
	$(MAKE) -f esp-idf/es3188/CMakeFiles/__idf_es3188.dir/build.make esp-idf/es3188/CMakeFiles/__idf_es3188.dir/es8311.c.obj.provides.build
.PHONY : esp-idf/es3188/CMakeFiles/__idf_es3188.dir/es8311.c.obj.provides

esp-idf/es3188/CMakeFiles/__idf_es3188.dir/es8311.c.obj.provides.build: esp-idf/es3188/CMakeFiles/__idf_es3188.dir/es8311.c.obj


# Object files for target __idf_es3188
__idf_es3188_OBJECTS = \
"CMakeFiles/__idf_es3188.dir/es8311.c.obj"

# External object files for target __idf_es3188
__idf_es3188_EXTERNAL_OBJECTS =

esp-idf/es3188/libes3188.a: esp-idf/es3188/CMakeFiles/__idf_es3188.dir/es8311.c.obj
esp-idf/es3188/libes3188.a: esp-idf/es3188/CMakeFiles/__idf_es3188.dir/build.make
esp-idf/es3188/libes3188.a: esp-idf/es3188/CMakeFiles/__idf_es3188.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vsirvent/src/mia/multi_task_test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libes3188.a"
	cd /home/vsirvent/src/mia/multi_task_test/esp-idf/es3188 && $(CMAKE_COMMAND) -P CMakeFiles/__idf_es3188.dir/cmake_clean_target.cmake
	cd /home/vsirvent/src/mia/multi_task_test/esp-idf/es3188 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/__idf_es3188.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
esp-idf/es3188/CMakeFiles/__idf_es3188.dir/build: esp-idf/es3188/libes3188.a

.PHONY : esp-idf/es3188/CMakeFiles/__idf_es3188.dir/build

esp-idf/es3188/CMakeFiles/__idf_es3188.dir/requires: esp-idf/es3188/CMakeFiles/__idf_es3188.dir/es8311.c.obj.requires

.PHONY : esp-idf/es3188/CMakeFiles/__idf_es3188.dir/requires

esp-idf/es3188/CMakeFiles/__idf_es3188.dir/clean:
	cd /home/vsirvent/src/mia/multi_task_test/esp-idf/es3188 && $(CMAKE_COMMAND) -P CMakeFiles/__idf_es3188.dir/cmake_clean.cmake
.PHONY : esp-idf/es3188/CMakeFiles/__idf_es3188.dir/clean

esp-idf/es3188/CMakeFiles/__idf_es3188.dir/depend:
	cd /home/vsirvent/src/mia/multi_task_test && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vsirvent/src/mia/multi_task_test /home/vsirvent/src/esp-idf/components/es3188 /home/vsirvent/src/mia/multi_task_test /home/vsirvent/src/mia/multi_task_test/esp-idf/es3188 /home/vsirvent/src/mia/multi_task_test/esp-idf/es3188/CMakeFiles/__idf_es3188.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : esp-idf/es3188/CMakeFiles/__idf_es3188.dir/depend

