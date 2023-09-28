#ifndef BASECAMERA_H
#define BASECAMERA_H


#include <QMatrix4x4>

#include "kqtcore3d/common.h"

namespace kqtcore3d
{

class BaseCamera
{
public:
    BaseCamera(QVector3D position, QVector3D orientation, QVector3D up, QMatrix4x4 projection, QMatrix4x4 view);

    virtual void cameraControl(CameraControl cameraControl, float delta = 1);

    virtual QMatrix4x4 getCameraView() const = 0;
    virtual QMatrix4x4 getCameraMatrix() const;

protected:
    float m_speed = 1.0f;
    float m_sensitivity = 1.0f;

    QVector3D m_position;
    QVector3D m_orientation;
    QVector3D m_up;

    QMatrix4x4 m_projection;
    QMatrix4x4 m_view;

};

}

#endif // BASECAMERA_H
