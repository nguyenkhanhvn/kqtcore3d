#ifndef RENDERCALLBACK_H
#define RENDERCALLBACK_H

#include <functional>

namespace kqtcore3d
{

// callback function parameter normally is the calling instance
struct RenderCallback
{
    std::function<void(void*)> initCallBack = nullptr;
    std::function<void(void*)> beforeRenderCallBack = nullptr;
    std::function<void(void*)> afterRenderCallBack = nullptr;
};

}

#endif // RENDERCALLBACK_H
