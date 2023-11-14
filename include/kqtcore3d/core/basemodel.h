#ifndef BASEMODEL_H
#define BASEMODEL_H


#include "kqtcore3d/interfaces/imodelimporter.h"

namespace kqtcore3d
{

#define ALL_MESHES_DO_FUNCTION(functionName, ...)   \
for (const QSharedPointer<BaseMesh>& mesh : m_meshes)      \
    {                                               \
        mesh->functionName(__VA_ARGS__);            \
    }


class BaseModel : public IRenderable
{
public:
    BaseModel(const QVector<QSharedPointer<BaseMesh>>& meshes, QSharedPointer<IModelImporter> importer);
    virtual ~BaseModel();

    virtual bool loadModel(const QString &filename);
    virtual bool loadModelFromMemory(const QByteArray &data);

    virtual QSharedPointer<IModelImporter> getImporter() const;
    virtual void setImporter(QSharedPointer<IModelImporter> importer);
    virtual QVector<QSharedPointer<BaseMesh>> getMeshes() const;
    virtual void setMeshes(QVector<QSharedPointer<BaseMesh>> meshes);
    virtual void addMeshes(QVector<QSharedPointer<BaseMesh>> meshes);
    virtual void addMesh(QSharedPointer<BaseMesh> mesh);

    virtual void translate(const QVector3D &vector);
    virtual void translate(float x, float y);
    virtual void translate(float x, float y, float z);
    virtual void rotate(float angle, const QVector3D &rotateAxis);
    virtual void rotate(float angle, float x, float y, float z = 0);
    virtual void rotate(const QQuaternion &quaternion);
    virtual void rotateGlobal(float angle, const QVector3D &rotateAxis);
    virtual void scale(const QVector3D &vector);
    virtual void scale(float x, float y);
    virtual void scale(float x, float y, float z);
    virtual void scale(float factor);


protected:
    QSharedPointer<IModelImporter> m_importer = nullptr;
    QVector<QSharedPointer<BaseMesh>> m_meshes;

};

}

#endif // BASEMODEL_H
