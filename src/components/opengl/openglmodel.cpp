#include "opengl/openglmodel.h"

#include "common.h"

namespace kqtcore3d
{

OpenGLModel::OpenGLModel(const QVector<QSharedPointer<BaseMesh>> &meshes, QSharedPointer<IModelImporter> importer) :
    Model(meshes, importer)
{}

bool OpenGLModel::init(QSharedPointer<IRenderCallbacks> callBack)
{
    LOG;
    bool result = true;
    for (const QSharedPointer<BaseMesh>& mesh : m_meshes)
        {
            result &= mesh->init(callBack);
        }
    return result;
}

}
