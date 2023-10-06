#include "opengl/openglmesh.h"

namespace kqtcore3d
{

OpenGLMesh::OpenGLMesh(const QSharedPointer<IVertices> &vertices, const QSharedPointer<IIndices> &indices, QMatrix4x4 meshMatrix) :
    Mesh(vertices, indices, meshMatrix)
{}

bool OpenGLMesh::init(QSharedPointer<IRenderCallbacks> callBack)
{
    if(m_vao.isNull()) m_vao = QSharedPointer<QOpenGLVertexArrayObject>::create();
    if(!m_vao.isNull() && !m_vao->isCreated()) m_vao->create();

    if(!m_vao.isNull() && m_vao->isCreated())
    {
        m_vao->bind();
        if(m_vertices->getSize() > 0)
        {
            if(m_vbo.isNull()) m_vbo = QSharedPointer<QOpenGLBuffer>::create(QOpenGLBuffer::VertexBuffer);
            if(!m_vbo.isNull())
            {
                if(!m_vbo->isCreated()) m_vbo->create();
                if(m_vbo->isCreated() && m_vbo->bind())
                {
                    m_vbo->setUsagePattern(QOpenGLBuffer::StaticDraw);
                    m_vbo->allocate(m_vertices->getData(), m_vertices->getByteSize());
                }
                else
                {
                    qDebug() << "[kqtcore3d] Cannot create or bind OpenGL Mesh Vertex Buffer Object";
                    return false;
                }
            }
        }

        if(m_indices->getSize() > 0)
        {
            if(m_ebo.isNull()) m_ebo = QSharedPointer<QOpenGLBuffer>::create(QOpenGLBuffer::IndexBuffer);
            if(!m_ebo.isNull())
            {
                if(!m_ebo->isCreated()) m_ebo->create();
                if(m_ebo->isCreated() && m_ebo->bind())
                {
                    m_ebo->setUsagePattern(QOpenGLBuffer::StaticDraw);
                    m_ebo->allocate(m_indices->getData(), m_indices->getByteSize());
                }
                else
                {
                    qDebug() << "[kqtcore3d] Cannot create or bind OpenGL Mesh Element Buffer Object";
                    return false;
                }
            }
        }

        if (!callBack.isNull())
        {
            callBack->initCallBack();
        }

        return true;
    }
    else
    {
        qDebug() << "[kqtcore3d] Cannot create OpenGL Mesh Vertex Array Object";
        return false;
    }

    qDebug() << "[kqtcore3d] Unknown error!";
    return false;
}

void OpenGLMesh::render(QSharedPointer<IRenderCallbacks> callBack)
{
    m_vao->bind();

    if(!callBack.isNull()) callBack->beforeRenderCallBack();

    glDrawElements(GL_TRIANGLES, m_indices->getSize(), m_indices->getType(), 0);

    m_vao->release();
}

void OpenGLMesh::renderPrimitive(uint primitiveId, QSharedPointer<IRenderCallbacks> callBack)
{
    if ((primitiveId * 3) < m_indices->getSize())
    {
        m_vao->bind();

        if(!callBack.isNull()) callBack->beforeRenderCallBack();

        glDrawElements(GL_TRIANGLES, 3, m_indices->getType(), (void *)(3 * primitiveId * sizeof(uint)));

        m_vao->release();
    }
}

void OpenGLMesh::drawElements(GLenum mode, GLsizei count, const GLvoid *indices, QSharedPointer<IRenderCallbacks> callBack)
{
    m_vao->bind();

    if(!callBack.isNull()) callBack->beforeRenderCallBack();

    glDrawElements(mode, count, m_indices->getType(), indices);

    m_vao->release();
}

void OpenGLMesh::drawArrays(GLenum mode, GLint first, const GLint count, QSharedPointer<IRenderCallbacks> callBack)
{
    m_vao->bind();

    if(!callBack.isNull()) callBack->beforeRenderCallBack();

    glDrawArrays(mode, first, count);

    m_vao->release();
}

void OpenGLMesh::drawByFunction(void (*drawFunction)(), QSharedPointer<IRenderCallbacks> callBack)
{
    m_vao->bind();

    if(!callBack.isNull()) callBack->beforeRenderCallBack();

    drawFunction();

    m_vao->release();
}

}
