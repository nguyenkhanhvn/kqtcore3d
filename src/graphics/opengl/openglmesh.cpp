#include "openglmesh.h"

using namespace kqtcore3d;

OpenGLMesh::OpenGLMesh(const QVector<Vertex>& vertices, const QVector<unsigned int>& indices, QMatrix4x4 modelMatrix) :
    Mesh(vertices, indices, modelMatrix)
{}
