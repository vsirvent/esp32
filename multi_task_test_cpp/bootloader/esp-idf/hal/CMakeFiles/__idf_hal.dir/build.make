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
CMAKE_SOURCE_DIR = /home/vsirvent/src/esp-idf/components/bootloader/subproject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vsirvent/src/mia/multi_task_test_cpp/bootloader

# Include any dependencies generated for this target.
include esp-idf/hal/CMakeFiles/__idf_hal.dir/depend.make

# Include the progress variables for this target.
include esp-idf/hal/CMakeFiles/__idf_hal.dir/progress.make

# Include the compile flags for this target's objects.
include esp-idf/hal/CMakeFiles/__idf_hal.dir/flags.make

esp-idf/hal/CMakeFiles/__idf_hal.dir/wdt_hal_iram.c.obj: esp-idf/hal/CMakeFiles/__idf_hal.dir/flags.make
esp-idf/hal/CMakeFiles/__idf_hal.dir/wdt_hal_iram.c.obj: /home/vsirvent/src/esp-idf/components/hal/wdt_hal_iram.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vsirvent/src/mia/multi_task_test_cpp/bootloader/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object esp-idf/hal/CMakeFiles/__idf_hal.dir/wdt_hal_iram.c.obj"
	cd /home/vsirvent/src/mia/multi_task_test_cpp/bootloader/esp-idf/hal && /home/vsirvent/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/__idf_hal.dir/wdt_hal_iram.c.obj   -c /home/vsirvent/src/esp-idf/components/hal/wdt_hal_iram.c

esp-idf/hal/CMakeFiles/__idf_hal.dir/wdt_hal_iram.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/__idf_hal.dir/wdt_hal_iram.c.i"
	cd /home/vsirvent/src/mia/multi_task_test_cpp/bootloader/esp-idf/hal && /home/vsirvent/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/vsirvent/src/esp-idf/components/hal/wdt_hal_iram.c > CMakeFiles/__idf_hal.dir/wdt_hal_iram.c.i

esp-idf/hal/CMakeFiles/__idf_hal.dir/wdt_hal_iram.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/__idf_hal.dir/wdt_hal_iram.c.s"
	cd /home/vsirvent/src/mia/multi_task_test_cpp/bootloader/esp-idf/hal && /home/vsirvent/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/vsirvent/src/esp-idf/components/hal/wdt_hal_iram.c -o CMakeFiles/__idf_hal.dir/wdt_hal_iram.c.s

esp-idf/hal/CMakeFiles/__idf_hal.dir/wdt_hal_iram.c.obj.requires:

.PHONY : esp-idf/hal/CMakeFiles/__idf_hal.dir/wdt_hal_iram.c.obj.requires

esp-idf/hal/CMakeFiles/__idf_hal.dir/wdt_hal_iram.c.obj.provides: esp-idf/hal/CMakeFiles/__idf_hal.dir/wdt_hal_iram.c.obj.requires
	$(MAKE) -f esp-idf/hal/CMakeFiles/__idf_hal.dir/build.make esp-idf/hal/CMakeFiles/__idf_hal.dir/wdt_hal_iram.c.obj.provides.build
.PHONY : esp-idf/hal/CMakeFiles/__idf_hal.dir/wdt_hal_iram.c.obj.provides

esp-idf/hal/CMakeFiles/__idf_hal.dir/wdt_hal_iram.c.obj.provides.build: esp-idf/hal/CMakeFiles/__idf_hal.dir/wdt_hal_iram.c.obj


esp-idf/hal/CMakeFiles/__idf_hal.dir/mpu_hal.c.obj: esp-idf/hal/CMakeFiles/__idf_hal.dir/flags.make
esp-idf/hal/CMakeFiles/__idf_hal.dir/mpu_hal.c.obj: /home/vsirvent/src/esp-idf/components/hal/mpu_hal.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vsirvent/src/mia/multi_task_test_cpp/bootloader/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object esp-idf/hal/CMakeFiles/__idf_hal.dir/mpu_hal.c.obj"
	cd /home/vsirvent/src/mia/multi_task_test_cpp/bootloader/esp-idf/hal && /home/vsirvent/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/__idf_hal.dir/mpu_hal.c.obj   -c /home/vsirvent/src/esp-idf/components/hal/mpu_hal.c

