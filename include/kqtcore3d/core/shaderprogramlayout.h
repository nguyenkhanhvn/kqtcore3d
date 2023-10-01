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

    // for now, support only GL_FLOAT, GL_UNSIGNED_INT, GL_UNSIGNED_BYTE
    static unsigned int GetSizeOfType(GLenum type);
};

class ShaderProgramLayout
{
public:
    void push(ShaderProgramLayoutElement &element, bool autoCalculateLocation = true, bool autoCalculateOffset = true, bool autoCalculateStride = true);
    void push(int attribLocation, GLenum type, GLint tupleSize, bool autoCalculateStride = true);
    void push(const char* name, GLenum type, GLint tupleSize, bool autoCalculateStride = true);
    void push(GLenum type, GLint tupleSize, bool autoCalculateStride = true);

    QVector<ShaderProgramLayoutElement> getElements() const;

    int getStride() const;
    void setStride(int stride);

    int calculateStride();

private:
    QVector<ShaderProgramLayoutElement> m_elements;
    int m_stride;

};

}

#endif // SHADERPROGRAMLAYOUT_H
