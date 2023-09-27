#include "openglmesh.h"

#include "shaderprogram.h"

using namespace kqtcore3d;


OpenGLMesh::OpenGLMesh(const QSharedPointer<IVertices> &vertices, const QVector<uint> &indices, QMatrix4x4 modelMatrix) :
    Mesh<uint>(vertices, indices, modelMatrix)
{}

bool OpenGLMesh::init(QSharedPointer<ShaderProgram> program)
{
    if(m_vao.isNull()) m_vao = QSharedPointer<QOpenGLVertexArrayObject>::create();
    if(!m_vao.isNull() && !m_vao->isCreated()) m_vao->create();

    if(m_vbo.isNull()) m_vbo = QSharedPointer<QOpenGLBuffer>::create(QOpenGLBuffer::VertexBuffer);
    if(!m_vbo.isNull() && !m_vbo->isCreated()) m_vbo->create();

    if(m_ebo.isNull()) m_ebo = QSharedPointer<QOpenGLBuffer>::create(QOpenGLBuffer::IndexBuffer);
    if(!m_ebo.isNull() && !m_ebo->isCreated()) m_ebo->create();

    if(!program.isNull() && !m_vao.isNull() && !m_vbo.isNull() && !m_ebo.isNull()
        && m_vao->isCreated() && m_vbo->isCreated() && m_ebo->isCreated())
    {
        if(m_vbo->bind())
        {
            m_vbo->setUsagePattern(QOpenGLBuffer::StaticDraw);
            m_vbo->allocate(m_vertices->getData(), m_vertices->getByteSize());
            m_vbo->release();
        } else return false;

        if(m_ebo->bind())
        {
            m_ebo->setUsagePattern(QOpenGLBuffer::StaticDraw);
            m_ebo->allocate(m_indices.constData(), m_indices.size() * sizeof(uint));
            m_ebo->release();
        } else return false;

        if(program->bind())
        {

            if(m_vbo->bind() && m_ebo->bind())
            {
                program->setAllAttributeBuffer(m_vertices->getByteSize());

                m_vao->release();
                m_vbo->release();
                m_ebo->release();
            } else return false;

            program->release();
        } else return false;
    }
    return false;
}

void OpenGLMesh::draw(QSharedPointer<ShaderProgram> program, QSharedPointer<Camera> camera)
{
    if (!program.isNull() && !camera.isNull()) {
        program->bind();
        m_vao->bind();

        program->setUniformValue(m_program->uniformLocation("cameraMatrix"), camera->getCameraMatrix());
        program->setUniformValue(m_program->uniformLocation("modelMatrix"), m_modelMatrix);

        glDrawElements(GL_TRIANGLES, m_indices.size(), GL_UNSIGNED_INT, 0);

        m_vao->release();
        program->release();
    }
}
