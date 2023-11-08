#include "vertices.h"

namespace kqtcore3d {

Vertices::Vertices(const QVector<Vertex> &vertices) : m_vertices(vertices)
{
}

const void *Vertices::getData()
{
    return m_vertices.constData();
}

int Vertices::getSize()
{
    return m_vertices.size();
}

int Vertices::getByteSize()
{
    return m_vertices.size() * sizeof(Vertex);
}

int Vertices::getStride()
{
    return sizeof(Vertex);
}

void Vertices::push(const Vertex &vertex)
{
    m_vertices.push_back(vertex);
}

}
