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

# Include any dependencies generated for this target.
include esp-idf/console/CMakeFiles/__idf_console.dir/depend.make

# Include the progress variables for this target.
include esp-idf/console/CMakeFiles/__idf_console.dir/progress.make

# Include the compile flags for this target's objects.
include esp-idf/console/CMakeFiles/__idf_console.dir/flags.make

esp-idf/console/CMakeFiles/__idf_console.dir/commands.c.obj: esp-idf/console/CMakeFiles/__idf_console.dir/flags.make
esp-idf/console/CMakeFiles/__idf_console.dir/commands.c.obj: /home/vsirvent/src/esp-idf/components/console/commands.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vsirvent/src/mia/task_test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object esp-idf/console/CMakeFiles/__idf_console.dir/commands.c.obj"
	cd /home/vsirvent/src/mia/task_test/esp-idf/console && /home/vsirvent/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/__idf_console.dir/commands.c.obj   -c /home/vsirvent/src/esp-idf/components/console/commands.c

esp-idf/console/CMakeFiles/__idf_console.dir/commands.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/__idf_console.dir/commands.c.i"
	cd /home/vsirvent/src/mia/task_test/esp-idf/console && /home/vsirvent/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/vsirvent/src/esp-idf/components/console/commands.c > CMakeFiles/__idf_console.dir/commands.c.i

esp-idf/console/CMakeFiles/__idf_console.dir/commands.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/__idf_console.dir/commands.c.s"
	cd /home/vsirvent/src/mia/task_test/esp-idf/console && /home/vsirvent/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/vsirvent/src/esp-idf/components/console/commands.c -o CMakeFiles/__idf_console.dir/commands.c.s

esp-idf/console/CMakeFiles/__idf_console.dir/commands.c.obj.requires:

.PHONY : esp-idf/console/CMakeFiles/__idf_console.dir/commands.c.obj.requires

esp-idf/console/CMakeFiles/__idf_console.dir/commands.c.obj.provides: esp-idf/console/CMakeFiles/__idf_console.dir/commands.c.obj.requires
	$(MAKE) -f esp-idf/console/CMakeFiles/__idf_console.dir/build.make esp-idf/console/CMakeFiles/__idf_console.dir/commands.c.obj.provides.build
.PHONY : esp-idf/console/CMakeFiles/__idf_console.dir/commands.c.obj.provides

esp-idf/console/CMakeFiles/__idf_console.dir/commands.c.obj.provides.build: esp-idf/console/CMakeFiles/__idf_console.dir/commands.c.obj


esp-idf/console/CMakeFiles/__idf_console.dir/esp_console_repl.c.obj: esp-idf/console/CMakeFiles/__idf_console.dir/flags.make
esp-idf/console/CMakeFiles/__idf_console.dir/esp_console_repl.c.obj: /home/vsirvent/src/esp-idf/components/console/esp_console_repl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vsirvent/src/mia/task_test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object esp-idf/console/CMakeFiles/__idf_console.dir/esp_console_repl.c.obj"
	cd /home/vsirvent/src/mia/task_test/esp-idf/console && /home/vsirvent/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/__idf_console.dir/esp_console_repl.c.obj   -c /home/vsirvent/src/esp-idf/components/console/esp_console_repl.c

esp-idf/console/CMakeFiles/__idf_console.dir/esp_console_repl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/__idf_console.dir/esp_console_repl.c.i"
	cd /home/vsirvent/src/mia/task_test/esp-idf/console && /home/vsirvent/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/vsirvent/src/esp-idf/components/console/esp_console_repl.c > CMakeFiles/__idf_console.dir/esp_console_repl.c.i

esp-idf/console/CMakeFiles/__idf_console.dir/esp_console_repl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/__idf_console.dir/esp_console_repl.c.s"
	cd /home/vsirvent/src/mia/task_test/esp-idf/console && /home/vsirvent/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/vsirvent/src/esp-idf/components/console/esp_console_repl.c -o CMakeFiles/__idf_console.dir/esp_console_repl.c.s

esp-idf/console/CMakeFiles/__idf_console.dir/esp_console_repl.c.obj.requires:

