#ifndef ORTHOCAMERA_H
#define ORTHOCAMERA_H

#include "kqtcore3d/core/basecamera.h"

namespace kqtcore3d {

class OrthoCamera : public BaseCamera
{
public:
    OrthoCamera(QVector3D position, float left, float right, float bottom, float top, QVector3D orientation, QVector3D up,
                      float nearPlane, float farPlane, QMatrix4x4 projection, QMatrix4x4 view);
    OrthoCamera(QVector3D position, const QRect &rect, QVector3D orientation, QVector3D up, QMatrix4x4 projection, QMatrix4x4 view);
    OrthoCamera(QVector3D position, const QRectF &rect, QVector3D orientation, QVector3D up, QMatrix4x4 projection, QMatrix4x4 view);

    void setupOrtho(float left, float right, float bottom, float top, float nearPlane, float farPlane, QMatrix4x4 projection = QMatrix4x4());
    void setupOrtho(const QRect &rect, QMatrix4x4 projection = QMatrix4x4());
    void setupOrtho(const QRectF &rect, QMatrix4x4 projection = QMatrix4x4());

};

}

#endif // ORTHOCAMERA_H
