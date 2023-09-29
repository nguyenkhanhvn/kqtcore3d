#ifndef MODEL_H
#define MODEL_H


#include "kqtcore3d/core/basemodel.h"

namespace kqtcore3d {

class Model : public BaseModel<uint>
{
public:
    static QSharedPointer<Model> create(const QVector<QSharedPointer<BaseMesh<uint>>>& meshes = QVector<QSharedPointer<BaseMesh<uint>>>(), QSharedPointer<IModelImporter<uint>> importer = nullptr);

    virtual void renderPrimitive(uint meshId, uint primitiveId, QSharedPointer<IRenderCallbacks> callBack = nullptr);

protected:
    Model(const QVector<QSharedPointer<BaseMesh<uint>>>& meshes, QSharedPointer<IModelImporter<uint>> importer);

};

}

#endif // MODEL_H
