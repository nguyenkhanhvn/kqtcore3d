#ifndef IINDICES_H
#define IINDICES_H


namespace kqtcore3d
{

class IIndices
{
public:
    virtual const void* getData() = 0;

    virtual int getType() = 0;
    virtual int getSize() = 0;
    virtual int getByteSize() = 0;
};

}

#endif // IINDICES_H
