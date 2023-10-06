#include "mesh.h"

#include "kqtcore3d.h"
#include "opengl/openglmesh.h"

namespace kqtcore3d
{

QSharedPointer<Mesh> Mesh::create(const QSharedPointer<IVertices> &vertices, const QSharedPointer<IIndices> &indices, QMatrix4x4 meshMatrix)
{
    switch(getRendererApi())
    {
    case OpenGL:
        return QSharedPointer<OpenGLMesh>::create(vertices, indices, meshMatrix);
        break;
    case Unknown:
        break;
    }
    return nullptr;
}

Mesh::Mesh(const QSharedPointer<IVertices> &vertices, const QSharedPointer<IIndices> &indices, QMatrix4x4 meshMatrix) :
    BaseMesh(vertices, indices, meshMatrix)
{}

}
