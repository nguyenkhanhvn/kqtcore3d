#include "orthocamera.h"

namespace kqtcore3d
{

OrthoCamera::OrthoCamera(QVector3D position, float left, float right, float bottom, float top, QVector3D orientation, QVector3D up, float nearPlane, float farPlane, QMatrix4x4 projection) :
    BaseCamera(position, orientation, up, projection), m_left(left), m_right(right), m_bottom(bottom), m_top(top), m_nearPlane(nearPlane), m_farPlane(farPlane)
{
#ifdef RENDER_LOG
    LOG << "position: " << position << ", orientation: " << orientation << ", up: " << up << projection << projection;
    LOG << "left: " << left << ", right: " << right << ", bottom: " << bottom << ", top: " << top << ", nearPlane: " << nearPlane << ", farPlane: " << farPlane;
#endif
    m_projection.ortho(left, right, bottom, top, nearPlane, farPlane);
    calculateCameraMatrix();
}

void OrthoCamera::setupOrtho(float left, float right, float bottom, float top, float nearPlane, float farPlane, QMatrix4x4 projection)
{
    LOG << "left: " << left << ", right: " << right << ", bottom: " << bottom << ", top: " << top << ", nearPlane: " << nearPlane << ", farPlane: " << farPlane << projection << projection;
    m_left = left; m_right = right; m_bottom = bottom; m_top = top; m_nearPlane = nearPlane; m_farPlane = farPlane;
    m_projection = projection;
    m_projection.ortho(left, right, bottom, top, nearPlane, farPlane);
    calculateCameraMatrix();
}

}
