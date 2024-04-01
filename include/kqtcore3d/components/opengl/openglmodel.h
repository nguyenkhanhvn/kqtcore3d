#ifndef OPENGLMODEL_H
#define OPENGLMODEL_H


#include "kqtcore3d/components/model.h"

namespace kqtcore3d
{

class OpenGLModel : public Model
{
public:
    OpenGLModel(const QVector<QSharedPointer<BaseMesh>>& meshes = {}, QSharedPointer<IModelImporter> importer = nullptr);

    virtual void destroy();

};

}

#endif // OPENGLMODEL_H
