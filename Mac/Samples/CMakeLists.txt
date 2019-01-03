cmake_minimum_required(VERSION 3.7.2)

project(DeckLinkSamples LANGUAGES C CXX VERSION 10.5)

find_package(DeckLink 10.5 CONFIG REQUIRED)

add_executable(BypassControl BypassControl/main.cpp BypassControl/PlaybackHelper.cpp BypassControl/PlaybackHelper.h)
target_link_libraries(BypassControl PUBLIC DeckLink::DeckLink)

add_executable(CaptureFromTape CaptureFromTape/main.cpp CaptureFromTape/capture.cpp CaptureFromTape/capture.h CaptureFromTape/common.h)
target_link_libraries(CaptureFromTape PUBLIC DeckLink::DeckLink)