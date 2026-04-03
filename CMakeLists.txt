cmake_minimum_required(VERSION 3.25.2)

project(dbscan VERSION 1.0.0 LANGUAGES CXX)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

add_library(dbscan SHARED
    dbscan.cpp
)

# Export all public symbols automatically on Windows.
set_target_properties(dbscan PROPERTIES
    WINDOWS_EXPORT_ALL_SYMBOLS ON
)

target_include_directories(dbscan
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
    PRIVATE
        vendor
)

# Optional but nice to have if consumers link dbscan::dbscan
add_library(dbscan::dbscan ALIAS dbscan)

# ---- install library + headers ----

install(
    TARGETS dbscan
    EXPORT dbscanTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}      # .so / .dylib
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}      # .a / import libs
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}      # .dll
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(
    DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# ---- install exported targets ----

install(
    EXPORT dbscanTargets
    FILE dbscanTargets.cmake
    NAMESPACE dbscan::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/dbscan
)

# ---- generate package config + version files ----

configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/dbscanConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/dbscanConfig.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/dbscan
)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/dbscanConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

install(
    FILES
        ${CMAKE_CURRENT_BINARY_DIR}/dbscanConfig.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/dbscanConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/dbscan
)
