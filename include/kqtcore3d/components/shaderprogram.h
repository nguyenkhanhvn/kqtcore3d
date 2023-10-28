#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H


#include "kqtcore3d/core/baseshaderprogram.h"
#include "kqtcore3d/interfaces/irendercallback.h"

namespace kqtcore3d {

class ShaderProgram : public BaseShaderProgram, public IRenderCallbacks
{
public:
    static QSharedPointer<ShaderProgram> create(const QString& vertexShaderSource, const QString& fragmentShaderSource, const ShaderProgramLayout& layout = ShaderProgramLayout());

    QString getVertexShaderSource() const;
    QString getFragmentShaderSource() const;

protected:
    ShaderProgram(const QString& vertexShaderSource, const QString& fragmentShaderSource, const ShaderProgramLayout& layout = ShaderProgramLayout());

protected:
    QString m_vsSource;
    QString m_fsSource;

};

}

#endif // SHADERPROGRAM_H
