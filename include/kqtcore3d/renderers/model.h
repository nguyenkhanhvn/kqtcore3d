#ifndef MODEL_H
#define MODEL_H


#include "kqtcore3d/core/basemodel.h"

namespace kqtcore3d {

class Model : public BaseModel<uint>
{
protected:
    Model(const QVector<QSharedPointer<BaseMesh<uint>>>& meshes, QSharedPointer<IModelImporter<uint>> importer);

public:
    static QSharedPointer<Model> create(const QVector<QSharedPointer<BaseMesh<uint>>>& meshes = QVector<QSharedPointer<BaseMesh<uint>>>(), QSharedPointer<IModelImporter<uint>> importer = nullptr);
};

}

#endif // MODEL_H
