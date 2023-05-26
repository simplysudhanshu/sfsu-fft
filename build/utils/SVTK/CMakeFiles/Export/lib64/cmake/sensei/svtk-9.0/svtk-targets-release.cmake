#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "SVTK::svtksys" for configuration "Release"
set_property(TARGET SVTK::svtksys APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(SVTK::svtksys PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C;CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib64/libsvtksys-9.0.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS SVTK::svtksys )
list(APPEND _IMPORT_CHECK_FILES_FOR_SVTK::svtksys "${_IMPORT_PREFIX}/lib64/libsvtksys-9.0.a" )

# Import target "SVTK::CommonCore" for configuration "Release"
set_property(TARGET SVTK::CommonCore APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(SVTK::CommonCore PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib64/libsvtkCommonCore-9.0.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS SVTK::CommonCore )
list(APPEND _IMPORT_CHECK_FILES_FOR_SVTK::CommonCore "${_IMPORT_PREFIX}/lib64/libsvtkCommonCore-9.0.a" )

# Import target "SVTK::CommonMath" for configuration "Release"
set_property(TARGET SVTK::CommonMath APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(SVTK::CommonMath PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib64/libsvtkCommonMath-9.0.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS SVTK::CommonMath )
list(APPEND _IMPORT_CHECK_FILES_FOR_SVTK::CommonMath "${_IMPORT_PREFIX}/lib64/libsvtkCommonMath-9.0.a" )

# Import target "SVTK::CommonTransforms" for configuration "Release"
set_property(TARGET SVTK::CommonTransforms APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(SVTK::CommonTransforms PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib64/libsvtkCommonTransforms-9.0.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS SVTK::CommonTransforms )
list(APPEND _IMPORT_CHECK_FILES_FOR_SVTK::CommonTransforms "${_IMPORT_PREFIX}/lib64/libsvtkCommonTransforms-9.0.a" )

# Import target "SVTK::CommonMisc" for configuration "Release"
set_property(TARGET SVTK::CommonMisc APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(SVTK::CommonMisc PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib64/libsvtkCommonMisc-9.0.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS SVTK::CommonMisc )
list(APPEND _IMPORT_CHECK_FILES_FOR_SVTK::CommonMisc "${_IMPORT_PREFIX}/lib64/libsvtkCommonMisc-9.0.a" )

# Import target "SVTK::CommonSystem" for configuration "Release"
set_property(TARGET SVTK::CommonSystem APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(SVTK::CommonSystem PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib64/libsvtkCommonSystem-9.0.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS SVTK::CommonSystem )
list(APPEND _IMPORT_CHECK_FILES_FOR_SVTK::CommonSystem "${_IMPORT_PREFIX}/lib64/libsvtkCommonSystem-9.0.a" )

# Import target "SVTK::CommonDataModel" for configuration "Release"
set_property(TARGET SVTK::CommonDataModel APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(SVTK::CommonDataModel PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib64/libsvtkCommonDataModel-9.0.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS SVTK::CommonDataModel )
list(APPEND _IMPORT_CHECK_FILES_FOR_SVTK::CommonDataModel "${_IMPORT_PREFIX}/lib64/libsvtkCommonDataModel-9.0.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
