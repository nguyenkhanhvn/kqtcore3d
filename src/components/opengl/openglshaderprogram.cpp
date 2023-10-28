#include "opengl/openglshaderprogram.h"

#include "common.h"

namespace kqtcore3d
{

OpenGLShaderProgram::OpenGLShaderProgram(const QString& vertexShaderSource, const QString& fragmentShaderSource, const ShaderProgramLayout &layout) :
    ShaderProgram(vertexShaderSource, fragmentShaderSource, layout)
{}

bool OpenGLShaderProgram::init()
{
    LOG;
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

void OpenGLShaderProgram::setAttributeBuffer(int layoutId)
{
    LOG << layoutId;
    if (layoutId < m_layout.getElements().size() && m_program.bind())
    {
        const ShaderProgramLayoutElement& element = m_layout.getElements().at(layoutId);
        if (element.attribLocation >= 0)
        {
            m_program.enableAttributeArray(element.attribLocation);
            m_program.setAttributeBuffer(element.attribLocation, element.type, element.offset, element.tupleSize, m_layout.getStride());
        }
        else if (element.name && element.name[0])
        {
            m_program.enableAttributeArray(element.name);
            m_program.setAttributeBuffer(element.name, element.type, element.offset, element.tupleSize, m_layout.getStride());
        }
        else
        {
            m_program.enableAttributeArray(layoutId);
            m_program.setAttributeBuffer(layoutId, element.type, element.offset, element.tupleSize, m_layout.getStride());
        }
    }
}

void OpenGLShaderProgram::setAllAttributeBuffer()
{
    LOG;
    for (uint i = 0; i < m_layout.getElements().size(); i++)
    {
        setAttributeBuffer(i);
    }
}

void OpenGLShaderProgram::setAttributeBuffer(int location, GLenum type, int offset, int tupleSize, int stride)
{
    LOG << "location: " << location << ", type: " << type << ", offset: " <<  offset << ", typleSize: " << tupleSize << ", stride: " << stride;
    m_program.enableAttributeArray(location);
    m_program.setAttributeBuffer(location, type, offset, tupleSize, stride);
}

void OpenGLShaderProgram::setAttributeBuffer(const char *name, GLenum type, int offset, int tupleSize, int stride)
{
    LOG << "name: " << name << ", type: " << type << ", offset: " <<  offset << ", typleSize: " << tupleSize << ", stride: " << stride;
    m_program.enableAttributeArray(name);
    m_program.setAttributeBuffer(name, type, offset, tupleSize, stride);
}

void OpenGLShaderProgram::initCallBack()
{
    setAllAttributeBuffer();
}

}
