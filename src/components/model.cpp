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

Model::Model(const QVector<QSharedPointer<BaseMesh> > &meshes, QSharedPointer<IModelImporter> importer) :
    BaseModel(meshes, importer)
{}

}
