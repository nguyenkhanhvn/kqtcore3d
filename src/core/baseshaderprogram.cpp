#include "baseshaderprogram.h"

namespace kqtcore3d
{

QVector<ShaderLayout> BaseShaderProgram::getLayouts() const
{
    return m_layouts;
}

void BaseShaderProgram::setLayouts(QVector<ShaderLayout> layouts)
{
    m_layouts = layouts;
}

void BaseShaderProgram::addLayout(ShaderLayout layout)
{
    m_layouts.append(layout);
}

void BaseShaderProgram::addLayout(const char *name, GLenum type, int offset, int tupleSize)
{
    m_layouts.append({-1, name, type, offset, tupleSize});
}

void BaseShaderProgram::addLayout(int attribLocation, GLenum type, int offset, int tupleSize)
{
    m_layouts.append({attribLocation, "", type, offset, tupleSize});
}

}
