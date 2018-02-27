cmake_minimum_required(VERSION 2.8)
project(IndoorSLSAM CXX)

add_compile_options(-std=c++11)

find_package(PCL REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

set(IndoorSLSAM_MAJOR_VERSION 0)
set(IndoorSLSAM_MINOR_VERSION 1)
set(IndoorSLSAM_PATCH_VERSION 0)
set(IndoorSLSAM_VERSION
  ${IndoorSLSAM_MAJOR_VERSION}.${IndoorSLSAM_MINOR_VERSION}.${IndoorSLSAM_PATCH_VERSION})

# Offer the user the choice of overriding the installation directories
set(INSTALL_LIB_DIR lib CACHE PATH "Installation directory for libraries")
set(INSTALL_BIN_DIR bin CACHE PATH "Installation directory for executables")
set(INSTALL_INCLUDE_DIR include CACHE PATH
  "Installation directory for header files")
if(WIN32 AND NOT CYGWIN)
  set(DEF_INSTALL_CMAKE_DIR CMake)
else()
  set(DEF_INSTALL_CMAKE_DIR lib/CMake/IndoorSLSAM)
endif()
set(INSTALL_CMAKE_DIR ${DEF_INSTALL_CMAKE_DIR} CACHE PATH
  "Installation directory for CMake files")

# Make relative paths absolute (needed later on)
foreach(p LIB BIN INCLUDE CMAKE)
  set(var INSTALL_${p}_DIR)
  if(NOT IS_ABSOLUTE "${${var}}")
    set(${var} "${CMAKE_INSTALL_PREFIX}/${${var}}")
  endif()
endforeach()

# set up include-directories
include_directories(
  "${PROJECT_SOURCE_DIR}"   # to find IndoorSLSAM/IndoorSLSAM.h
  "${PROJECT_BINARY_DIR}")  # to find IndoorSLSAM/config.h

# Add sub-directories
add_subdirectory(IndoorSLSAM)
add_subdirectory(IndoorSLSAM_test)

# The interesting stuff goes here
# ===============================

# Add all targets to the build-tree export set
export(TARGETS IndoorSLSAM IndoorSLSAM_test
  FILE "${PROJECT_BINARY_DIR}/IndoorSLSAMTargets.cmake")

# Export the package for use from the build-tree
# (this registers the build-tree with a global CMake-registry)
export(PACKAGE IndoorSLSAM)

# Create the IndoorSLSAMConfig.cmake and IndoorSLSAMConfigVersion files
file(RELATIVE_PATH REL_INCLUDE_DIR "${INSTALL_CMAKE_DIR}"
   "${INSTALL_INCLUDE_DIR}")
# ... for the build tree
set(CONF_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}" "${PROJECT_BINARY_DIR}")
configure_file(IndoorSLSAMConfig.cmake.in
  "${PROJECT_BINARY_DIR}/IndoorSLSAMConfig.cmake" @ONLY)
# ... for the install tree
set(CONF_INCLUDE_DIRS "\${IndoorSLSAM_CMAKE_DIR}/${REL_INCLUDE_DIR}")
configure_file(IndoorSLSAMConfig.cmake.in
  "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/IndoorSLSAMConfig.cmake" @ONLY)
# ... for both
configure_file(IndoorSLSAMConfigVersion.cmake.in
  "${PROJECT_BINARY_DIR}/IndoorSLSAMConfigVersion.cmake" @ONLY)

# Install the IndoorSLSAMConfig.cmake and IndoorSLSAMConfigVersion.cmake
install(FILES
  "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/IndoorSLSAMConfig.cmake"
  "${PROJECT_BINARY_DIR}/IndoorSLSAMConfigVersion.cmake"
  DESTINATION "${INSTALL_CMAKE_DIR}" COMPONENT dev)

# Install the export set for use with the install-tree
install(EXPORT IndoorSLSAMTargets DESTINATION
  "${INSTALL_CMAKE_DIR}" COMPONENT dev)
