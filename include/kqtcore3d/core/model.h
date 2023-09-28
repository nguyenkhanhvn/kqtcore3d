#ifndef MODEL_H
#define MODEL_H


#include "kqtcore3d/interfaces/imodelimporter.h"

namespace kqtcore3d
{

#define ALL_MESHES_DO_FUNCTION(functionName, meshType, ...)   \
for (const QSharedPointer<Mesh<meshType>>& mesh : m_meshes)      \
    {                                               \
        mesh->functionName(__VA_ARGS__);            \
    }


template<typename I>
class Model : public IRenderable
{
public:
    Model(const QVector<QSharedPointer<Mesh<I>>>& meshes, QSharedPointer<IModelImporter<I>> importer) :
        m_importer(importer)
    {}
    virtual ~Model() {}

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
    virtual QVector<QSharedPointer<Mesh<I>>> getMeshes() const
    {
        return m_meshes;
    }
    virtual void setMeshes(QVector<QSharedPointer<Mesh<I>>> meshes)
    {
        m_meshes = meshes;
    }
    virtual void addMeshes(QVector<QSharedPointer<Mesh<I>>> meshes)
    {
        m_meshes.append(meshes);
    }
    virtual void addMesh(QSharedPointer<Mesh<I>> mesh)
    {
        m_meshes.append(mesh);
    }


protected:
    QSharedPointer<IModelImporter<I>> m_importer;
    QVector<QSharedPointer<Mesh<I>>> m_meshes;

};

}

#endif // MODEL_H
