configure_file(config.h.in "${CMAKE_CURRENT_BINARY_DIR}/config.h" @ONLY)

add_library(
  IndoorSLSAM
    SHARED
      slsam.cpp
      slsam.h
      config.h.in

      # perception
      perception/scan2d.h
      perception/scan2d.cpp
      perception/point_cloud2.h
      perception/point_cloud2.cpp
      perception/scan_processor.h
      perception/scan_processor.cpp

      # mapping
      mapping/map2d.h
      mapping/map2d.cpp
      mapping/map_generator.h
      mapping/map_generator.cpp

      # localization
      localization/odom2d.h
      localization/odom2d.cpp

      # utility
      utility/utilities.h
      utility/utilities.cpp
      utility/time.h
      utility/time.cpp
      utility/transform.h
      utility/transform.cpp
)

target_link_libraries(
  IndoorSLSAM
    ${PCL_LIBRARIES}
)

set(
  PUBLIC_HEADER_FILES
    slsam.h

    # perception
    perception/scan2d.h

    # mapping
    mapping/map2d.h

    # localization
    localization/odom2d.h

    # utility
    utility/time.h
    utility/transform.h
)

set_target_properties(IndoorSLSAM PROPERTIES
  PUBLIC_HEADER "${PUBLIC_HEADER_FILES};${CMAKE_CURRENT_BINARY_DIR}/config.h")

install(TARGETS IndoorSLSAM
  # IMPORTANT: Add the IndoorSLSAM library to the "export-set"
  EXPORT IndoorSLSAMTargets
  RUNTIME DESTINATION "${INSTALL_BIN_DIR}" COMPONENT bin
  LIBRARY DESTINATION "${INSTALL_LIB_DIR}" COMPONENT shlib
  PUBLIC_HEADER DESTINATION "${INSTALL_INCLUDE_DIR}/IndoorSLSAM"
    COMPONENT dev)
