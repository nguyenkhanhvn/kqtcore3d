#ifndef OPENGLMODEL_H
#define OPENGLMODEL_H


#include "kqtcore3d/components/model.h"

namespace kqtcore3d
{

class OpenGLModel : public Model
{
public:
    OpenGLModel(const QVector<QSharedPointer<BaseMesh>>& meshes = QVector<QSharedPointer<BaseMesh>>(), QSharedPointer<IModelImporter> importer = nullptr);

    virtual bool init(QSharedPointer<IRenderCallbacks> callback = nullptr) override;
};

}

#endif // OPENGLMODEL_H
