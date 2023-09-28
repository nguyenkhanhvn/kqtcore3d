#ifndef OPENGLMODEL_H
#define OPENGLMODEL_H


#include "kqtcore3d/core/model.h"

namespace kqtcore3d
{

class OpenGLModel : public Model<uint>
{
public:
    OpenGLModel(const QVector<QSharedPointer<Mesh<uint>>>& meshes = QVector<QSharedPointer<Mesh<uint>>>(), QSharedPointer<IModelImporter<uint>> importer = nullptr);

    virtual bool init(QSharedPointer<IRenderCallbacks> callBack = nullptr) override;
    virtual void render(QSharedPointer<IRenderCallbacks> callBack = nullptr) override;
};

}

#endif // OPENGLMODEL_H
