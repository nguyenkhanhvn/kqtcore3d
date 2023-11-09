#ifndef IRENDERABLE_H
#define IRENDERABLE_H


#include <QSharedPointer>

#include "kqtcore3d/interfaces/irendercallback.h"

namespace kqtcore3d
{

class IRenderable
{
public:
    // initialize before render
    virtual bool init(QSharedPointer<IRenderCallbacks> callback = nullptr) = 0;

    virtual void render(QSharedPointer<IRenderCallbacks> callback = nullptr) = 0;
};

}

#endif // IRENDERABLE_H
