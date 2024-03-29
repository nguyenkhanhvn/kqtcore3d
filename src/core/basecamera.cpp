#include "basecamera.h"

#include "kqtcore3dutils.h"

namespace kqtcore3d
{

BaseCamera::BaseCamera(QVector3D position, QVector3D orientation, QVector3D up, QMatrix4x4 projection) :
    m_position(position), m_orientation(orientation), m_up(up), m_projection(projection)
{
    calculateCameraMatrix();
}

void BaseCamera::cameraControl(CameraControl cameraControl, float delta)
{
    LOG << cameraControl << ": " << delta;
    switch(cameraControl)
    {
    case Move_Forward:
        m_position += m_speed * delta * m_orientation;
        break;
    case Move_Backward:
        m_position -= m_speed * delta * m_orientation;
        break;
    case Move_Left:
        m_position += m_speed * delta * QVector3D::crossProduct(m_up, m_orientation);
        break;
    case Move_Right:
        m_position += m_speed * delta * QVector3D::crossProduct(m_orientation, m_up);
        break;
    case Move_Up:
        m_position += m_speed * delta * m_up;
        break;
    case Move_Down:
        m_position -= m_speed * delta * m_up;
        break;
    case Rotate_Up_Down:
    {
        QQuaternion rotation = QQuaternion::fromAxisAndAngle(QVector3D::crossProduct(m_orientation, m_up), delta * m_sensitivity);
        m_orientation = rotation.rotatedVector(m_orientation);
        break;
    }
    case Rotate_Left_Right:
    {
        QQuaternion rotation = QQuaternion::fromAxisAndAngle(m_up, delta * m_sensitivity);
        m_orientation = rotation.rotatedVector(m_orientation);
        break;
    }
    }

    calculateCameraMatrix();
}

QMatrix4x4 BaseCamera::getCameraView() const
{
    return m_view;
}

QMatrix4x4 BaseCamera::getCameraProjection() const
{
    return m_projection;
}

QMatrix4x4 BaseCamera::getCameraMatrix() const
{
    return m_cameraMatrix;
}

void BaseCamera::setPosition(const QVector3D &position)
{
    if(m_position == position) return;
    m_position = position;
    calculateCameraMatrix();
}

QVector3D BaseCamera::getPosition() const
{
    return m_position;
}

void BaseCamera::setOrientation(const QVector3D &orientation)
{
    if(m_orientation == orientation) return;
    m_orientation = orientation;
    calculateCameraMatrix();
}

QVector3D BaseCamera::getOrientation() const
{
    return m_orientation;
}

void BaseCamera::setUp(const QVector3D &up)
{
    if(m_up == up) return;
    m_up = up;
    calculateCameraMatrix();
}

QVector3D BaseCamera::getUp() const
{
    return m_up;
}

void BaseCamera::calculateCameraMatrix()
{
    m_view = QMatrix4x4();
    m_view.lookAt(m_position, m_position + m_orientation, m_up);

    m_cameraMatrix = m_projection * m_view;
}

}
