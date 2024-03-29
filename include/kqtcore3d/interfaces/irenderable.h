#ifndef IRENDERABLE_H
#define IRENDERABLE_H


#include <QSharedPointer>

#include "kqtcore3d/callbacks/rendercallback.h"

namespace kqtcore3d
{

class IRenderable
{
public:
    // initialize before render
    virtual bool init(RenderCallback callback = {}) = 0;
    virtual void render(RenderCallback callback = {}) {}

    virtual void translate(const QVector3D &vector) {}
    virtual void translate(float x, float y) {}
    virtual void translate(float x, float y, float z) {}
    virtual void rotate(float angle, float x, float y, float z = 0) {}
    virtual void rotate(const QQuaternion &quaternion) {}
    virtual void rotate(const QVector3D &rotateAxis, float angle) {}
    virtual void rotateGlobal(const QVector3D &rotateAxis, float angle, const QVector3D &rotatePoint) {}
    virtual void scale(const QVector3D &vector) {}
    virtual void scale(float x, float y) {}
    virtual void scale(float x, float y, float z) {}
    virtual void scale(float factor) {}

};

}

#endif // IRENDERABLE_H
