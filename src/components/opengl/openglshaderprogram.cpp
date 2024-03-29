#include "opengl/openglshaderprogram.h"

#include "kqtcore3dutils.h"

namespace kqtcore3d
{

OpenGLShaderProgram::OpenGLShaderProgram(const QString& vsSource, const QString& fsSource, BufferLayout layouts) :
    ShaderProgram(vsSource, fsSource, layouts)
{}

bool OpenGLShaderProgram::init()
{
    bool result = true;
    result &= m_program.addShaderFromSourceCode(QOpenGLShader::Vertex, m_vsSource);
    result &= m_program.addShaderFromSourceCode(QOpenGLShader::Fragment, m_fsSource);
    result &= m_program.link();
    LOG << result;

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

void OpenGLShaderProgram::setAttributeBuffer(int location, GLenum type, int offset, int tupleSize, int stride)
{
#ifdef RENDER_LOG
    LOG << "location: " << location << ", type: " << type << ", offset: " <<  offset << ", typleSize: " << tupleSize << ", stride: " << stride;
#endif
    m_program.enableAttributeArray(location);
    m_program.setAttributeBuffer(location, type, offset, tupleSize, stride);
}

void OpenGLShaderProgram::setAttributeBuffer(const char *name, GLenum type, int offset, int tupleSize, int stride)
{
#ifdef RENDER_LOG
    LOG << "name: " << name << ", type: " << type << ", offset: " <<  offset << ", typleSize: " << tupleSize << ", stride: " << stride;
#endif
    m_program.enableAttributeArray(name);
    m_program.setAttributeBuffer(name, type, offset, tupleSize, stride);
}

void OpenGLShaderProgram::setAttributeBuffer(BufferLayout layouts)
{
#ifdef RENDER_LOG
    LOG;
#endif
    if (m_program.bind()) {
        for (uint i = 0; i < layouts.getElements().size(); i++)
        {
            const BufferLayoutElement& element = layouts.getElements().at(i);
            if (element.attribLocation >= 0)
            {
                m_program.enableAttributeArray(element.attribLocation);
                m_program.setAttributeBuffer(element.attribLocation, element.type, element.offset, element.tupleSize, layouts.getStride());
            }
            else if (element.name && element.name[0])
            {
                m_program.enableAttributeArray(element.name);
                m_program.setAttributeBuffer(element.name, element.type, element.offset, element.tupleSize, layouts.getStride());
            }
            else
            {
                m_program.enableAttributeArray(i);
                m_program.setAttributeBuffer(i, element.type, element.offset, element.tupleSize, layouts.getStride());
            }
        }
    }
}

void kqtcore3d::OpenGLShaderProgram::setAttributeBuffer()
{
    setAttributeBuffer(m_layouts);
}

}
