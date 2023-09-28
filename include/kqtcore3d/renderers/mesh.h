#ifndef MESH_H
#define MESH_H


#include "kqtcore3d/core/basemesh.h"

namespace kqtcore3d {

class Mesh : public BaseMesh<uint>
{
protected:
    Mesh(const QSharedPointer<IVertices> &vertices, const QVector<uint> &indices, QMatrix4x4 meshMatrix);

public:
    static QSharedPointer<Mesh> create(const QSharedPointer<IVertices> &vertices = nullptr, const QVector<uint> &indices = QVector<uint>(), QMatrix4x4 meshMatrix = QMatrix4x4());
};

}

#endif // MESH_H
