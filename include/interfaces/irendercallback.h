#ifndef IRENDERCALLBACK_H
#define IRENDERCALLBACK_H

class IRenderCallbacks
{
public:
    virtual void initCallBack() {}
    virtual void initAttribBufferCallBack(int stride) {}

    virtual void beforeRenderCallBack() {}
};

#endif // IRENDERCALLBACK_H
