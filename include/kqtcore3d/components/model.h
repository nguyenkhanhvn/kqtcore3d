#ifndef MODEL_H
#define MODEL_H


#include "kqtcore3d/core/basemodel.h"

namespace kqtcore3d {

class Model : public BaseModel
{
public:
    static QSharedPointer<Model> create(const QVector<QSharedPointer<BaseMesh>>& meshes = {}, QSharedPointer<IModelImporter> importer = nullptr);

    virtual void render(QSharedPointer<IRenderCallbacks> callback = nullptr) override;

protected:
    Model(const QVector<QSharedPointer<BaseMesh>>& meshes, QSharedPointer<IModelImporter> importer);

};

}

#endif // MODEL_H
