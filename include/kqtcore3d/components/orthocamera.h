#ifndef ORTHOCAMERA_H
#define ORTHOCAMERA_H

#include "kqtcore3d/core/basecamera.h"

namespace kqtcore3d {

class OrthoCamera : public BaseCamera
{
public:
    OrthoCamera(QVector3D position, float left, float right, float bottom, float top, QVector3D orientation, QVector3D up,
                      float nearPlane, float farPlane, QMatrix4x4 projection);

    virtual void setupOrtho(float left, float right, float bottom, float top, float nearPlane, float farPlane, QMatrix4x4 projection = QMatrix4x4());

protected:
    float m_left, m_right, m_bottom, m_top, m_nearPlane, m_farPlane;
};

}

#endif // ORTHOCAMERA_H
