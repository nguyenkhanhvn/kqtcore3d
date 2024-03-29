#include "bufferlayout.h"

#include "kqtcore3dutils.h"

namespace kqtcore3d {

unsigned int BufferLayoutElement::GetSizeOfType(GLenum type)
{
    switch (type)
    {
    case GL_FLOAT: return sizeof(GLfloat);
    case GL_UNSIGNED_INT: return sizeof(GLuint);
    case GL_UNSIGNED_BYTE: return sizeof(GLubyte);
    default: return 0;
    }
}

void BufferLayout::push(BufferLayoutElement &element, bool autoCalculateLocation, bool autoCalculateOffset, bool autoCalculateStride)
{
    LOG << element.attribLocation << ", " << element.name;
    if(autoCalculateLocation) element.attribLocation = m_elements.size();
    if(autoCalculateOffset) element.offset = calculateStride();

    m_elements.push_back(element);
    if (autoCalculateStride) m_stride = element.offset + element.tupleSize * BufferLayoutElement::GetSizeOfType(element.type);
}

void BufferLayout::push(int attribLocation, GLenum type, GLint tupleSize, bool autoCalculateStride)
{
    LOG << attribLocation;
    int offset = calculateStride();
    m_elements.push_back({attribLocation, nullptr, offset, type, tupleSize});
    if (autoCalculateStride) m_stride = offset + tupleSize * BufferLayoutElement::GetSizeOfType(type);
}

void BufferLayout::push(const char *name, GLenum type, GLint tupleSize, bool autoCalculateStride)
{
    LOG << name;
    int offset = calculateStride();
    m_elements.push_back({-1, name, offset, type, tupleSize});
    if (autoCalculateStride) m_stride = offset + tupleSize * BufferLayoutElement::GetSizeOfType(type);
}

QVector<BufferLayoutElement> BufferLayout::getElements() const
{
    return m_elements;
}

int BufferLayout::getStride() const
{
    return m_stride;
}

void BufferLayout::setStride(int stride)
{
    if (m_stride != stride)
    {
        m_stride = stride;
    }
}

int BufferLayout::calculateStride()
{
    int stride = 0;
    for (const BufferLayoutElement& element : m_elements)
    {
        stride += element.tupleSize * BufferLayoutElement::GetSizeOfType(element.type);
    }
    return stride;
}

}
