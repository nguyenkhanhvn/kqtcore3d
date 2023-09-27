#ifndef IRENDERABLE_H
#define IRENDERABLE_H


#include "interfaces/irendercallback.h"

namespace kqtcore3d
{

class IRenderable
{
public:
    // initialize before render
    virtual bool init(QSharedPointer<IRenderCallbacks> callBack) = 0;

    virtual void render(QSharedPointer<IRenderCallbacks> callBack) = 0;
};

}

#endif // IRENDERABLE_H
