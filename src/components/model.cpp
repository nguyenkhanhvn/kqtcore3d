#include "model.h"

#include "kqtcore3d.h"
#include "opengl/openglmodel.h"

namespace kqtcore3d
{

QSharedPointer<Model> Model::create(const QVector<QSharedPointer<BaseMesh> > &meshes, QSharedPointer<IModelImporter> importer)
{
    LOG << getRendererApi();
    switch(getRendererApi())
    {
    case OpenGL:
        return QSharedPointer<OpenGLModel>::create(meshes, importer);
        break;
    case Unknown:
        break;
    }
    return nullptr;
}

void Model::render(QSharedPointer<IRenderCallbacks> callback)
{
#ifdef RENDER_LOG
    LOG;
#endif
    ALL_MESHES_DO_FUNCTION(render, callback)
}

void Model::renderPrimitive(uint meshId, uint primitiveId, QSharedPointer<IRenderCallbacks> callback)
{
#ifdef RENDER_LOG
    LOG << "messId: " << meshId << "primitiveId: " << primitiveId;
#endif
    if (meshId < m_meshes.size())
    {
        QSharedPointer<Mesh> mesh = qSharedPointerCast<Mesh, BaseMesh>(m_meshes.at(meshId));
        if (!mesh.isNull()) mesh->renderPrimitive(primitiveId, callback);
    }
}

Model::Model(const QVector<QSharedPointer<BaseMesh> > &meshes, QSharedPointer<IModelImporter> importer) :
    BaseModel(meshes, importer)
{}

}
