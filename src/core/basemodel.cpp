#include "basemodel.h"

namespace kqtcore3d
{

BaseModel::BaseModel(const QVector<QSharedPointer<BaseMesh> > &meshes, QSharedPointer<IModelImporter> importer) :
    m_meshes(meshes), m_importer(importer)
{}

BaseModel::~BaseModel() {}

bool BaseModel::init(RenderCallback callback)
{
    bool result = true;
    for (const QSharedPointer<BaseMesh>& mesh : m_meshes)
    {
        result &= mesh->init(callback);
    }
    return result;
}

void BaseModel::render(RenderCallback callback)
{
    ALL_MESHES_DO_FUNCTION(render, callback)
}

bool BaseModel::loadModel(const QString &filename)
{
    if(!m_importer.isNull())
    {
        ModelImporterData loadedData = m_importer->loadModel(filename);
        if(loadedData.isLoaded)
        {
            m_meshes = loadedData.meshes;
            return true;
        }
    }
    return false;
}

bool BaseModel::loadModelFromMemory(const QByteArray &data)
{
    if(!m_importer.isNull())
    {
        ModelImporterData loadedData = m_importer->loadModelFromMemory(data);
        if(loadedData.isLoaded)
        {
            m_meshes = loadedData.meshes;
            return true;
        }
    }
    return false;
}

QSharedPointer<IModelImporter> BaseModel::getImporter() const
{
    return m_importer;
}

void BaseModel::setImporter(QSharedPointer<IModelImporter> importer)
{
    if (m_importer != importer)
    {
        m_importer = importer;
    }
}

QVector<QSharedPointer<BaseMesh> > BaseModel::getMeshes() const
{
    return m_meshes;
}

void BaseModel::setMeshes(QVector<QSharedPointer<BaseMesh> > meshes)
{
    m_meshes = meshes;
}

void BaseModel::addMeshes(QVector<QSharedPointer<BaseMesh> > meshes)
{
    m_meshes.append(meshes);
}

void BaseModel::addMesh(QSharedPointer<BaseMesh> mesh)
{
    m_meshes.append(mesh);
}

void BaseModel::translate(const QVector3D &vector)
{
    ALL_MESHES_DO_FUNCTION(translate, vector);
}

void BaseModel::translate(float x, float y)
{
    ALL_MESHES_DO_FUNCTION(translate, x, y);
}

void BaseModel::translate(float x, float y, float z)
{
    ALL_MESHES_DO_FUNCTION(translate, x, y, z);
}

void BaseModel::rotate(float angle, float x, float y, float z)
{
    ALL_MESHES_DO_FUNCTION(rotate, angle, x, y, z);
}

void BaseModel::rotate(const QQuaternion &quaternion)
{
    ALL_MESHES_DO_FUNCTION(rotate, quaternion);
}

void BaseModel::rotate(const QVector3D &rotateAxis, float angle)
{
    ALL_MESHES_DO_FUNCTION(rotate, rotateAxis, angle);
}

void BaseModel::rotateGlobal(const QVector3D &rotateAxis, float angle, const QVector3D &rotatePoint)
{
    ALL_MESHES_DO_FUNCTION(rotateGlobal, rotateAxis, angle, rotatePoint);
}

void BaseModel::scale(const QVector3D &vector)
{
    ALL_MESHES_DO_FUNCTION(scale, vector);
}

void BaseModel::scale(float x, float y)
{
    ALL_MESHES_DO_FUNCTION(scale, x, y);
}

void BaseModel::scale(float x, float y, float z)
{
    ALL_MESHES_DO_FUNCTION(scale, x, y, z);
}

void BaseModel::scale(float factor)
{
    ALL_MESHES_DO_FUNCTION(scale, factor);
}

} // namespace kqtcore3d
