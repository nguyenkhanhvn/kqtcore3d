#ifndef BASEMESH_H
#define BASEMESH_H


#include <QMatrix4x4>

#include "kqtcore3d/interfaces/irenderable.h"
#include "kqtcore3d/interfaces/ivertices.h"

namespace kqtcore3d
{

template<typename I>
class BaseMesh : public IRenderable
{
public:
    BaseMesh(const QSharedPointer<IVertices>& vertices, const QVector<I>& indices, QMatrix4x4 meshMatrix) :
        m_vertices(vertices), m_indices(indices), m_meshMatrix(meshMatrix)
    {}

    virtual ~BaseMesh() {}

    virtual QSharedPointer<IVertices> vertices() const
    {
        return m_vertices;
    }
    virtual QVector<I> indices() const
    {
        return m_indices;
    }
    virtual QMatrix4x4 getMeshMatrix() const
    {
        return m_meshMatrix;
    }


protected:
    QSharedPointer<IVertices> m_vertices;
    QVector<I> m_indices;

    QMatrix4x4 m_meshMatrix;
};

}

#endif // BASEMESH_H
