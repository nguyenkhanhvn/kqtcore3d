#include "opengl/openglshaderprogram.h"

using namespace kqtcore3d;


OpenGLShaderProgram::OpenGLShaderProgram(const QString& vertexShaderSource, const QString& fragmentShaderSource, const QVector<ShaderLayout>& layout) :
    ShaderProgram(vertexShaderSource, fragmentShaderSource, layout)
{}

bool OpenGLShaderProgram::init()
{
    bool result = true;
    result &= m_program.bind();
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
    if (layoutId < m_layouts.size())
    {
        const ShaderLayout& layout = m_layouts.at(layoutId);
        if (layout.attribLocation >= 0)
        {
            m_program.enableAttributeArray(layout.attribLocation);
            m_program.setAttributeBuffer(layout.attribLocation, layout.type, layout.offset, stride);
        }
        else if (layout.name && layout.name[0])
        {
            m_program.enableAttributeArray(layout.name);
            m_program.setAttributeBuffer(layout.name, layout.type, layout.offset, stride);
        }
    }
}

void OpenGLShaderProgram::setAllAttributeBuffer(int stride)
{
    for (const ShaderLayout& layout : m_layouts)
    {
        if (layout.attribLocation >= 0)
        {
            m_program.enableAttributeArray(layout.attribLocation);
            m_program.setAttributeBuffer(layout.attribLocation, layout.type, layout.offset, stride);
        }
        else if (layout.name && layout.name[0])
        {
            m_program.enableAttributeArray(layout.name);
            m_program.setAttributeBuffer(layout.name, layout.type, layout.offset, stride);
        }
    }
}

void OpenGLShaderProgram::initAttribBufferCallBack(int stride)
{
    setAllAttributeBuffer(stride);
}
