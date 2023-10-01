#include "baseshaderprogram.h"

namespace kqtcore3d
{

BaseShaderProgram::BaseShaderProgram(const ShaderProgramLayout &layout) :
    m_layout(layout)
{}

ShaderProgramLayout BaseShaderProgram::getLayout() const
{
    return m_layout;
}

void BaseShaderProgram::setLayouts(const ShaderProgramLayout &layout)
{
    m_layout = layout;
}

}
