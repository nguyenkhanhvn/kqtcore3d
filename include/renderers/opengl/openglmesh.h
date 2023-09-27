#ifndef OPENGLMESH_H
#define OPENGLMESH_H


#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>

#include "interfaces/ivertices.h"
#include "mesh.h"

namespace kqtcore3d
{

class OpenGLMesh : public Mesh<uint>
{
public:
    OpenGLMesh(const QSharedPointer<IVertices>& vertices, const QVector<uint>& indices, QMatrix4x4 modelMatrix = QMatrix4x4());

    // IDrawable interface
    virtual bool init(QSharedPointer<IRenderCallbacks> callBack = nullptr) override;
    virtual void render(QSharedPointer<IRenderCallbacks> callBack = nullptr) override;

private:
    QSharedPointer<QOpenGLVertexArrayObject> m_vao;
    QSharedPointer<QOpenGLBuffer> m_vbo;
    QSharedPointer<QOpenGLBuffer> m_ebo;


};

}

#endif // OPENGLMESH_H
