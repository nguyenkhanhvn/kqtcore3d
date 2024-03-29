cmake_minimum_required(VERSION 3.14)

project(kqtcore3d LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    message("debug mode")
#    add_definitions(-DRENDER_LOG)
elseif (CMAKE_BUILD_TYPE STREQUAL "Release" OR CMAKE_BUILD_TYPE STREQUAL "MinSizeRel")
    message("release mode")
    add_definitions(-DQT_NO_DEBUG_OUTPUT)
endif()

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick OpenGL)

file(GLOB_RECURSE  HEADER_FILES "include/*.h")
file(GLOB_RECURSE  SOURCE_FILES "src/*.cpp")
add_library(kqtcore3d STATIC
    ${HEADER_FILES}
    ${SOURCE_FILES}
)


include_directories(include)

target_include_directories(kqtcore3d PRIVATE include/kqtcore3d include/kqtcore3d/core include/kqtcore3d/interfaces include/kqtcore3d/components)

target_link_libraries(kqtcore3d
    PRIVATE
    Qt6::Quick
    Qt6::OpenGL
)
