#include "opengl/openglmodel.h"

#include "kqtcore3dutils.h"

namespace kqtcore3d
{

OpenGLModel::OpenGLModel(const QVector<QSharedPointer<BaseMesh>> &meshes, QSharedPointer<IModelImporter> importer) :
    Model(meshes, importer)
{}

}
