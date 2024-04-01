#include "opengl/openglmodel.h"

#include "kqtcore3dutils.h"
#include "opengl/openglmesh.h"

namespace kqtcore3d
{

OpenGLModel::OpenGLModel(const QVector<QSharedPointer<BaseMesh>> &meshes, QSharedPointer<IModelImporter> importer) :
    Model(meshes, importer)
{}

void OpenGLModel::destroy()
{
    for (const QSharedPointer<BaseMesh>& mesh : m_meshes) {
        QSharedPointer<OpenGLMesh> tmp = qSharedPointerCast<OpenGLMesh>(mesh);
        if(tmp) tmp->destroy();
    }
}

}
