#include "basecamera.h"

namespace kqtcore3d
{

BaseCamera::BaseCamera(QVector3D position, QVector3D orientation, QVector3D up, QMatrix4x4 projection) :
    m_position(position), m_orientation(orientation), m_up(up), m_projection(projection)
{
    calculateCameraMatrix();
}

void BaseCamera::cameraControl(CameraControl cameraControl, float delta)
{
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

void BaseCamera::calculateCameraMatrix()
{
    QMatrix4x4 view;
    view.lookAt(m_position, m_position + m_orientation, m_up);
    m_view = view;

    m_cameraMatrix = m_projection * m_view;
}

}
