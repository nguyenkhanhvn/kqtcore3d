#include "opengl/openglshaderprogram.h"

namespace kqtcore3d
{

OpenGLShaderProgram::OpenGLShaderProgram(const QString& vertexShaderSource, const QString& fragmentShaderSource, const QVector<ShaderLayout>& layout) :
    ShaderProgram(vertexShaderSource, fragmentShaderSource, layout)
{}

bool OpenGLShaderProgram::init()
{
    bool result = true;
    result &= m_program.addShaderFromSourceCode(QOpenGLShader::Vertex, m_vsSource);
    result &= m_program.addShaderFromSourceCode(QOpenGLShader::Fragment, m_fsSource);
    result &= m_program.link();
    m_program.release();

    return result;
}

bool OpenGLShaderProgram::bind()
{
    return m_program.bind();
}

void OpenGLShaderProgram::release()
{
    m_program.release();
}

void OpenGLShaderProgram::setAttributeBuffer(int layoutId, int stride)
{
    if (layoutId < m_layouts.size() && m_program.bind())
    {
        const ShaderLayout& layout = m_layouts.at(layoutId);
        if (layout.attribLocation >= 0)
        {
            m_program.enableAttributeArray(layout.attribLocation);
            m_program.setAttributeBuffer(layout.attribLocation, layout.type, layout.offset, layout.tupleSize, stride);
        }
        else if (layout.name && layout.name[0])
        {
            m_program.enableAttributeArray(layout.name);
            m_program.setAttributeBuffer(layout.name, layout.type, layout.offset, layout.tupleSize, stride);
        }
        else
        {
            m_program.enableAttributeArray(layoutId);
            m_program.setAttributeBuffer(layoutId, layout.type, layout.offset, layout.tupleSize, stride);
        }
    }
}

void OpenGLShaderProgram::setAllAttributeBuffer(int stride)
{
    for (uint i = 0; i < m_layouts.size(); i++)
    {
        setAttributeBuffer(i, stride);
    }
}

void OpenGLShaderProgram::setRawAttributeBuffer(int location, GLenum type, int offset, int tupleSize, int stride)
{
    m_program.enableAttributeArray(location);
    m_program.setAttributeBuffer(location, type, offset, tupleSize, stride);
}

void OpenGLShaderProgram::setRawAttributeBuffer(const char *name, GLenum type, int offset, int tupleSize, int stride)
{
    m_program.enableAttributeArray(name);
    m_program.setAttributeBuffer(name, type, offset, tupleSize, stride);
}

void OpenGLShaderProgram::initAttribBufferCallBack(int stride)
{
    setAllAttributeBuffer(stride);
}

}
