#ifndef VERTICES_H
#define VERTICES_H

#include <QVector>
#include <QVector4D>

#include "kqtcore3d/interfaces/ivertices.h"

namespace kqtcore3d {

template<typename T>
class Vertices : public IVertices
{
public:
    Vertices(const QVector<T>& vertices = QVector<T>())  : m_vertices(vertices) {}

    // IVertices interface
    virtual const void *getData() override {
        return m_vertices.constData();
    }
    virtual int getSize() override {
        return m_vertices.size();
    }
    virtual int getByteSize() override {
        return m_vertices.size() * sizeof(T);
    }
    virtual int getStride() override {
        return sizeof(T);
    }

    QVector<T> getVertices() const {
        return m_vertices;
    }
    void setVertices(QVector<T> vertices) {
        m_vertices = vertices;
    }


    void push(const T& vertex) {
        m_vertices.push_back(vertex);
    }

protected:
    QVector<T> m_vertices;

};

}

#endif // VERTICES_H
