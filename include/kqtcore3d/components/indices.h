#ifndef INDICES_H
#define INDICES_H


#include <QVector>

#include "kqtcore3d/interfaces/iindices.h"

namespace kqtcore3d {

class Indices : public IIndices
{
public:
    Indices(const QVector<uint>& indices = QVector<uint>());

    // IIndices interface
    virtual const void *getData() override;
    virtual int getType() override;
    virtual int getSize() override;
    virtual int getByteSize() override;

    QVector<uint> getIndices() const;
    void setIndices(const QVector<uint>& indices);

    void push(uint index);

private:
    QVector<uint> m_indices;

};

}

#endif // INDICES_H
