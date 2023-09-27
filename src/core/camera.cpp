#include "camera.h"

using namespace kqtcore3d;


Camera::Camera(QVector3D position, QVector3D orientation, QVector3D up) :
    m_position(position), m_orientation(orientation), m_up(up)
{}

void Camera::inputControl(CameraControl cameraControl, float delta)
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
}

QMatrix4x4 Camera::getCameraMatrix() const
{
    return m_proj * getCameraView();
}
