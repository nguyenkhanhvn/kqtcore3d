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


    // IRenderable interface
    virtual bool init(RenderCallback callback = {}) override;
    virtual void render(RenderCallback callback = {}) override;


    virtual bool loadModel(const QString &filename);
    virtual bool loadModelFromMemory(const QByteArray &data);

    virtual QSharedPointer<IModelImporter> getImporter() const;
    virtual void setImporter(QSharedPointer<IModelImporter> importer);
    virtual QVector<QSharedPointer<BaseMesh>> getMeshes() const;
    virtual void setMeshes(QVector<QSharedPointer<BaseMesh>> meshes);
    virtual void addMeshes(QVector<QSharedPointer<BaseMesh>> meshes);
    virtual void addMesh(QSharedPointer<BaseMesh> mesh);

    virtual void translate(const QVector3D &vector) override;
    virtual void translate(float x, float y) override;
    virtual void translate(float x, float y, float z) override;
    virtual void rotate(float angle, float x, float y, float z = 0) override;
    virtual void rotate(const QQuaternion &quaternion) override;
    virtual void rotate(const QVector3D &rotateAxis, float angle) override;
    virtual void rotateGlobal(const QVector3D &rotateAxis, float angle, const QVector3D &rotatePoint = {0,0,0}) override;
    virtual void scale(const QVector3D &vector) override;
    virtual void scale(float x, float y) override;
    virtual void scale(float x, float y, float z) override;
    virtual void scale(float factor) override;


protected:
    QSharedPointer<IModelImporter> m_importer = nullptr;
    QVector<QSharedPointer<BaseMesh>> m_meshes;

};

}

#endif // BASEMODEL_H
