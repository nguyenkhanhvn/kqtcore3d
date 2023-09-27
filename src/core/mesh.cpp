#include "mesh.h"

using namespace kqtcore3d;

Mesh::Mesh(const QVector<Vertex> &vertices, const QVector<unsigned int> &indices, QMatrix4x4 modelMatrix) :
    m_vertices(vertices), m_indices(indices), m_modelMatrix(modelMatrix)
{}

QVector<Vertex> Mesh::vertices() const
{
    return m_vertices;
}

QVector<unsigned int> Mesh::indices() const
{
    return m_indices;
}

QMatrix4x4 Mesh::getModelMatrix() const
{
    return m_modelMatrix;
}
