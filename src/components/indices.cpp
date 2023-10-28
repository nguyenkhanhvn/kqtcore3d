#include "indices.h"

#include <QOpenGLFunctions>


namespace kqtcore3d {

Indices::Indices(const QVector<uint> &indices) :
    m_indices(indices)
{}

const void *Indices::getData()
{
    return m_indices.constData();
}

int Indices::getType()
{
    return GL_UNSIGNED_INT;
}

int Indices::getSize()
{
    return m_indices.size();
}

int Indices::getByteSize()
{
    return m_indices.size() * sizeof(uint);
}

QVector<uint> Indices::getIndices() const
{
    return m_indices;
}

void Indices::setIndices(const QVector<uint> &indices)
{
    if (m_indices != indices)
    {
        m_indices = indices;
    }
}

void Indices::push(uint index)
{
    m_indices.push_back(index);
}

}
