#ifndef OPENGLMESH_H
#define OPENGLMESH_H


#include "mesh.h"

namespace kqtcore3d {

class OpenGLMesh : public Mesh
{
public:
    OpenGLMesh(const QVector<Vertex>& vertices, const QVector<unsigned int>& indices, QMatrix4x4 modelMatrix = QMatrix4x4());
};

}

#endif // OPENGLMESH_H
