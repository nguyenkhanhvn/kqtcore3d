#ifndef CAMERA_H
#define CAMERA_H


#include <QMatrix4x4>

#include "common.h"

namespace kqtcore3d
{

class Camera
{
public:
    Camera(QVector3D position = QVector3D(0, 0, 0), QVector3D orientation = QVector3D(0, 0, -1), QVector3D up = QVector3D(0, 1, 0));

    virtual void inputControl(CameraControl cameraControl, float delta = 1);

    virtual QMatrix4x4 getCameraView() const = 0;
    virtual QMatrix4x4 getCameraMatrix() const;

protected:
    float m_speed = 1.0f;
    float m_sensitivity = 1.0f;

    QVector3D m_position;
    QVector3D m_orientation;
    QVector3D m_up;

    QMatrix4x4 m_proj;
    QMatrix4x4 m_view;

};

}

#endif // CAMERA_H
