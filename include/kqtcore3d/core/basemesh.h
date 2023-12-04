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

    virtual QMatrix4x4 getMeshMatrix() const;
    virtual void setMeshMatrix(QMatrix4x4 newMeshMatrix);

    virtual void translate(const QVector3D &vector);
    virtual void translate(float x, float y);
    virtual void translate(float x, float y, float z);
    virtual void rotate(float angle, const QVector3D &rotateAxis);
    virtual void rotate(float angle, float x, float y, float z = 0);
    virtual void rotate(const QQuaternion &quaternion);
    virtual void rotateGlobal(float angle, const QVector3D &rotateAxis, const QVector3D &rotatePoint = {0,0,0});
    virtual void scale(const QVector3D &vector);
    virtual void scale(float x, float y);
    virtual void scale(float x, float y, float z);
    virtual void scale(float factor);


protected:
    QSharedPointer<IVertices> m_vertices = nullptr;
    QSharedPointer<IIndices> m_indices = nullptr;

    QMatrix4x4 m_meshMatrix;
};

}

#endif // BASEMESH_H
