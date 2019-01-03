cmake_minimum_required(VERSION 3.7.2)

project(DeckLink LANGUAGES C CXX VERSION 10.5)

option(BUILD_SHARED_LIBS "Build shared libraries" ON)


find_package(Threads REQUIRED)

if(APPLE)
    message(STATUS "Building the Mac OSX version")
    include(macosxSources.cmake)
elseif(UNIX)
    message(STATUS "Building the Linux Version")
    include(linuxSources.cmake)
else()
    message(FATAL_ERROR "This building system only support linux or mac osx")
endif()

add_library(DeckLink ${SDK_SOURCES} ${SDK_HEADERS})

if(APPLE)
    set(decklinkInclude "${PROJECT_SOURCE_DIR}/Mac/include")
else()
    set(decklinkInclude "${PROJECT_SOURCE_DIR}/Linux/include")
endif()

target_include_directories(DeckLink PUBLIC
    $<BUILD_INTERFACE:${decklinkInclude}>
    $<INSTALL_INTERFACE:include/>)

target_link_libraries(DeckLink PUBLIC Threads::Threads)

if(APPLE)
    target_link_libraries(DeckLink PUBLIC "-framework CoreFoundation")
else()
    target_link_libraries(DeckLink PRIVATE ${CMAKE_DL_LIBS})
endif()


set_target_properties(DeckLink PROPERTIES PUBLIC_HEADER "${SDK_HEADERS}")

set_target_properties(DeckLink
        PROPERTIES SOVERSION ${PROJECT_VERSION_MAJOR}
        VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}"
        )




## stuff to export and install
include(GNUInstallDirs)

# place to put the cmake-related files
set(config_install_dir "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}")

# build directory containing the generated files
set(generated_dir "${CMAKE_CURRENT_BINARY_DIR}/generated")

# Configuration
set(version_config "${generated_dir}/${PROJECT_NAME}ConfigVersion.cmake")
set(project_config "${generated_dir}/${PROJECT_NAME}Config.cmake")
set(targets_export_name "${PROJECT_NAME}Targets")
set(namespace "${PROJECT_NAME}::")

# Include module with fuction 'write_basic_package_version_file'
include(CMakePackageConfigHelpers)

# Configure '<PROJECT-NAME>ConfigVersion.cmake'
# Note: major version number must be the same as requested
write_basic_package_version_file("${version_config}" COMPATIBILITY SameMajorVersion)

# Configure '<PROJECT-NAME>Config.cmake'
# Use variables:
#   * targets_export_name
#   * PROJECT_NAME
configure_package_config_file("${PROJECT_SOURCE_DIR}/cmake/Config.cmake.in"
        "${project_config}"
        INSTALL_DESTINATION "${config_install_dir}")


export(TARGETS DeckLink FILE "${generated_dir}/${targets_export_name}.cmake")

install(TARGETS DeckLink
        EXPORT ${targets_export_name}
        ARCHIVE
        DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY
        DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME
        DESTINATION ${CMAKE_INSTALL_BINDIR}
        PUBLIC_HEADER
        DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")

# Config
#   * <prefix>/lib/cmake/${PROJECT_NAME}/${PROJECT_NAME}Config.cmake
#   * <prefix>/lib/cmake/${PROJECT_NAME}/${PROJECT_NAME}ConfigVersion.cmake
install(
        FILES "${project_config}" "${version_config}"
        DESTINATION "${config_install_dir}"
)

#   * <prefix>/lib/cmake/${PROJECT_NAME}/${PROJECT_NAME}Targets.cmake
install(EXPORT "${targets_export_name}"
        NAMESPACE "${namespace}"
        DESTINATION "${config_install_dir}")

## Uninstall target
configure_file(
        "${PROJECT_SOURCE_DIR}/cmake/cmake_uninstall.cmake.in"
        "${generated_dir}/cmake_uninstall.cmake"
        IMMEDIATE @ONLY)

add_custom_target(uninstall
        COMMAND ${CMAKE_COMMAND} -P ${generated_dir}/cmake_uninstall.cmake)