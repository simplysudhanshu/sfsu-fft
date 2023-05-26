#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "senseiCore" for configuration "Release"
set_property(TARGET senseiCore APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(senseiCore PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib64/libsenseiCore.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS senseiCore )
list(APPEND _IMPORT_CHECK_FILES_FOR_senseiCore "${_IMPORT_PREFIX}/lib64/libsenseiCore.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
