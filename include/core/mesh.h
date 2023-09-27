#ifndef MESH_H
#define MESH_H


#include "common.h"

namespace kqtcore3d
{

class Mesh
{
public:
    Mesh(const QVector<Vertex>& vertices, const QVector<unsigned int>& indices, QMatrix4x4 modelMatrix = QMatrix4x4());

    virtual QVector<Vertex> vertices() const;
    virtual QVector<unsigned int> indices() const;
    virtual QMatrix4x4 getModelMatrix() const;


protected:
    QVector<Vertex> m_vertices;
    QVector<unsigned int> m_indices;

    QMatrix4x4 m_modelMatrix;
};

}

#endif // MESH_H
