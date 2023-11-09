#include "basemesh.h"

namespace kqtcore3d
{

BaseMesh::BaseMesh(const QSharedPointer<IVertices> &vertices, const QSharedPointer<IIndices> &indices, QMatrix4x4 meshMatrix) :
    m_vertices(vertices), m_indices(indices), m_meshMatrix(meshMatrix)
{}

BaseMesh::~BaseMesh() {}

QSharedPointer<IVertices> BaseMesh::vertices() const
{
    return m_vertices;
}

void BaseMesh::swapVertices(QSharedPointer<IVertices> newVertices)
{
    m_vertices.swap(newVertices);
}

QSharedPointer<IIndices> BaseMesh::indices() const
{
    return m_indices;
}

void BaseMesh::swapIndices(QSharedPointer<IIndices> newIndices)
{
    m_indices.swap(newIndices);
}

QMatrix4x4 BaseMesh::getMeshMatrix() const
{
    return m_meshMatrix;
}

void BaseMesh::setMeshMatrix(QMatrix4x4 newMeshMatrix)
{
    if(m_meshMatrix == newMeshMatrix) return;
    m_meshMatrix = newMeshMatrix;
}

void BaseMesh::translate(const QVector3D &vector)
{
    m_meshMatrix.translate(vector);
}

void BaseMesh::translate(float x, float y)
{
    m_meshMatrix.translate(x, y);
}

void BaseMesh::translate(float x, float y, float z)
{
    m_meshMatrix.translate(x, y, z);
}

void BaseMesh::rotate(float angle, const QVector3D &rotateAxis)
{
    m_meshMatrix.rotate(angle, rotateAxis);
}

void BaseMesh::rotate(float angle, float x, float y, float z)
{
    m_meshMatrix.rotate(angle, x, y, z);
}

void BaseMesh::rotate(const QQuaternion &quaternion)
{
    m_meshMatrix.rotate(quaternion);
}

void BaseMesh::rotateGlobal(float angle, const QVector3D &rotateAxis)
{
    QMatrix4x4 globalRotation;
    globalRotation.rotate(angle, rotateAxis);
    m_meshMatrix = globalRotation * m_meshMatrix;
}

void BaseMesh::scale(const QVector3D &vector)
{
    m_meshMatrix.scale(vector);
}

void BaseMesh::scale(float x, float y)
{
    m_meshMatrix.scale(x, y);
}

void BaseMesh::scale(float x, float y, float z)
{
    m_meshMatrix.scale(x, y, z);
}

void BaseMesh::scale(float factor)
{
    m_meshMatrix.scale(factor);
}

}
