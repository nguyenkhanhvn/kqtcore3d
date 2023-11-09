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
qt_add_library(kqtcore3d STATIC
    ${HEADER_FILES}
    ${SOURCE_FILES}
    include/kqtcore3d/kqtcore3d.h src/kqtcore3d.cpp
    include/kqtcore3d/common.h
    include/kqtcore3d/core/core.h
    include/kqtcore3d/core/basecamera.h src/core/basecamera.cpp
    include/kqtcore3d/core/basemesh.h src/core/basemesh.cpp
    include/kqtcore3d/core/basemodel.h src/core/basemodel.cpp
    include/kqtcore3d/core/baseshaderprogram.h src/core/baseshaderprogram.cpp
    include/kqtcore3d/core/shaderprogramlayout.h src/core/shaderprogramlayout.cpp
    include/kqtcore3d/interfaces/interfaces.h
    include/kqtcore3d/interfaces/imodelimporter.h
    include/kqtcore3d/interfaces/irenderable.h
    include/kqtcore3d/interfaces/irendercallback.h
    include/kqtcore3d/interfaces/ivertices.h
    include/kqtcore3d/interfaces/iindices.h
    include/kqtcore3d/components/components.h
    include/kqtcore3d/components/orthocamera.h src/components/orthocamera.cpp
    include/kqtcore3d/components/perspectivecamera.h src/components/perspectivecamera.cpp
    include/kqtcore3d/components/mesh.h src/components/mesh.cpp
    include/kqtcore3d/components/model.h src/components/model.cpp
    include/kqtcore3d/components/shaderprogram.h src/components/shaderprogram.cpp
    include/kqtcore3d/components/indices.h src/components/indices.cpp
    include/kqtcore3d/components/vertices.h src/components/vertices.cpp
    include/kqtcore3d/components/opengl/openglmesh.h src/components/opengl/openglmodel.cpp
    include/kqtcore3d/components/opengl/openglmodel.h src/components/opengl/openglmodel.cpp
    include/kqtcore3d/components/opengl/openglshaderprogram.h src/components/opengl/openglshaderprogram.cpp
)

include_directories(include)

target_include_directories(kqtcore3d PRIVATE include/kqtcore3d include/kqtcore3d/core include/kqtcore3d/interfaces include/kqtcore3d/components)

target_link_libraries(kqtcore3d
    PRIVATE
    Qt6::Quick
    Qt6::OpenGL
)

target_compile_definitions(kqtcore3d PRIVATE KQTCORE3D_LIBRARY)
