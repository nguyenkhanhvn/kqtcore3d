#ifndef IDRAWABLE_H
#define IDRAWABLE_H


#include "camera.h"
#include "shaderprogram.h"

namespace kqtcore3d
{

class IDrawable
{
public:
    // initialize before render
    virtual bool init(QSharedPointer<ShaderProgram> program) = 0;

    virtual void draw(QSharedPointer<ShaderProgram> program, QSharedPointer<Camera> camera) = 0;
};

}

#endif // IDRAWABLE_H
