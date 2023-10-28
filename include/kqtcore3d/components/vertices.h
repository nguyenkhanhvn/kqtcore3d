#ifndef VERTICES_H
#define VERTICES_H

#include <QVector>
#include <QVector4D>

#include "kqtcore3d/interfaces/ivertices.h"

namespace kqtcore3d {

struct Vertex {
    QVector3D position;
    QVector3D normal;
    QVector4D color = {0.0, 0.0, 0.0, 1.0};
    QVector2D texUV;
};

class Vertices : public IVertices
{
public:
    Vertices(const QVector<Vertex>& vertices = QVector<Vertex>());

    // IVertices interface
    const void *getData();
    int getSize();
    int getByteSize();
    int getStride();

    void push(const Vertex& vertex);

private:
    QVector<Vertex> m_vertices;

};

}

#endif // VERTICES_H
