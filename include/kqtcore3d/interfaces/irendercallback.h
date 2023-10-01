#ifndef IRENDERCALLBACK_H
#define IRENDERCALLBACK_H


namespace kqtcore3d
{

class IRenderCallbacks
{
public:
    virtual void initCallBack() {}

    virtual void beforeRenderCallBack() {}
};

}

#endif // IRENDERCALLBACK_H
