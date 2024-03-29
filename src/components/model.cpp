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

Model::Model(const QVector<QSharedPointer<BaseMesh> > &meshes, QSharedPointer<IModelImporter> importer) :
    BaseModel(meshes, importer)
{}

}
