#include "orthocamera.h"

namespace kqtcore3d
{

OrthoCamera::OrthoCamera(QVector3D position, float left, float right, float bottom, float top, QVector3D orientation, QVector3D up, float nearPlane, float farPlane, QMatrix4x4 projection, QMatrix4x4 view) :
    BaseCamera(position, orientation, up, projection, view)
{
    m_projection.ortho(left, right, bottom, top, nearPlane, farPlane);
}

OrthoCamera::OrthoCamera(QVector3D position, const QRect &rect, QVector3D orientation, QVector3D up, QMatrix4x4 projection, QMatrix4x4 view) :
    BaseCamera(position, orientation, up, projection, view)
{
    m_projection.ortho(rect);
}

OrthoCamera::OrthoCamera(QVector3D position, const QRectF &rect, QVector3D orientation, QVector3D up, QMatrix4x4 projection, QMatrix4x4 view) :
    BaseCamera(position, orientation, up, projection, view)
{
    m_projection.ortho(rect);
}

void OrthoCamera::setupOrtho(float left, float right, float bottom, float top, float nearPlane, float farPlane, QMatrix4x4 projection)
{
    m_projection = projection;
    m_projection.ortho(left, right, bottom, top, nearPlane, farPlane);
}

void OrthoCamera::setupOrtho(const QRect &rect, QMatrix4x4 projection)
{
    m_projection = projection;
    m_projection.ortho(rect);
}

void OrthoCamera::setupOrtho(const QRectF &rect, QMatrix4x4 projection)
{
    m_projection = projection;
    m_projection.ortho(rect);
}

}
