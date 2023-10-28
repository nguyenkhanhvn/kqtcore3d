#include "perspectivecamera.h"

namespace kqtcore3d
{

PerspectiveCamera::PerspectiveCamera(QVector3D position, float verticalAngle, float aspectRatio, QVector3D orientation, QVector3D up, float nearPlane, float farPlane, QMatrix4x4 projection) :
    BaseCamera(position, orientation, up, projection), m_verticalAngle(verticalAngle), m_aspectRatio(aspectRatio), m_nearPlane(nearPlane), m_farPlane(farPlane)
{
    LOG << "position: " << position << ", orientation: " << orientation << ", up: " << up << projection << projection;
    LOG << "verticalAngle: " << verticalAngle << ", aspectRatio: " << aspectRatio << ", nearPlane: " << nearPlane << ", farPlane: " << farPlane;
    m_projection.perspective(verticalAngle, aspectRatio, nearPlane, farPlane);
    calculateCameraMatrix();
}

void PerspectiveCamera::setupPerspective(float verticalAngle, float aspectRatio, float nearPlane, float farPlane, QMatrix4x4 projection)
{
    LOG << "verticalAngle: " << verticalAngle << ", aspectRatio: " << aspectRatio << ", nearPlane: " << nearPlane << ", farPlane: " << farPlane << projection << projection;
    m_verticalAngle = verticalAngle; m_aspectRatio = aspectRatio; m_nearPlane = nearPlane; m_farPlane = farPlane;
    m_projection = projection;
    m_projection.perspective(verticalAngle, aspectRatio, nearPlane, farPlane);
    calculateCameraMatrix();
}

}
