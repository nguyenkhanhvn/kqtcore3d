#ifndef COMMON_H
#define COMMON_H


#include <QVector3D>
#include <QVector4D>
#include <QMatrix4x4>

namespace kqtcore3d
{

struct Vertex
{
    QVector3D position;
    QVector4D color;
};

enum GraphicApi
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
