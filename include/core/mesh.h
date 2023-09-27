#ifndef MESH_H
#define MESH_H


#include <QMatrix4x4>

#include "interfaces/irenderable.h"
#include "interfaces/ivertices.h"

namespace kqtcore3d
{

template<typename I>
class Mesh : public IRenderable
{
public:
    Mesh(const QSharedPointer<IVertices>& vertices, const QVector<I>& indices, QMatrix4x4 modelMatrix = QMatrix4x4()) :
        m_vertices(vertices), m_indices(indices), m_modelMatrix(modelMatrix)
    {}

    virtual ~Mesh() {}

    virtual QSharedPointer<IVertices> vertices() const
    {
        return m_vertices;
    }
    virtual QVector<I> indices() const
    {
        return m_indices;
    }
    virtual QMatrix4x4 getModelMatrix() const
    {
        return m_modelMatrix;
    }


protected:
    QSharedPointer<IVertices> m_vertices;
    QVector<I> m_indices;

    QMatrix4x4 m_modelMatrix;
};

}

#endif // MESH_H
