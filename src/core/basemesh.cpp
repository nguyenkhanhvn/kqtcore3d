#include "basemesh.h"

namespace kqtcore3d
{

BaseMesh::BaseMesh(const QSharedPointer<IVertices> &vertices, const QSharedPointer<IIndices> &indices, QMatrix4x4 meshMatrix) :
    m_vertices(vertices), m_indices(indices), m_transformationMatrix(meshMatrix)
{}

BaseMesh::~BaseMesh() {}

QSharedPointer<IVertices> BaseMesh::vertices() const
{
    return m_vertices;
}

void BaseMesh::setVertices(const QSharedPointer<IVertices> &newVertices)
{
    m_vertices = newVertices;
}

QSharedPointer<IIndices> BaseMesh::indices() const
{
    return m_indices;
}

void BaseMesh::setIndices(const QSharedPointer<IIndices> &newIndices)
{
    m_indices = newIndices;
}

QMatrix4x4 BaseMesh::getTransformationMatrix() const
{
    return m_transformationMatrix;
}

void BaseMesh::setTransformationMatrix(QMatrix4x4 newTransformationMatrix)
{
    if(m_transformationMatrix == newTransformationMatrix) return;
    m_transformationMatrix = newTransformationMatrix;
}

void BaseMesh::translate(const QVector3D &vector)
{
    m_transformationMatrix.translate(vector);
}

void BaseMesh::translate(float x, float y)
{
    m_transformationMatrix.translate(x, y);
}

void BaseMesh::translate(float x, float y, float z)
{
    m_transformationMatrix.translate(x, y, z);
}

void BaseMesh::rotate(float angle, float x, float y, float z)
{
    m_transformationMatrix.rotate(angle, x, y, z);
}

void BaseMesh::rotate(const QQuaternion &quaternion)
{
    m_transformationMatrix.rotate(quaternion);
}

void BaseMesh::rotate(const QVector3D &rotateAxis, float angle)
{
    m_transformationMatrix.rotate(angle, rotateAxis);
}

void BaseMesh::rotateGlobal(const QVector3D &rotateAxis, float angle, const QVector3D &rotatePoint)
{
    QMatrix4x4 beforeRotation;
    beforeRotation.translate(-rotatePoint);
    QMatrix4x4 globalRotation;
    globalRotation.rotate(angle, rotateAxis);
    QMatrix4x4 afterRotation;
    afterRotation.translate(rotatePoint);
    m_transformationMatrix = beforeRotation * globalRotation * afterRotation * m_transformationMatrix;
}

void BaseMesh::scale(const QVector3D &vector)
{
    m_transformationMatrix.scale(vector);
}

void BaseMesh::scale(float x, float y)
{
    m_transformationMatrix.scale(x, y);
}

void BaseMesh::scale(float x, float y, float z)
{
    m_transformationMatrix.scale(x, y, z);
}

void BaseMesh::scale(float factor)
{
    m_transformationMatrix.scale(factor);
}

}
