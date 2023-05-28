cmake_minimum_required(VERSION 3.10)
project(c_struct VERSION 0.1)
add_subdirectory(test test)

include(GNUInstallDirs)
add_library(c_struct STATIC src/array.c)

target_include_directories(c_struct
                           PUBLIC
                           "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
                           "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)
install(TARGETS c_struct
        EXPORT c_structTargets
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(FILES include/array.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(EXPORT c_structTargets
        FILE c_structTargets.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/c_struct
)

include(CMakePackageConfigHelpers)

configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/c_structConfig.cmake"
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/c_struct
)

write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/c_structConfigVersion.cmake"
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY AnyNewerVersion
)

install(FILES
          "${CMAKE_CURRENT_BINARY_DIR}/c_structConfig.cmake"
          "${CMAKE_CURRENT_BINARY_DIR}/c_structConfigVersion.cmake"
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/c_struct
)
