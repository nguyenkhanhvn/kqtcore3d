#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H


#include "kqtcore3d/common.h"

namespace kqtcore3d
{

class ShaderProgram
{
public:
    ShaderProgram(const QVector<ShaderProgramLayout> layout = QVector<ShaderProgramLayout>()) :
        m_layout(layout)
    {}

    virtual bool bind() = 0;
    virtual void release() = 0;

    virtual void setAttributeBuffer(int layoutIndex, int stride) = 0;
    virtual void setAllAttributeBuffer(int stride) = 0;


    virtual QVector<ShaderProgramLayout> getLayouts() const;
    virtual void setLayouts(QVector<ShaderProgramLayout> layout);
    virtual void addLayout(ShaderProgramLayout layout);
    virtual void addLayout(QString name, GLenum type, int offset, int tupleSize);
    virtual void addLayout(int attribLocation, GLenum type, int offset, int tupleSize);

private:
    QVector<ShaderProgramLayout> m_layout;

};

}

#endif // SHADERPROGRAM_H
