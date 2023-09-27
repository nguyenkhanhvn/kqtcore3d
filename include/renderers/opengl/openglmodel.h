#ifndef OPENGLMODEL_H
#define OPENGLMODEL_H


#include "model.h"

namespace kqtcore3d
{

class OpenGLModel : public Model<uint>
{
public:
    OpenGLModel();

    virtual bool init(QSharedPointer<IRenderCallbacks> callBack = nullptr) override;
    virtual void render(QSharedPointer<IRenderCallbacks> callBack = nullptr) override;
};

}

#endif // OPENGLMODEL_H
