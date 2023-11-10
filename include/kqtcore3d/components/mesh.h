#ifndef MESH_H
#define MESH_H


#include "kqtcore3d/core/basemesh.h"

namespace kqtcore3d {

class Mesh : public BaseMesh
{
public:
    static QSharedPointer<Mesh> create(const QSharedPointer<IVertices> &vertices = nullptr, const QSharedPointer<IIndices> &indices = nullptr, QMatrix4x4 meshMatrix = QMatrix4x4());

protected:
    Mesh(const QSharedPointer<IVertices> &vertices, const QSharedPointer<IIndices> &indices, QMatrix4x4 meshMatrix);

};

}

#endif // MESH_H
