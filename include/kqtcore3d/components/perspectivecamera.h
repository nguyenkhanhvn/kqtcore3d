#ifndef PERSPECTIVECAMERA_H
#define PERSPECTIVECAMERA_H


#include "kqtcore3d/core/basecamera.h"

namespace kqtcore3d {

class PerspectiveCamera : public BaseCamera
{
public:
    PerspectiveCamera(QVector3D position, float verticalAngle, float aspectRatio, QVector3D orientation, QVector3D up,
                      float nearPlane, float farPlane, QMatrix4x4 projection);

    virtual void setupPerspective(float verticalAngle, float aspectRatio, float nearPlane, float farPlane, QMatrix4x4 projection = QMatrix4x4());


protected:
    float m_verticalAngle, m_aspectRatio, m_nearPlane, m_farPlane;
};

}

#endif // PERSPECTIVECAMERA_H
