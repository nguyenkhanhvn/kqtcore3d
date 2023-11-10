#include "opengl/openglmesh.h"

#include "common.h"

namespace kqtcore3d
{

OpenGLMesh::OpenGLMesh(const QSharedPointer<IVertices> &vertices, const QSharedPointer<IIndices> &indices, QMatrix4x4 meshMatrix) :
    Mesh(vertices, indices, meshMatrix),
    m_vao(QSharedPointer<QOpenGLVertexArrayObject>::create()),
    m_vbo(QSharedPointer<QOpenGLBuffer>::create(QOpenGLBuffer::VertexBuffer)),
    m_ebo(QSharedPointer<QOpenGLBuffer>::create(QOpenGLBuffer::IndexBuffer))
{}

bool OpenGLMesh::init(QSharedPointer<IRenderCallbacks> callback)
{
    LOG;
    if(!m_vao->isCreated()) m_vao->create();

    if(m_vao->isCreated())
    {
        m_vao->bind();
        if(!m_vertices.isNull() && m_vertices->getSize() > 0)
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

        if(!m_indices.isNull() && m_indices->getSize() > 0)
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

        if (!callback.isNull())
        {
            callback->initCallBack();
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

void OpenGLMesh::render(QSharedPointer<IRenderCallbacks> callback)
{
#ifdef RENDER_LOG
    LOG;
#endif
    if(m_indices.isNull()) return;

    m_vao->bind();

    if(!callback.isNull()) callback->beforeRenderCallBack();

    glDrawElements(GL_TRIANGLES, m_indices->getSize(), m_indices->getType(), 0);

    if(!callback.isNull()) callback->afterRenderCallBack();

    m_vao->release();
}

void OpenGLMesh::setVertices(const QSharedPointer<IVertices> &newVertices)
{
    LOG << newVertices;
    if(newVertices.isNull() || m_vertices == newVertices) return;
    if (m_vertices.isNull() || newVertices->getByteSize() > m_vertices->getByteSize()) {
        Mesh::setVertices(newVertices);
        if(m_vbo->bind())
        {
            m_vbo->allocate(m_vertices->getData(), m_vertices->getByteSize());
        }
    } else {
        Mesh::setVertices(newVertices);
        if(m_vbo->bind())
        {
            m_vbo->write(0, m_vertices->getData(), m_vertices->getByteSize());
        }
    }
}

void OpenGLMesh::setIndices(const QSharedPointer<IIndices> &newIndices)
{
    LOG << newIndices;
    if(newIndices.isNull() || m_indices == newIndices) return;
    if (m_indices.isNull() || newIndices->getByteSize() > m_indices->getByteSize()) {
        Mesh::setIndices(newIndices);
        if(m_ebo->bind())
        {
            m_ebo->allocate(m_indices->getData(), m_indices->getByteSize());
        }
    } else {
        Mesh::setIndices(newIndices);
        if(m_ebo->bind())
        {
            m_ebo->write(0, m_indices->getData(), m_indices->getByteSize());
        }
    }
}

void OpenGLMesh::drawElements(GLenum mode, GLsizei count, const GLvoid *indices, QSharedPointer<IRenderCallbacks> callback)
{
#ifdef RENDER_LOG
    LOG << "mode: " << mode << ", count: " << count;
#endif
    if(m_indices.isNull()) return;

    m_vao->bind();

    if(!callback.isNull()) callback->beforeRenderCallBack();

    glDrawElements(mode, count, m_indices->getType(), indices);

    if(!callback.isNull()) callback->afterRenderCallBack();

    m_vao->release();
}

void OpenGLMesh::drawArrays(GLenum mode, GLint first, const GLint count, QSharedPointer<IRenderCallbacks> callback)
{
#ifdef RENDER_LOG
    LOG << "mode: " << mode << ", first: " << first << ", count: " << count;
#endif
    m_vao->bind();

    if(!callback.isNull()) callback->beforeRenderCallBack();

    glDrawArrays(mode, first, count);

    if(!callback.isNull()) callback->afterRenderCallBack();

    m_vao->release();
}

void OpenGLMesh::drawByFunction(std::function<void ()> drawFunction, QSharedPointer<IRenderCallbacks> callback)
{
#ifdef RENDER_LOG
    LOG;
#endif
    m_vao->bind();

    if(!callback.isNull()) callback->beforeRenderCallBack();

    drawFunction();

    if(!callback.isNull()) callback->afterRenderCallBack();

    m_vao->release();
}

}
