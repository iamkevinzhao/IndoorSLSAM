configure_file(config.h.in "${CMAKE_CURRENT_BINARY_DIR}/config.h" @ONLY)

add_library(IndoorSLSAM SHARED slsam.cpp slsam.h config.h.in)

set_target_properties(IndoorSLSAM PROPERTIES
  PUBLIC_HEADER "slsam.h;${CMAKE_CURRENT_BINARY_DIR}/config.h")

install(TARGETS IndoorSLSAM
  # IMPORTANT: Add the IndoorSLSAM library to the "export-set"
  EXPORT IndoorSLSAMTargets
  RUNTIME DESTINATION "${INSTALL_BIN_DIR}" COMPONENT bin
  LIBRARY DESTINATION "${INSTALL_LIB_DIR}" COMPONENT shlib
  PUBLIC_HEADER DESTINATION "${INSTALL_INCLUDE_DIR}/IndoorSLSAM"
    COMPONENT dev)
