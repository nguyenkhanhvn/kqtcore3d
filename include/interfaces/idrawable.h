#ifndef IDRAWABLE_H
#define IDRAWABLE_H


namespace kqtcore3d
{

class IModelImporter
{
public:
    void draw(Camera* camera, QOpenGLShaderProgram* program, QOpenGLFunctions* openglFunction);
};

}

#endif // IDRAWABLE_H
