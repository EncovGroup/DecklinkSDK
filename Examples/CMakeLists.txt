cmake_minimum_required(VERSION 3.7.2)

project(DeckLinkExamples LANGUAGES C CXX VERSION 10.5)

option(BUILD_SHARED_LIBS "Build shared libraries" ON)

find_package(Threads REQUIRED)
find_package(DeckLink 10.5 CONFIG REQUIRED)

if(APPLE)
    set(PLATFORM_SOURCES Mac/platform.cpp)
    set(PLATFORM_HEADERS Mac/platform.h)
elseif(UNIX)
    set(PLATFORM_SOURCES Linux/platform.cpp)
    set(PLATFORM_HEADERS Linux/platform.h)
else()
    message(FATAL_ERROR "This building system only support linux or mac osx")
endif()

add_library(platform ${PLATFORM_SOURCES} ${PLATFORM_HEADERS})
if(APPLE)
    set(platformInclude "${PROJECT_SOURCE_DIR}/Mac")
else()
    set(platformInclude "${PROJECT_SOURCE_DIR}/Linux")
endif()

target_include_directories(platform PUBLIC
        $<BUILD_INTERFACE:${platformInclude}>
        $<INSTALL_INTERFACE:include/>)

target_link_libraries(platform PUBLIC Threads::Threads DeckLink::DeckLink)

add_executable(AutomaticModeDetection AutomaticModeDetection.cpp)
target_link_libraries(AutomaticModeDetection PUBLIC platform)

add_executable(DeviceNotification DeviceNotification.cpp)
target_link_libraries(DeviceNotification PUBLIC platform)

add_executable(VancOutput VancOutput.cpp)
target_link_libraries(VancOutput PUBLIC platform)

add_executable(RP188VitcOutput RP188VitcOutput.cpp)
target_link_libraries(RP188VitcOutput PUBLIC platform)
