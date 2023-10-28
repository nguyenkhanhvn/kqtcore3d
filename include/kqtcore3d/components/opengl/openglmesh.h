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
    virtual bool init(QSharedPointer<IRenderCallbacks> callBack = nullptr) override;
    virtual void render(QSharedPointer<IRenderCallbacks> callBack = nullptr) override;

    // Mesh interface
    virtual void renderPrimitive(uint primitiveId, QSharedPointer<IRenderCallbacks> callBack) override;

    // OpenGL custom draw
    virtual void drawElements(GLenum mode, GLsizei count, const GLvoid *indices, QSharedPointer<IRenderCallbacks> callBack = nullptr);
    virtual void drawArrays(GLenum mode, GLint first, const GLint count, QSharedPointer<IRenderCallbacks> callBack = nullptr);
    /**** Carefull with this option ****/
    virtual void drawByFunction(std::function<void ()> drawFunction, QSharedPointer<IRenderCallbacks> callBack = nullptr);

private:
    QSharedPointer<QOpenGLVertexArrayObject> m_vao;
    QSharedPointer<QOpenGLBuffer> m_vbo;
    QSharedPointer<QOpenGLBuffer> m_ebo;

};

}

#endif // OPENGLMESH_H
