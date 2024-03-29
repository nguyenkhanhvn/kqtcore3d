#ifndef BASESHADERPROGRAM_H
#define BASESHADERPROGRAM_H

#include <QMatrix4x4>
#include <QOpenGLFunctions>

namespace kqtcore3d
{

class BaseShaderProgram
{
public:
    virtual bool init() = 0;
    virtual bool bind() = 0;
    virtual void release() = 0;

};

}

#endif // BASESHADERPROGRAM_H
