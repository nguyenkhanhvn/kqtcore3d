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
    virtual void swapVertices(QSharedPointer<IVertices> newVertices);

    virtual QSharedPointer<IIndices> indices() const;
    virtual void swapIndices(QSharedPointer<IIndices> newIndices);

    virtual QMatrix4x4 getMeshMatrix() const;
    virtual void setMeshMatrix(QMatrix4x4 newMeshMatrix);

    void translate(const QVector3D &vector);
    void translate(float x, float y);
    void translate(float x, float y, float z);
    void rotate(float angle, const QVector3D &rotateAxis);
    void rotate(float angle, float x, float y, float z = 0);
    void rotate(const QQuaternion &quaternion);
    void rotateGlobal(float angle, const QVector3D &rotateAxis);
    void scale(const QVector3D &vector);
    void scale(float x, float y);
    void scale(float x, float y, float z);
    void scale(float factor);


protected:
    QSharedPointer<IVertices> m_vertices;
    QSharedPointer<IIndices> m_indices;

    QMatrix4x4 m_meshMatrix;
};

}

#endif // BASEMESH_H
