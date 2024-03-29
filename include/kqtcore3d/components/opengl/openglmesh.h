#ifndef OPENGLMESH_H
#define OPENGLMESH_H


#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>

#include "kqtcore3d/interfaces/ivertices.h"
#include "kqtcore3d/components/mesh.h"

namespace kqtcore3d
{

class OpenGLMesh : public Mesh
{
public:
    OpenGLMesh(const QSharedPointer<IVertices>& vertices = nullptr, const QSharedPointer<IIndices>& indices = nullptr, QMatrix4x4 meshMatrix = QMatrix4x4());

    // IDrawable interface
    virtual bool init(RenderCallback callback = {}) override;
    virtual void render(RenderCallback callback = {}) override;

    // BaseMesh interface
    virtual void setVertices(const QSharedPointer<IVertices> &newVertices) override;
    virtual void setIndices(const QSharedPointer<IIndices> &newIndices) override;

    // OpenGL custom draw
    virtual void drawElements(GLenum mode, GLsizei count, const GLvoid *indices = 0, RenderCallback callback = {});
    virtual void drawArrays(GLenum mode, GLint first, const GLint count, RenderCallback callback = {});

    /**** Carefull with this option ****/
    virtual void drawByFunction(std::function<void ()> drawFunction, RenderCallback callback = {});

protected:
    const QSharedPointer<QOpenGLVertexArrayObject> m_vao;
    const QSharedPointer<QOpenGLBuffer> m_vbo;
    const QSharedPointer<QOpenGLBuffer> m_ebo;

};

}

#endif // OPENGLMESH_H
