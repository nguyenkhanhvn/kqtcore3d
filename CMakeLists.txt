cmake_minimum_required(VERSION 3.14)

project(kqtcore3d LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

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
    include/kqtcore3d/core/basemesh.h
    include/kqtcore3d/core/basemodel.h
    include/kqtcore3d/core/baseshaderprogram.h src/core/baseshaderprogram.cpp
    include/kqtcore3d/interfaces/imodelimporter.h
    include/kqtcore3d/interfaces/irenderable.h
    include/kqtcore3d/interfaces/irendercallback.h
    include/kqtcore3d/interfaces/ivertices.h
    include/kqtcore3d/renderers/renderers.h
    include/kqtcore3d/renderers/orthocamera.h src/renderers/orthocamera.cpp
    include/kqtcore3d/renderers/mesh.h src/renderers/mesh.cpp
    include/kqtcore3d/renderers/model.h src/renderers/model.cpp
    include/kqtcore3d/renderers/shaderprogram.h src/renderers/shaderprogram.cpp
    include/kqtcore3d/renderers/opengl/openglmesh.h src/renderers/opengl/openglmodel.cpp
    include/kqtcore3d/renderers/opengl/openglmodel.h src/renderers/opengl/openglmodel.cpp
    include/kqtcore3d/renderers/perspectivecamera.h src/renderers/perspectivecamera.cpp
    include/kqtcore3d/renderers/opengl/openglshaderprogram.h src/renderers/opengl/openglshaderprogram.cpp
)

include_directories(include)

target_include_directories(kqtcore3d PRIVATE include/kqtcore3d include/kqtcore3d/core include/kqtcore3d/interfaces include/kqtcore3d/renderers)

target_link_libraries(kqtcore3d
    PRIVATE
    Qt6::Quick
    Qt6::OpenGL
)

target_compile_definitions(kqtcore3d PRIVATE KQTCORE3D_LIBRARY)
