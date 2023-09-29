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


template<typename IndexType>
class BaseModel : public IRenderable
{
public:
    BaseModel(const QVector<QSharedPointer<BaseMesh<IndexType>>>& meshes, QSharedPointer<IModelImporter<IndexType>> importer) :
        m_importer(importer)
    {}
    virtual ~BaseModel() {}

    virtual bool loadModel(const QString &filename)
    {
        if(m_importer)
        {
            ModelImporterData<IndexType> loadedData = m_importer->loadModel(filename);
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
            ModelImporterData<IndexType> loadedData = m_importer->loadModelFromMemory(data);
            if(loadedData.isLoaded)
            {
                m_meshes = loadedData.meshes;
                return true;
            }
        }
        return false;
    }

    virtual QSharedPointer<IModelImporter<IndexType>> getImporter() const
    {
        return m_importer;
    }
    virtual void setImporter(QSharedPointer<IModelImporter<IndexType>> importer)
    {
        if (m_importer != importer)
        {
            m_importer = importer;
        }
    }
    virtual QVector<QSharedPointer<BaseMesh<IndexType>>> getMeshes() const
    {
        return m_meshes;
    }
    virtual void setMeshes(QVector<QSharedPointer<BaseMesh<IndexType>>> meshes)
    {
        m_meshes = meshes;
    }
    virtual void addMeshes(QVector<QSharedPointer<BaseMesh<IndexType>>> meshes)
    {
        m_meshes.append(meshes);
    }
    virtual void addMesh(QSharedPointer<BaseMesh<IndexType>> mesh)
    {
        m_meshes.append(mesh);
    }

    void translate(const QVector3D &vector)
    {
        ALL_MESHES_DO_FUNCTION(translate, IndexType, vector);
    }
    void rotate(float angle, const QVector3D &rotateAxis)
    {
        ALL_MESHES_DO_FUNCTION(rotate, IndexType, angle, rotateAxis);
    }
    void rotateGlobal(float angle, const QVector3D &rotateAxis)
    {
        ALL_MESHES_DO_FUNCTION(rotateGlobal, IndexType, angle, rotateAxis);
    }


protected:
    QSharedPointer<IModelImporter<IndexType>> m_importer;
    QVector<QSharedPointer<BaseMesh<IndexType>>> m_meshes;

};

}

#endif // BASEMODEL_H
