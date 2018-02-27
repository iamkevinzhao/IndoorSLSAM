add_executable(IndoorSLSAM_test test.cpp)

target_link_libraries(IndoorSLSAM_test IndoorSLSAM)

install(TARGETS IndoorSLSAM_test
  # IMPORTANT: Add the IndoorSLSAM_test executable to the "export-set"
  EXPORT IndoorSLSAMTargets
  RUNTIME DESTINATION "${INSTALL_BIN_DIR}" COMPONENT bin)
