#include "shaderprogramlayout.h"

#include "common.h"

namespace kqtcore3d {

unsigned int ShaderProgramLayoutElement::GetSizeOfType(GLenum type)
{
    switch (type)
    {
    case GL_FLOAT: return sizeof(GLfloat);
    case GL_UNSIGNED_INT: return sizeof(GLuint);
    case GL_UNSIGNED_BYTE: return sizeof(GLubyte);
    default: return 0;
    }
}

void ShaderProgramLayout::push(ShaderProgramLayoutElement &element, bool autoCalculateLocation, bool autoCalculateOffset, bool autoCalculateStride)
{
    LOG << element.attribLocation << ", " << element.name;
    if(autoCalculateLocation) element.attribLocation = m_elements.size();
    if(autoCalculateOffset) element.offset = calculateStride();

    m_elements.push_back(element);
    if (autoCalculateStride) m_stride = element.offset + element.tupleSize * ShaderProgramLayoutElement::GetSizeOfType(element.type);
}

void ShaderProgramLayout::push(int attribLocation, GLenum type, GLint tupleSize, bool autoCalculateStride)
{
    LOG << attribLocation;
    int offset = calculateStride();
    m_elements.push_back({attribLocation, nullptr, offset, type, tupleSize});
    if (autoCalculateStride) m_stride = offset + tupleSize * ShaderProgramLayoutElement::GetSizeOfType(type);
}

void ShaderProgramLayout::push(const char *name, GLenum type, GLint tupleSize, bool autoCalculateStride)
{
    LOG << name;
    int offset = calculateStride();
    m_elements.push_back({-1, name, offset, type, tupleSize});
    if (autoCalculateStride) m_stride = offset + tupleSize * ShaderProgramLayoutElement::GetSizeOfType(type);
}

void ShaderProgramLayout::push(GLenum type, GLint tupleSize, bool autoCalculateStride)
{
    LOG << type << ", " << tupleSize;
    int offset = calculateStride();
    m_elements.push_back({static_cast<int>(m_elements.size()), nullptr, offset, type, tupleSize});
    if (autoCalculateStride) m_stride = offset + tupleSize * ShaderProgramLayoutElement::GetSizeOfType(type);
}

QVector<ShaderProgramLayoutElement> ShaderProgramLayout::getElements() const
{
    return m_elements;
}

int ShaderProgramLayout::getStride() const
{
    return m_stride;
}

void ShaderProgramLayout::setStride(int stride)
{
    if (m_stride != stride)
    {
        m_stride = stride;
    }
}

int ShaderProgramLayout::calculateStride()
{
    int stride = 0;
    for (const ShaderProgramLayoutElement& element : m_elements)
    {
        stride += element.tupleSize * ShaderProgramLayoutElement::GetSizeOfType(element.type);
    }
    return stride;
}

}