.PHONY : esp-idf/console/CMakeFiles/__idf_console.dir/esp_console_repl.c.obj.requires

esp-idf/console/CMakeFiles/__idf_console.dir/esp_console_repl.c.obj.provides: esp-idf/console/CMakeFiles/__idf_console.dir/esp_console_repl.c.obj.requires
	$(MAKE) -f esp-idf/console/CMakeFiles/__idf_console.dir/build.make esp-idf/console/CMakeFiles/__idf_console.dir/esp_console_repl.c.obj.provides.build
.PHONY : esp-idf/console/CMakeFiles/__idf_console.dir/esp_console_repl.c.obj.provides

esp-idf/console/CMakeFiles/__idf_console.dir/esp_console_repl.c.obj.provides.build: esp-idf/console/CMakeFiles/__idf_console.dir/esp_console_repl.c.obj


esp-idf/console/CMakeFiles/__idf_console.dir/split_argv.c.obj: esp-idf/console/CMakeFiles/__idf_console.dir/flags.make
esp-idf/console/CMakeFiles/__idf_console.dir/split_argv.c.obj: /home/vsirvent/src/esp-idf/components/console/split_argv.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vsirvent/src/mia/task_test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object esp-idf/console/CMakeFiles/__idf_console.dir/split_argv.c.obj"
	cd /home/vsirvent/src/mia/task_test/esp-idf/console && /home/vsirvent/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/__idf_console.dir/split_argv.c.obj   -c /home/vsirvent/src/esp-idf/components/console/split_argv.c

esp-idf/console/CMakeFiles/__idf_console.dir/split_argv.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/__idf_console.dir/split_argv.c.i"
	cd /home/vsirvent/src/mia/task_test/esp-idf/console && /home/vsirvent/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/vsirvent/src/esp-idf/components/console/split_argv.c > CMakeFiles/__idf_console.dir/split_argv.c.i

esp-idf/console/CMakeFiles/__idf_console.dir/split_argv.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/__idf_console.dir/split_argv.c.s"
	cd /home/vsirvent/src/mia/task_test/esp-idf/console && /home/vsirvent/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/vsirvent/src/esp-idf/components/console/split_argv.c -o CMakeFiles/__idf_console.dir/split_argv.c.s

esp-idf/console/CMakeFiles/__idf_console.dir/split_argv.c.obj.requires:

.PHONY : esp-idf/console/CMakeFiles/__idf_console.dir/split_argv.c.obj.requires

esp-idf/console/CMakeFiles/__idf_console.dir/split_argv.c.obj.provides: esp-idf/console/CMakeFiles/__idf_console.dir/split_argv.c.obj.requires
	$(MAKE) -f esp-idf/console/CMakeFiles/__idf_console.dir/build.make esp-idf/console/CMakeFiles/__idf_console.dir/split_argv.c.obj.provides.build
.PHONY : esp-idf/console/CMakeFiles/__idf_console.dir/split_argv.c.obj.provides

esp-idf/console/CMakeFiles/__idf_console.dir/split_argv.c.obj.provides.build: esp-idf/console/CMakeFiles/__idf_console.dir/split_argv.c.obj


esp-idf/console/CMakeFiles/__idf_console.dir/argtable3/argtable3.c.obj: esp-idf/console/CMakeFiles/__idf_console.dir/flags.make
esp-idf/console/CMakeFiles/__idf_console.dir/argtable3/argtable3.c.obj: /home/vsirvent/src/esp-idf/components/console/argtable3/argtable3.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vsirvent/src/mia/task_test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object esp-idf/console/CMakeFiles/__idf_console.dir/argtable3/argtable3.c.obj"
	cd /home/vsirvent/src/mia/task_test/esp-idf/console && /home/vsirvent/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -Wno-clobbered -o CMakeFiles/__idf_console.dir/argtable3/argtable3.c.obj   -c /home/vsirvent/src/esp-idf/components/console/argtable3/argtable3.c

