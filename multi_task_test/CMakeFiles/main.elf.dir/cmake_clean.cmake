file(REMOVE_RECURSE
  "config/sdkconfig.h"
  "config/sdkconfig.cmake"
  "bootloader/bootloader.elf"
  "bootloader/bootloader.bin"
  "bootloader/bootloader.map"
  "main.bin"
  "flash_project_args"
  "main.map"
  "project_elf_src_esp32.c"
  "project_elf_src_esp32.c"
  "CMakeFiles/main.elf.dir/project_elf_src_esp32.c.obj"
  "main.elf.pdb"
  "main.elf"
)

# Per-language clean rules from dependency scanning.
foreach(lang C)
  include(CMakeFiles/main.elf.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
