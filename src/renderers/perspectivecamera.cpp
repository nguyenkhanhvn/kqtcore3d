#include "perspectivecamera.h"

namespace kqtcore3d
{

PerspectiveCamera::PerspectiveCamera(QVector3D position, float verticalAngle, float aspectRatio, QVector3D orientation, QVector3D up, float nearPlane, float farPlane, QMatrix4x4 projection, QMatrix4x4 view) :
    BaseCamera(position, orientation, up, projection, view)
{
    m_projection.perspective(verticalAngle, aspectRatio, nearPlane, farPlane);
}

void PerspectiveCamera::setupPerspective(float verticalAngle, float aspectRatio, float nearPlane, float farPlane, QMatrix4x4 projection)
{
    m_projection = projection;
    m_projection.perspective(verticalAngle, aspectRatio, nearPlane, farPlane);
}

}