esp-idf/console/CMakeFiles/__idf_console.dir/argtable3/argtable3.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/__idf_console.dir/argtable3/argtable3.c.i"
	cd /home/vsirvent/src/mia/task_test/esp-idf/console && /home/vsirvent/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -Wno-clobbered -E /home/vsirvent/src/esp-idf/components/console/argtable3/argtable3.c > CMakeFiles/__idf_console.dir/argtable3/argtable3.c.i

esp-idf/console/CMakeFiles/__idf_console.dir/argtable3/argtable3.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/__idf_console.dir/argtable3/argtable3.c.s"
	cd /home/vsirvent/src/mia/task_test/esp-idf/console && /home/vsirvent/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -Wno-clobbered -S /home/vsirvent/src/esp-idf/components/console/argtable3/argtable3.c -o CMakeFiles/__idf_console.dir/argtable3/argtable3.c.s

esp-idf/console/CMakeFiles/__idf_console.dir/argtable3/argtable3.c.obj.requires:

.PHONY : esp-idf/console/CMakeFiles/__idf_console.dir/argtable3/argtable3.c.obj.requires

esp-idf/console/CMakeFiles/__idf_console.dir/argtable3/argtable3.c.obj.provides: esp-idf/console/CMakeFiles/__idf_console.dir/argtable3/argtable3.c.obj.requires
	$(MAKE) -f esp-idf/console/CMakeFiles/__idf_console.dir/build.make esp-idf/console/CMakeFiles/__idf_console.dir/argtable3/argtable3.c.obj.provides.build
.PHONY : esp-idf/console/CMakeFiles/__idf_console.dir/argtable3/argtable3.c.obj.provides

esp-idf/console/CMakeFiles/__idf_console.dir/argtable3/argtable3.c.obj.provides.build: esp-idf/console/CMakeFiles/__idf_console.dir/argtable3/argtable3.c.obj


esp-idf/console/CMakeFiles/__idf_console.dir/linenoise/linenoise.c.obj: esp-idf/console/CMakeFiles/__idf_console.dir/flags.make
esp-idf/console/CMakeFiles/__idf_console.dir/linenoise/linenoise.c.obj: /home/vsirvent/src/esp-idf/components/console/linenoise/linenoise.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vsirvent/src/mia/task_test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object esp-idf/console/CMakeFiles/__idf_console.dir/linenoise/linenoise.c.obj"
	cd /home/vsirvent/src/mia/task_test/esp-idf/console && /home/vsirvent/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/__idf_console.dir/linenoise/linenoise.c.obj   -c /home/vsirvent/src/esp-idf/components/console/linenoise/linenoise.c

esp-idf/console/CMakeFiles/__idf_console.dir/linenoise/linenoise.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/__idf_console.dir/linenoise/linenoise.c.i"
	cd /home/vsirvent/src/mia/task_test/esp-idf/console && /home/vsirvent/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/vsirvent/src/esp-idf/components/console/linenoise/linenoise.c > CMakeFiles/__idf_console.dir/linenoise/linenoise.c.i

esp-idf/console/CMakeFiles/__idf_console.dir/linenoise/linenoise.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/__idf_console.dir/linenoise/linenoise.c.s"
	cd /home/vsirvent/src/mia/task_test/esp-idf/console && /home/vsirvent/.espressif/tools/xtensa-esp32-elf/esp-2021r2-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/vsirvent/src/esp-idf/components/console/linenoise/linenoise.c -o CMakeFiles/__idf_console.dir/linenoise/linenoise.c.s

esp-idf/console/CMakeFiles/__idf_console.dir/linenoise/linenoise.c.obj.requires:

.PHONY : esp-idf/console/CMakeFiles/__idf_console.dir/linenoise/linenoise.c.obj.requires

esp-idf/console/CMakeFiles/__idf_console.dir/linenoise/linenoise.c.obj.provides: esp-idf/console/CMakeFiles/__idf_console.dir/linenoise/linenoise.c.obj.requires
	$(MAKE) -f esp-idf/console/CMakeFiles/__idf_console.dir/build.make esp-idf/console/CMakeFiles/__idf_console.dir/linenoise/linenoise.c.obj.provides.build
