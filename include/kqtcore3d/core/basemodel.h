#ifndef BASEMODEL_H
#define BASEMODEL_H


#include "kqtcore3d/interfaces/imodelimporter.h"

namespace kqtcore3d
{

#define ALL_MESHES_DO_FUNCTION(functionName, meshType, ...)   \
for (const QSharedPointer<BaseMesh<meshType>>& mesh : m_meshes)      \
    {                                               \
        mesh->functionName(__VA_ARGS__);            \
    }


template<typename I>
class BaseModel : public IRenderable
{
public:
    BaseModel(const QVector<QSharedPointer<BaseMesh<I>>>& meshes, QSharedPointer<IModelImporter<I>> importer) :
        m_importer(importer)
    {}
    virtual ~BaseModel() {}

    virtual bool loadModel(const QString &filename)
    {
        if(m_importer)
        {
            ModelImporterData<I> loadedData = m_importer->loadModel(filename);
            if(loadedData.isLoaded)
            {
                m_meshes = loadedData.meshes;
                return true;
            }
        }
        return false;
    }
    virtual bool loadModelFromMemory(const QByteArray &data)
    {
        if(m_importer)
        {
            ModelImporterData<I> loadedData = m_importer->loadModelFromMemory(data);
            if(loadedData.isLoaded)
            {
                m_meshes = loadedData.meshes;
                return true;
            }
        }
        return false;
    }

    virtual QSharedPointer<IModelImporter<I>> getImporter() const
    {
        return m_importer;
    }
    virtual void setImporter(QSharedPointer<IModelImporter<I>> importer)
    {
        if (m_importer != importer)
        {
            m_importer = importer;
        }
    }
    virtual QVector<QSharedPointer<BaseMesh<I>>> getMeshes() const
    {
        return m_meshes;
    }
    virtual void setMeshes(QVector<QSharedPointer<BaseMesh<I>>> meshes)
    {
        m_meshes = meshes;
    }
    virtual void addMeshes(QVector<QSharedPointer<BaseMesh<I>>> meshes)
    {
        m_meshes.append(meshes);
    }
    virtual void addMesh(QSharedPointer<BaseMesh<I>> mesh)
    {
        m_meshes.append(mesh);
    }


protected:
    QSharedPointer<IModelImporter<I>> m_importer;
    QVector<QSharedPointer<BaseMesh<I>>> m_meshes;

};

}

#endif // BASEMODEL_H
