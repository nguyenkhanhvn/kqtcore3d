#ifndef OPENGLMESH_H
#define OPENGLMESH_H


#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>

#include "ivertices.h"
#include "mesh.h"

namespace kqtcore3d
{

class OpenGLMesh : public Mesh
{
public:
    OpenGLMesh(const QSharedPointer<IVertices>& vertices = nullptr, const QVector<uint>& indices = QVector<uint>(), QMatrix4x4 meshMatrix = QMatrix4x4());

    // IDrawable interface
    virtual bool init(QSharedPointer<IRenderCallbacks> callBack = nullptr) override;
    virtual void render(QSharedPointer<IRenderCallbacks> callBack = nullptr) override;

    // Mesh interface
    virtual void renderPrimitive(uint primitiveId, QSharedPointer<IRenderCallbacks> callBack) override;

private:
    QSharedPointer<QOpenGLVertexArrayObject> m_vao;
    QSharedPointer<QOpenGLBuffer> m_vbo;
    QSharedPointer<QOpenGLBuffer> m_ebo;

};

}

#endif // OPENGLMESH_H