.PHONY : esp-idf/console/CMakeFiles/__idf_console.dir/linenoise/linenoise.c.obj.provides

esp-idf/console/CMakeFiles/__idf_console.dir/linenoise/linenoise.c.obj.provides.build: esp-idf/console/CMakeFiles/__idf_console.dir/linenoise/linenoise.c.obj


# Object files for target __idf_console
__idf_console_OBJECTS = \
"CMakeFiles/__idf_console.dir/commands.c.obj" \
"CMakeFiles/__idf_console.dir/esp_console_repl.c.obj" \
"CMakeFiles/__idf_console.dir/split_argv.c.obj" \
"CMakeFiles/__idf_console.dir/argtable3/argtable3.c.obj" \
"CMakeFiles/__idf_console.dir/linenoise/linenoise.c.obj"

# External object files for target __idf_console
__idf_console_EXTERNAL_OBJECTS =

esp-idf/console/libconsole.a: esp-idf/console/CMakeFiles/__idf_console.dir/commands.c.obj
esp-idf/console/libconsole.a: esp-idf/console/CMakeFiles/__idf_console.dir/esp_console_repl.c.obj
esp-idf/console/libconsole.a: esp-idf/console/CMakeFiles/__idf_console.dir/split_argv.c.obj
esp-idf/console/libconsole.a: esp-idf/console/CMakeFiles/__idf_console.dir/argtable3/argtable3.c.obj
esp-idf/console/libconsole.a: esp-idf/console/CMakeFiles/__idf_console.dir/linenoise/linenoise.c.obj
esp-idf/console/libconsole.a: esp-idf/console/CMakeFiles/__idf_console.dir/build.make
esp-idf/console/libconsole.a: esp-idf/console/CMakeFiles/__idf_console.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vsirvent/src/mia/task_test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C static library libconsole.a"
	cd /home/vsirvent/src/mia/task_test/esp-idf/console && $(CMAKE_COMMAND) -P CMakeFiles/__idf_console.dir/cmake_clean_target.cmake
	cd /home/vsirvent/src/mia/task_test/esp-idf/console && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/__idf_console.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
esp-idf/console/CMakeFiles/__idf_console.dir/build: esp-idf/console/libconsole.a

.PHONY : esp-idf/console/CMakeFiles/__idf_console.dir/build

esp-idf/console/CMakeFiles/__idf_console.dir/requires: esp-idf/console/CMakeFiles/__idf_console.dir/commands.c.obj.requires
esp-idf/console/CMakeFiles/__idf_console.dir/requires: esp-idf/console/CMakeFiles/__idf_console.dir/esp_console_repl.c.obj.requires
esp-idf/console/CMakeFiles/__idf_console.dir/requires: esp-idf/console/CMakeFiles/__idf_console.dir/split_argv.c.obj.requires
esp-idf/console/CMakeFiles/__idf_console.dir/requires: esp-idf/console/CMakeFiles/__idf_console.dir/argtable3/argtable3.c.obj.requires
esp-idf/console/CMakeFiles/__idf_console.dir/requires: esp-idf/console/CMakeFiles/__idf_console.dir/linenoise/linenoise.c.obj.requires

.PHONY : esp-idf/console/CMakeFiles/__idf_console.dir/requires

esp-idf/console/CMakeFiles/__idf_console.dir/clean:
	cd /home/vsirvent/src/mia/task_test/esp-idf/console && $(CMAKE_COMMAND) -P CMakeFiles/__idf_console.dir/cmake_clean.cmake
.PHONY : esp-idf/console/CMakeFiles/__idf_console.dir/clean

esp-idf/console/CMakeFiles/__idf_console.dir/depend:
	cd /home/vsirvent/src/mia/task_test && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vsirvent/src/mia/task_test /home/vsirvent/src/esp-idf/components/console /home/vsirvent/src/mia/task_test /home/vsirvent/src/mia/task_test/esp-idf/console /home/vsirvent/src/mia/task_test/esp-idf/console/CMakeFiles/__idf_console.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : esp-idf/console/CMakeFiles/__idf_console.dir/depend

