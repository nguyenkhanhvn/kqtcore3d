 #ifndef IVERTICES_H
#define IVERTICES_H


namespace kqtcore3d
{

class IVertices
{
public:
    virtual const void* getData() = 0;

    virtual int getByteSize() = 0;
    virtual int getStride() = 0;
};

}

#endif // IVERTICES_H