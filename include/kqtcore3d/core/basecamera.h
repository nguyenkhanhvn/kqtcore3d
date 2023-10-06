#ifndef BASECAMERA_H
#define BASECAMERA_H


#include <QMatrix4x4>

#include "kqtcore3d/common.h"

namespace kqtcore3d
{

class BaseCamera
{
public:
    BaseCamera(QVector3D position, QVector3D orientation, QVector3D up, QMatrix4x4 projection);

    virtual void cameraControl(CameraControl cameraControl, float delta = 1);

    virtual QMatrix4x4 getCameraView() const;
    virtual QMatrix4x4 getCameraProjection() const;
    virtual QMatrix4x4 getCameraMatrix() const;

    void setPosition();
    QVector3D getPosition() const;

    void setOrientation();
    QVector3D getOrientation() const;

    void setUp();
    QVector3D getUp() const;


protected:
    virtual void calculateCameraMatrix();

protected:
    float m_speed = 1.0f;
    float m_sensitivity = 1.0f;

    QVector3D m_position;
    QVector3D m_orientation;
    QVector3D m_up;

    QMatrix4x4 m_projection;
    QMatrix4x4 m_view;
    QMatrix4x4 m_cameraMatrix;

};

}

#endif // BASECAMERA_H