esp-idf/hal/CMakeFiles/__idf_hal.dir/mpu_hal.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/__idf_hal.dir/mpu_hal.c.i"
	cd /home/vsirvent/src/mia/multi_task_test_cpp/bootloader/esp-idf/hal && /home/vsirvent/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/vsirvent/src/esp-idf/components/hal/mpu_hal.c > CMakeFiles/__idf_hal.dir/mpu_hal.c.i

esp-idf/hal/CMakeFiles/__idf_hal.dir/mpu_hal.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/__idf_hal.dir/mpu_hal.c.s"
	cd /home/vsirvent/src/mia/multi_task_test_cpp/bootloader/esp-idf/hal && /home/vsirvent/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/vsirvent/src/esp-idf/components/hal/mpu_hal.c -o CMakeFiles/__idf_hal.dir/mpu_hal.c.s

esp-idf/hal/CMakeFiles/__idf_hal.dir/mpu_hal.c.obj.requires:

.PHONY : esp-idf/hal/CMakeFiles/__idf_hal.dir/mpu_hal.c.obj.requires

esp-idf/hal/CMakeFiles/__idf_hal.dir/mpu_hal.c.obj.provides: esp-idf/hal/CMakeFiles/__idf_hal.dir/mpu_hal.c.obj.requires
	$(MAKE) -f esp-idf/hal/CMakeFiles/__idf_hal.dir/build.make esp-idf/hal/CMakeFiles/__idf_hal.dir/mpu_hal.c.obj.provides.build
.PHONY : esp-idf/hal/CMakeFiles/__idf_hal.dir/mpu_hal.c.obj.provides

esp-idf/hal/CMakeFiles/__idf_hal.dir/mpu_hal.c.obj.provides.build: esp-idf/hal/CMakeFiles/__idf_hal.dir/mpu_hal.c.obj


esp-idf/hal/CMakeFiles/__idf_hal.dir/cpu_hal.c.obj: esp-idf/hal/CMakeFiles/__idf_hal.dir/flags.make
esp-idf/hal/CMakeFiles/__idf_hal.dir/cpu_hal.c.obj: /home/vsirvent/src/esp-idf/components/hal/cpu_hal.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vsirvent/src/mia/multi_task_test_cpp/bootloader/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object esp-idf/hal/CMakeFiles/__idf_hal.dir/cpu_hal.c.obj"
	cd /home/vsirvent/src/mia/multi_task_test_cpp/bootloader/esp-idf/hal && /home/vsirvent/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/__idf_hal.dir/cpu_hal.c.obj   -c /home/vsirvent/src/esp-idf/components/hal/cpu_hal.c

esp-idf/hal/CMakeFiles/__idf_hal.dir/cpu_hal.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/__idf_hal.dir/cpu_hal.c.i"
	cd /home/vsirvent/src/mia/multi_task_test_cpp/bootloader/esp-idf/hal && /home/vsirvent/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/vsirvent/src/esp-idf/components/hal/cpu_hal.c > CMakeFiles/__idf_hal.dir/cpu_hal.c.i

esp-idf/hal/CMakeFiles/__idf_hal.dir/cpu_hal.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/__idf_hal.dir/cpu_hal.c.s"
	cd /home/vsirvent/src/mia/multi_task_test_cpp/bootloader/esp-idf/hal && /home/vsirvent/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/vsirvent/src/esp-idf/components/hal/cpu_hal.c -o CMakeFiles/__idf_hal.dir/cpu_hal.c.s

esp-idf/hal/CMakeFiles/__idf_hal.dir/cpu_hal.c.obj.requires:

.PHONY : esp-idf/hal/CMakeFiles/__idf_hal.dir/cpu_hal.c.obj.requires

