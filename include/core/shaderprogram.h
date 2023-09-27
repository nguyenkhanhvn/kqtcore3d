#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H


#include "common.h"
#include "interfaces/irendercallback.h"

namespace kqtcore3d
{

class ShaderProgram : public IRenderCallbacks
{
public:
    ShaderProgram(const QVector<ShaderProgramLayout> layout = QVector<ShaderProgramLayout>()) :
        m_layout(layout)
    {}

    virtual bool bind() = 0;
    virtual void release() = 0;

    virtual void setAttributeBuffer(int layoutIndex, int stride) = 0;
    virtual void setAllAttributeBuffer(int stride) = 0;


    virtual QVector<ShaderProgramLayout> getLayouts() const
    {
        return m_layout;
    }
    virtual void setLayouts(QVector<ShaderProgramLayout> layout)
    {
        m_layout = layout;
    }
    virtual void addLayout(ShaderProgramLayout layout)
    {
        m_layout.append(layout);
    }
    virtual void addLayout(QString name, GLenum type, int offset, int tupleSize)
    {
        m_layout.append({-1, name, type, offset, tupleSize});
    }
    virtual void addLayout(int attribLocation, GLenum type, int offset, int tupleSize)
    {
        m_layout.append({attribLocation, "", type, offset, tupleSize});
    }

private:
    QVector<ShaderProgramLayout> m_layout;

};

}

#endif // SHADERPROGRAM_H
