#include "shaderprogram.h"

#include "kqtcore3d.h"
#include "opengl/openglshaderprogram.h"

namespace kqtcore3d
{

QSharedPointer<ShaderProgram> ShaderProgram::create(const QString& vertexShaderSource, const QString& fragmentShaderSource, const ShaderProgramLayout& layout)
{
    switch(getRendererApi())
    {
    case OpenGL:
        return QSharedPointer<OpenGLShaderProgram>::create(vertexShaderSource, fragmentShaderSource, layout);
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

QString ShaderProgram::getFragmentShaderSource() const
{
    return m_fsSource;
}

ShaderProgram::ShaderProgram(const QString &vertexShaderSource, const QString &fragmentShaderSource, const ShaderProgramLayout &layout) :
    BaseShaderProgram(layout), m_vsSource(vertexShaderSource), m_fsSource(fragmentShaderSource)
{}

}
