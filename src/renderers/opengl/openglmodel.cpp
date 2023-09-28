#include "kqtcore3d/renderers/opengl/openglmodel.h"

using namespace kqtcore3d;


OpenGLModel::OpenGLModel(const QVector<QSharedPointer<Mesh<uint>>>& meshes, QSharedPointer<IModelImporter<uint>> importer) :
    Model<uint>(meshes, importer)
{}

bool OpenGLModel::init(QSharedPointer<IRenderCallbacks> callBack)
{
    bool result = true;
    for (const QSharedPointer<Mesh<uint>>& mesh : m_meshes)
        {
            result &= mesh->init(callBack);
        }
    return result;
}

void kqtcore3d::OpenGLModel::render(QSharedPointer<IRenderCallbacks> callBack)
{
    ALL_MESHES_DO_FUNCTION(render, uint, callBack)
}
