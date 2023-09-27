#include "model.h"

using namespace kqtcore3d;

Model::Model(const QVector<QSharedPointer<Mesh>> &meshes, QSharedPointer<IModelImporter> importer) :
    m_importer(importer)
{}

Model::~Model()
{}

void Model::setImporter(QSharedPointer<IModelImporter> importer)
{
    if (m_importer != importer)
    {
        m_importer = importer;
    }
}

bool Model::loadModel(const QString &filename)
{
    if(m_importer)
    {
        ModelImporterData loadedData = m_importer->loadModel(filename);
        if(loadedData.isLoaded)
        {
            m_meshes.clear();
            m_meshes = loadedData.meshes;
            return true;
        }
    }
    return false;
}

bool Model::loadModelFromMemory(const QByteArray &data)
{
    if(m_importer)
    {
        ModelImporterData loadedData = m_importer->loadModelFromMemory(data);
        if(loadedData.isLoaded)
        {
            m_meshes.clear();
            m_meshes = loadedData.meshes;
            return true;
        }
    }
    return false;
}

QVector<QSharedPointer<Mesh>> Model::getMeshes() const
{
    return m_meshes;
}

void Model::setMeshes(QVector<QSharedPointer<Mesh>> meshes)
{
    m_meshes = meshes;
}

void Model::addMeshes(QVector<QSharedPointer<Mesh>> meshes)
{
    m_meshes.append(meshes);
}

void Model::addMesh(QSharedPointer<Mesh> mesh)
{
    m_meshes.append(mesh);
}
