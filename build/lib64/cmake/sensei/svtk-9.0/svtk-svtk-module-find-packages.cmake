set(_svtk_module_find_package_quiet)
if (${CMAKE_FIND_PACKAGE_NAME}_FIND_QUIETLY)
  set(_svtk_module_find_package_quiet QUIET)
endif ()

set(_svtk_module_find_package_components_checked)
set(_svtk_module_find_package_components_to_check
  ${${CMAKE_FIND_PACKAGE_NAME}_FIND_COMPONENTS})
set(_svtk_module_find_package_components)
set(_svtk_module_find_package_components_required)
while (_svtk_module_find_package_components_to_check)
  list(GET _svtk_module_find_package_components_to_check 0 _svtk_module_component)
  list(REMOVE_AT _svtk_module_find_package_components_to_check 0)
  if (_svtk_module_component IN_LIST _svtk_module_find_package_components_checked)
    continue ()
  endif ()
  list(APPEND _svtk_module_find_package_components_checked
    "${_svtk_module_component}")

  list(APPEND _svtk_module_find_package_components
    "${_svtk_module_component}")
  if (${CMAKE_FIND_PACKAGE_NAME}_FIND_REQUIRED_${_svtk_module_component})
    list(APPEND _svtk_module_find_package_components_required
      "${_svtk_module_component}")
  endif ()

  if (TARGET "${CMAKE_FIND_PACKAGE_NAME}::${_svtk_module_component}")
    set(_svtk_module_find_package_component_target "${CMAKE_FIND_PACKAGE_NAME}::${_svtk_module_component}")
  elseif (TARGET "${_svtk_module_component}")
    set(_svtk_module_find_package_component_target "${_svtk_module_component}")
  else ()
    # No such target for the component; skip.
    continue ()
  endif ()
  get_property(_svtk_module_find_package_depends
    TARGET    "${_svtk_module_find_package_component_target}"
    PROPERTY  "INTERFACE_svtk_module_depends")
  string(REPLACE "${CMAKE_FIND_PACKAGE_NAME}::" "" _svtk_module_find_package_depends "${_svtk_module_find_package_depends}")
  list(APPEND _svtk_module_find_package_components_to_check
    ${_svtk_module_find_package_depends})
  get_property(_svtk_module_find_package_depends
    TARGET    "${_svtk_module_find_package_component_target}"
    PROPERTY  "INTERFACE_svtk_module_private_depends")
  string(REPLACE "${CMAKE_FIND_PACKAGE_NAME}::" "" _svtk_module_find_package_depends "${_svtk_module_find_package_depends}")
  list(APPEND _svtk_module_find_package_components_to_check
    ${_svtk_module_find_package_depends})
  get_property(_svtk_module_find_package_depends
    TARGET    "${_svtk_module_find_package_component_target}"
    PROPERTY  "INTERFACE_svtk_module_optional_depends")
  foreach (_svtk_module_find_package_depend IN LISTS _svtk_module_find_package_depends)
    if (TARGET "${_svtk_module_find_package_depend}")
      string(REPLACE "${CMAKE_FIND_PACKAGE_NAME}::" "" _svtk_module_find_package_depend "${_svtk_module_find_package_depend}")
      list(APPEND _svtk_module_find_package_components_to_check
        "${_svtk_module_find_package_depend}")
    endif ()
  endforeach ()
  get_property(_svtk_module_find_package_depends
    TARGET    "${_svtk_module_find_package_component_target}"
    PROPERTY  "INTERFACE_svtk_module_forward_link")
  string(REPLACE "${CMAKE_FIND_PACKAGE_NAME}::" "" _svtk_module_find_package_depends "${_svtk_module_find_package_depends}")
  list(APPEND _svtk_module_find_package_components_to_check
    ${_svtk_module_find_package_depends})

  get_property(_svtk_module_find_package_kit
    TARGET    "${_svtk_module_find_package_component_target}"
    PROPERTY  "INTERFACE_svtk_module_kit")
  if (_svtk_module_find_package_kit)
    get_property(_svtk_module_find_package_kit_modules
      TARGET    "${_svtk_module_find_package_kit}"
      PROPERTY  "INTERFACE_svtk_kit_kit_modules")
    string(REPLACE "${CMAKE_FIND_PACKAGE_NAME}::" "" _svtk_module_find_package_kit_modules "${_svtk_module_find_package_kit_modules}")
    list(APPEND _svtk_module_find_package_components_to_check
      ${_svtk_module_find_package_kit_modules})
  endif ()
endwhile ()
unset(_svtk_module_find_package_component_target)
unset(_svtk_module_find_package_components_to_check)
unset(_svtk_module_find_package_components_checked)
unset(_svtk_module_component)
unset(_svtk_module_find_package_depend)
unset(_svtk_module_find_package_depends)
unset(_svtk_module_find_package_kit)
unset(_svtk_module_find_package_kit_modules)

