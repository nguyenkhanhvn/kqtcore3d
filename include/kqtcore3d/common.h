#ifndef COMMON_H
#define COMMON_H


#include <QVector3D>
#include <QVector4D>
#include <QMatrix4x4>
#include <QOpenGLFunctions>

namespace kqtcore3d
{

// unknow attribLocation -> set to <
struct ShaderLayout {
    int attribLocation = -1;
    const char* name;
    GLenum type;
    int offset;
    int tupleSize;
};

enum RendererApi
{
    OpenGL = 0,
    Unknown,
};

enum CameraControl
{
    Move_Forward = 0,
    Move_Backward,
    Move_Left,
    Move_Right,
    Move_Up,
    Move_Down,
    Rotate_Up_Down,
    Rotate_Left_Right,
};

}

#endif // COMMON_H
