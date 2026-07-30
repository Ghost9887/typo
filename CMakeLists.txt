cmake_minimum_required(VERSION 3.10)
project(typo)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

add_subdirectory(${CMAKE_SOURCE_DIR}/external/mead)

file(GLOB_RECURSE APP_SOURCES
    ${CMAKE_SOURCE_DIR}/src/*.cc
)

add_executable(typo ${APP_SOURCES})

target_include_directories(typo
    PRIVATE
        ${CMAKE_SOURCE_DIR}/src
)

target_compile_options(typo PRIVATE -Wall -Wextra -Wpedantic)

target_link_libraries(typo PRIVATE mead)
