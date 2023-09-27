#ifndef MODEL_H
#define MODEL_H


#include "interfaces/imodelimporter.h"

namespace kqtcore3d
{

class Model
{
public:
    Model(const QVector<QSharedPointer<Mesh>>& meshes = QVector<QSharedPointer<Mesh>>(), QSharedPointer<IModelImporter> importer = QSharedPointer<IModelImporter>());
    virtual ~Model();

    virtual void setImporter(QSharedPointer<IModelImporter> importer);
    virtual bool loadModel(const QString &filename);
    virtual bool loadModelFromMemory(const QByteArray &data);

    virtual QVector<QSharedPointer<Mesh>> getMeshes() const;
    virtual void setMeshes(QVector<QSharedPointer<Mesh>> meshes);
    virtual void addMeshes(QVector<QSharedPointer<Mesh>> meshes);
    virtual void addMesh(QSharedPointer<Mesh> mesh);

protected:
    QSharedPointer<IModelImporter> m_importer;
    QVector<QSharedPointer<Mesh>> m_meshes;

};

}

#endif // MODEL_H
