#ifndef SHADERPROGRAMLAYOUT_H
#define SHADERPROGRAMLAYOUT_H


#include <QOpenGLFunctions>

namespace kqtcore3d
{

struct ShaderProgramLayoutElement
{
    int attribLocation = -1;
    const char* name;
    int offset = -1;
    GLenum type;
    GLint tupleSize;

    // for now, support only GL_FLOAT, GL_UNSIGNED_INT, GL_UNSIGNED_BYTE, other -> size 0;
    static unsigned int GetSizeOfType(GLenum type);
};

class ShaderProgramLayout
{
public:
    virtual void push(ShaderProgramLayoutElement &element, bool autoCalculateLocation = true, bool autoCalculateOffset = true, bool autoCalculateStride = true);
    virtual void push(int attribLocation, GLenum type, GLint tupleSize, bool autoCalculateStride = true);
    virtual void push(const char* name, GLenum type, GLint tupleSize, bool autoCalculateStride = true);
    virtual void push(GLenum type, GLint tupleSize, bool autoCalculateStride = true);

    virtual QVector<ShaderProgramLayoutElement> getElements() const;

    virtual int getStride() const;
    virtual void setStride(int stride);

    virtual int calculateStride();

private:
    QVector<ShaderProgramLayoutElement> m_elements;
    int m_stride;

};

}

#endif // SHADERPROGRAMLAYOUT_H
