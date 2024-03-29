#include "shaderprogram.h"

#include "kqtcore3d.h"
#include "opengl/openglshaderprogram.h"

namespace kqtcore3d
{

QSharedPointer<ShaderProgram> ShaderProgram::create(const QString& vsSource, const QString& fsSource, BufferLayout layouts)
{
    LOG << getRendererApi();
    switch(getRendererApi())
    {
    case OpenGL:
        return QSharedPointer<OpenGLShaderProgram>::create(vsSource, fsSource);
        break;
    case Unknown:
        break;
    }
    return nullptr;
}

QString ShaderProgram::getVertexShaderSource() const
{
    return m_vsSource;
}

void ShaderProgram::setVertexShaderSource(QString vsSource)
{
    if(m_vsSource == vsSource) return;
    m_vsSource = vsSource;
}

QString ShaderProgram::getFragmentShaderSource() const
{
    return m_fsSource;
}

void ShaderProgram::setFragmentShaderSource(const QString & fsSource)
{
    if(m_fsSource == fsSource) return;
    m_fsSource = fsSource;
}

BufferLayout ShaderProgram::getBufferLayouts() const
{
    return m_layouts;
}

void ShaderProgram::setBufferLayouts(const BufferLayout &layouts)
{
    m_layouts = layouts;
}

ShaderProgram::ShaderProgram(const QString &vsSource, const QString &fsSource, BufferLayout layouts) :
    m_vsSource(vsSource), m_fsSource(fsSource), m_layouts(layouts)
{}

}
