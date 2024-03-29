#ifndef BASEMESH_H
#define BASEMESH_H


#include <QMatrix4x4>

#include "kqtcore3d/interfaces/irenderable.h"
#include "kqtcore3d/interfaces/ivertices.h"
#include "kqtcore3d/interfaces/iindices.h"

namespace kqtcore3d
{

class BaseMesh : public IRenderable
{
public:
    BaseMesh(const QSharedPointer<IVertices>& vertices, const QSharedPointer<IIndices>& indices, QMatrix4x4 meshMatrix);

    virtual ~BaseMesh();

    virtual QSharedPointer<IVertices> vertices() const;
    virtual void setVertices(const QSharedPointer<IVertices> &newVertices);

    virtual QSharedPointer<IIndices> indices() const;
    virtual void setIndices(const QSharedPointer<IIndices> &newIndices);

    virtual QMatrix4x4 getTransformationMatrix() const;
    virtual void setTransformationMatrix(QMatrix4x4 newTransformationMatrix);

    virtual void translate(const QVector3D &vector) override;
    virtual void translate(float x, float y) override;
    virtual void translate(float x, float y, float z) override;
    virtual void rotate(float angle, float x, float y, float z = 0) override;
    virtual void rotate(const QQuaternion &quaternion) override;
    virtual void rotate(const QVector3D &rotateAxis, float angle) override;
    virtual void rotateGlobal(const QVector3D &rotateAxis, float angle, const QVector3D &rotatePoint = {0,0,0}) override;
    virtual void scale(const QVector3D &vector) override;
    virtual void scale(float x, float y) override;
    virtual void scale(float x, float y, float z) override;
    virtual void scale(float factor) override;


protected:
    QSharedPointer<IVertices> m_vertices = nullptr;
    QSharedPointer<IIndices> m_indices = nullptr;

    QMatrix4x4 m_transformationMatrix;
};

}

#endif // BASEMESH_H
