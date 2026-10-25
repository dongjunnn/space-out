cmake_minimum_required(VERSION 3.16)
project(SpaceOut CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "" FORCE)
endif()

# Fetch and build raylib from source; nothing to install system-wide.
include(FetchContent)

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG        6.0
    GIT_SHALLOW    TRUE
)
FetchContent_MakeAvailable(raylib)

add_executable(space-out
    main.cpp
    entity/ship.cpp
)
target_link_libraries(space-out PRIVATE raylib)

option(WARNINGS_AS_ERRORS "Treat compiler warnings as errors" OFF)
if(MSVC)
    target_compile_options(space-out PRIVATE /W4 $<$<BOOL:${WARNINGS_AS_ERRORS}>:/WX>)
else()
    target_compile_options(space-out PRIVATE -Wall -Wextra -Wpedantic -Wshadow
        $<$<BOOL:${WARNINGS_AS_ERRORS}>:-Werror>)
endif()
