#include "kqtcore3d/core/shaderprogram.h"

using namespace kqtcore3d;


QVector<ShaderProgramLayout> ShaderProgram::getLayouts() const
{
    return m_layout;
}

void ShaderProgram::setLayouts(QVector<ShaderProgramLayout> layout)
{
    m_layout = layout;
}

void ShaderProgram::addLayout(ShaderProgramLayout layout)
{
    m_layout.append(layout);
}

void ShaderProgram::addLayout(QString name, GLenum type, int offset, int tupleSize)
{
    m_layout.append({-1, name, type, offset, tupleSize});
}

void ShaderProgram::addLayout(int attribLocation, GLenum type, int offset, int tupleSize)
{
    m_layout.append({attribLocation, "", type, offset, tupleSize});
}
