file(REMOVE_RECURSE
  "../../ldgen_libraries.in"
  "../../ldgen_libraries"
  "CMakeFiles/__ldgen_output_sections.ld"
  "ld/sections.ld"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/__ldgen_output_sections.ld.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
