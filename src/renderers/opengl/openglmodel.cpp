#include "opengl/openglmodel.h"

namespace kqtcore3d
{

OpenGLModel::OpenGLModel(const QVector<QSharedPointer<BaseMesh>> &meshes, QSharedPointer<IModelImporter> importer) :
    Model(meshes, importer)
{}

bool OpenGLModel::init(QSharedPointer<IRenderCallbacks> callBack)
{
    bool result = true;
    for (const QSharedPointer<BaseMesh>& mesh : m_meshes)
        {
            result &= mesh->init(callBack);
        }
    return result;
}

}
