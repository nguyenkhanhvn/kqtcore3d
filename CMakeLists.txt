cmake_minimum_required(VERSION 3.14)

project(kqtcore3d LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick OpenGL)

file(GLOB_RECURSE  HEADER_FILES "include/*.h")
file(GLOB_RECURSE  SOURCE_FILES "src/*.cpp")
add_library(kqtcore3d STATIC
    ${HEADER_FILES}
    ${SOURCE_FILES}
    include/interfaces/IDrawable.h
)

include_directories(include include/core include/graphics)
target_include_directories(kqtcore3d PRIVATE include/graphics/opengl)

target_link_libraries(kqtcore3d
    PRIVATE
    Qt6::Quick
    Qt6::OpenGL
)

target_compile_definitions(kqtcore3d PRIVATE KQTCORE3D_LIBRARY)
