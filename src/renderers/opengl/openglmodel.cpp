#include "opengl/openglmodel.h"

namespace kqtcore3d
{

OpenGLModel::OpenGLModel(const QVector<QSharedPointer<BaseMesh<uint>>>& meshes, QSharedPointer<IModelImporter<uint>> importer) :
    Model(meshes, importer)
{}

bool OpenGLModel::init(QSharedPointer<IRenderCallbacks> callBack)
{
    bool result = true;
    for (const QSharedPointer<BaseMesh<uint>>& mesh : m_meshes)
        {
            result &= mesh->init(callBack);
        }
    return result;
}

void kqtcore3d::OpenGLModel::render(QSharedPointer<IRenderCallbacks> callBack)
{
    ALL_MESHES_DO_FUNCTION(render, uint, callBack)
}

}