if (_svtk_module_find_package_components)
  list(REMOVE_DUPLICATES _svtk_module_find_package_components)
endif ()
if (_svtk_module_find_package_components_required)
  list(REMOVE_DUPLICATES _svtk_module_find_package_components_required)
endif ()

set(_svtk_module_find_package_enabled OFF)
set(_svtk_module_find_package_is_required OFF)
set(_svtk_module_find_package_fail_if_not_found OFF)
if (_svtk_module_find_package_components)
  if ("CommonSystem" IN_LIST _svtk_module_find_package_components)
    set(_svtk_module_find_package_enabled ON)
    if ("CommonSystem" IN_LIST _svtk_module_find_package_components_required)
      set(_svtk_module_find_package_is_required "${${CMAKE_FIND_PACKAGE_NAME}_FIND_REQUIRED}")
      set(_svtk_module_find_package_fail_if_not_found ON)
    endif ()
  endif ()
else ()
  set(_svtk_module_find_package_enabled ON)
  set(_svtk_module_find_package_is_required "${${CMAKE_FIND_PACKAGE_NAME}_FIND_REQUIRED}")
  set(_svtk_module_find_package_fail_if_not_found ON)
endif ()

if (_svtk_module_find_package_enabled)
  set(_svtk_module_find_package_required)
  if (_svtk_module_find_package_is_required)
    set(_svtk_module_find_package_required REQUIRED)
  endif ()

  find_package(Threads
    
    
    
    ${_svtk_module_find_package_quiet}
    ${_svtk_module_find_package_required}
    COMPONENTS          
    OPTIONAL_COMPONENTS )
  if (NOT Threads_FOUND AND _svtk_module_find_package_fail_if_not_found)
    if (NOT ${CMAKE_FIND_PACKAGE_NAME}_FIND_QUIETLY)
      message(STATUS
        "Could not find the ${CMAKE_FIND_PACKAGE_NAME} package due to a "
        "missing dependency: Threads")
    endif ()
    set("${CMAKE_FIND_PACKAGE_NAME}_CommonSystem_FOUND" 0)
    list(APPEND "${CMAKE_FIND_PACKAGE_NAME}_CommonSystem_NOT_FOUND_MESSAGE"
      "Failed to find the Threads package.")
  endif ()
endif ()

unset(_svtk_module_find_package_fail_if_not_found)
unset(_svtk_module_find_package_enabled)
unset(_svtk_module_find_package_required)

set(_svtk_module_find_package_enabled OFF)
set(_svtk_module_find_package_is_required OFF)
set(_svtk_module_find_package_fail_if_not_found OFF)
if (_svtk_module_find_package_components)
  if ("CommonCore" IN_LIST _svtk_module_find_package_components)
    set(_svtk_module_find_package_enabled ON)
    if ("CommonCore" IN_LIST _svtk_module_find_package_components_required)
      set(_svtk_module_find_package_is_required "${${CMAKE_FIND_PACKAGE_NAME}_FIND_REQUIRED}")
      set(_svtk_module_find_package_fail_if_not_found ON)
    endif ()
  endif ()
else ()
  set(_svtk_module_find_package_enabled ON)
  set(_svtk_module_find_package_is_required "${${CMAKE_FIND_PACKAGE_NAME}_FIND_REQUIRED}")
  set(_svtk_module_find_package_fail_if_not_found ON)
endif ()

if (_svtk_module_find_package_enabled)
  set(_svtk_module_find_package_required)
  if (_svtk_module_find_package_is_required)
    set(_svtk_module_find_package_required REQUIRED)
  endif ()

  find_package(Threads
    
    
    
    ${_svtk_module_find_package_quiet}
    ${_svtk_module_find_package_required}
    COMPONENTS          
    OPTIONAL_COMPONENTS )
  if (NOT Threads_FOUND AND _svtk_module_find_package_fail_if_not_found)
    if (NOT ${CMAKE_FIND_PACKAGE_NAME}_FIND_QUIETLY)
      message(STATUS
        "Could not find the ${CMAKE_FIND_PACKAGE_NAME} package due to a "
        "missing dependency: Threads")
    endif ()
    set("${CMAKE_FIND_PACKAGE_NAME}_CommonCore_FOUND" 0)
    list(APPEND "${CMAKE_FIND_PACKAGE_NAME}_CommonCore_NOT_FOUND_MESSAGE"
      "Failed to find the Threads package.")
  endif ()
endif ()

unset(_svtk_module_find_package_fail_if_not_found)
unset(_svtk_module_find_package_enabled)
unset(_svtk_module_find_package_required)

unset(_svtk_module_find_package_components)
unset(_svtk_module_find_package_components_required)
unset(_svtk_module_find_package_quiet)
