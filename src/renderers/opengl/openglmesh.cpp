#include "openglmesh.h"

using namespace kqtcore3d;


OpenGLMesh::OpenGLMesh(const QSharedPointer<IVertices> &vertices, const QVector<uint> &indices, QMatrix4x4 modelMatrix) :
    Mesh<uint>(vertices, indices, modelMatrix)
{}

bool OpenGLMesh::init(QSharedPointer<IRenderCallbacks> callBack)
{
    if(m_vao.isNull()) m_vao = QSharedPointer<QOpenGLVertexArrayObject>::create();
    if(!m_vao.isNull() && !m_vao->isCreated()) m_vao->create();

    if(m_vbo.isNull()) m_vbo = QSharedPointer<QOpenGLBuffer>::create(QOpenGLBuffer::VertexBuffer);
    if(!m_vbo.isNull() && !m_vbo->isCreated()) m_vbo->create();

    if(m_ebo.isNull()) m_ebo = QSharedPointer<QOpenGLBuffer>::create(QOpenGLBuffer::IndexBuffer);
    if(!m_ebo.isNull() && !m_ebo->isCreated()) m_ebo->create();

    if(!m_vao.isNull() && !m_vbo.isNull() && !m_ebo.isNull()
        && m_vao->isCreated() && m_vbo->isCreated() && m_ebo->isCreated())
    {
        m_vao->bind();
        if(m_vbo->bind() && m_ebo->bind())
        {
            m_vbo->setUsagePattern(QOpenGLBuffer::StaticDraw);
            m_vbo->allocate(m_vertices->getData(), m_vertices->getByteSize());
            m_vbo->release();

            m_ebo->setUsagePattern(QOpenGLBuffer::StaticDraw);
            m_ebo->allocate(m_indices.constData(), m_indices.size() * sizeof(uint));
            m_ebo->release();

            if (!callBack.isNull()) callBack->initAttribBufferCallBack(m_vertices->getByteSize());

            m_vao->release();
            m_vbo->release();
            m_ebo->release();
            return true;
        }
        m_vao->release();
    }
    return false;
}

void OpenGLMesh::render(QSharedPointer<IRenderCallbacks> callBack)
{
    m_vao->bind();

    if(!callBack.isNull()) callBack->beforeRenderCallBack();

    glDrawElements(GL_TRIANGLES, m_indices.size(), GL_UNSIGNED_INT, 0);

    m_vao->release();
}
