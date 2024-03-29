#ifndef INDICES_H
#define INDICES_H


#include <QVector>

#include "kqtcore3d/interfaces/iindices.h"

namespace kqtcore3d {

template<typename T, int type>
class Indices : public IIndices
{
public:
    Indices(const QVector<T>& indices = QVector<T>()) : m_indices(indices) {}

    // IIndices interface
    virtual const void *getData() override {
        return m_indices.constData();
    }
    virtual int getType() override {
        return type;
    }
    virtual int getSize() override {
        return m_indices.size();
    }
    virtual int getByteSize() override {
        return m_indices.size() * sizeof(uint);
    }


    QVector<T> getIndices() const {
        return m_indices;
    }
    void setIndices(const QVector<T>& indices) {
        if (m_indices != indices) {
            m_indices = indices;
        }
    }

    void push(T index) {
        m_indices.push_back(index);
    }

protected:
    QVector<T> m_indices;

};

}

#endif // INDICES_H