esp-idf/hal/CMakeFiles/__idf_hal.dir/cpu_hal.c.obj.provides: esp-idf/hal/CMakeFiles/__idf_hal.dir/cpu_hal.c.obj.requires
	$(MAKE) -f esp-idf/hal/CMakeFiles/__idf_hal.dir/build.make esp-idf/hal/CMakeFiles/__idf_hal.dir/cpu_hal.c.obj.provides.build
.PHONY : esp-idf/hal/CMakeFiles/__idf_hal.dir/cpu_hal.c.obj.provides

esp-idf/hal/CMakeFiles/__idf_hal.dir/cpu_hal.c.obj.provides.build: esp-idf/hal/CMakeFiles/__idf_hal.dir/cpu_hal.c.obj


# Object files for target __idf_hal
__idf_hal_OBJECTS = \
"CMakeFiles/__idf_hal.dir/wdt_hal_iram.c.obj" \
"CMakeFiles/__idf_hal.dir/mpu_hal.c.obj" \
"CMakeFiles/__idf_hal.dir/cpu_hal.c.obj"

# External object files for target __idf_hal
__idf_hal_EXTERNAL_OBJECTS =

esp-idf/hal/libhal.a: esp-idf/hal/CMakeFiles/__idf_hal.dir/wdt_hal_iram.c.obj
esp-idf/hal/libhal.a: esp-idf/hal/CMakeFiles/__idf_hal.dir/mpu_hal.c.obj
esp-idf/hal/libhal.a: esp-idf/hal/CMakeFiles/__idf_hal.dir/cpu_hal.c.obj
esp-idf/hal/libhal.a: esp-idf/hal/CMakeFiles/__idf_hal.dir/build.make
esp-idf/hal/libhal.a: esp-idf/hal/CMakeFiles/__idf_hal.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vsirvent/src/mia/multi_task_test_cpp/bootloader/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C static library libhal.a"
	cd /home/vsirvent/src/mia/multi_task_test_cpp/bootloader/esp-idf/hal && $(CMAKE_COMMAND) -P CMakeFiles/__idf_hal.dir/cmake_clean_target.cmake
	cd /home/vsirvent/src/mia/multi_task_test_cpp/bootloader/esp-idf/hal && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/__idf_hal.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
esp-idf/hal/CMakeFiles/__idf_hal.dir/build: esp-idf/hal/libhal.a

.PHONY : esp-idf/hal/CMakeFiles/__idf_hal.dir/build

esp-idf/hal/CMakeFiles/__idf_hal.dir/requires: esp-idf/hal/CMakeFiles/__idf_hal.dir/wdt_hal_iram.c.obj.requires
esp-idf/hal/CMakeFiles/__idf_hal.dir/requires: esp-idf/hal/CMakeFiles/__idf_hal.dir/mpu_hal.c.obj.requires
esp-idf/hal/CMakeFiles/__idf_hal.dir/requires: esp-idf/hal/CMakeFiles/__idf_hal.dir/cpu_hal.c.obj.requires

.PHONY : esp-idf/hal/CMakeFiles/__idf_hal.dir/requires

esp-idf/hal/CMakeFiles/__idf_hal.dir/clean:
	cd /home/vsirvent/src/mia/multi_task_test_cpp/bootloader/esp-idf/hal && $(CMAKE_COMMAND) -P CMakeFiles/__idf_hal.dir/cmake_clean.cmake
.PHONY : esp-idf/hal/CMakeFiles/__idf_hal.dir/clean

esp-idf/hal/CMakeFiles/__idf_hal.dir/depend:
	cd /home/vsirvent/src/mia/multi_task_test_cpp/bootloader && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vsirvent/src/esp-idf/components/bootloader/subproject /home/vsirvent/src/esp-idf/components/hal /home/vsirvent/src/mia/multi_task_test_cpp/bootloader /home/vsirvent/src/mia/multi_task_test_cpp/bootloader/esp-idf/hal /home/vsirvent/src/mia/multi_task_test_cpp/bootloader/esp-idf/hal/CMakeFiles/__idf_hal.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : esp-idf/hal/CMakeFiles/__idf_hal.dir/depend

