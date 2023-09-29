#ifndef BASEMESH_H
#define BASEMESH_H


#include <QMatrix4x4>

#include "kqtcore3d/interfaces/irenderable.h"
#include "kqtcore3d/interfaces/ivertices.h"

namespace kqtcore3d
{

template<typename IndexType>
class BaseMesh : public IRenderable
{
public:
    BaseMesh(const QSharedPointer<IVertices>& vertices, const QVector<IndexType>& indices, QMatrix4x4 meshMatrix) :
        m_vertices(vertices), m_indices(indices), m_meshMatrix(meshMatrix)
    {}

    virtual ~BaseMesh() {}

    virtual QSharedPointer<IVertices> vertices() const
    {
        return m_vertices;
    }
    virtual QVector<IndexType> indices() const
    {
        return m_indices;
    }
    virtual QMatrix4x4 getMeshMatrix() const
    {
        return m_meshMatrix;
    }

    void translate(const QVector3D &vector)
    {
        m_meshMatrix.translate(vector);
    }
    void rotate(float angle, const QVector3D &rotateAxis)
    {
        m_meshMatrix.rotate(angle, rotateAxis);
    }
    void rotateGlobal(float angle, const QVector3D &rotateAxis)
    {
        QMatrix4x4 globalRotation;
        globalRotation.rotate(angle, rotateAxis);
        m_meshMatrix = globalRotation * m_meshMatrix;
    }


protected:
    QSharedPointer<IVertices> m_vertices;
    QVector<IndexType> m_indices;

    QMatrix4x4 m_meshMatrix;
};

}

#endif // BASEMESH_H
