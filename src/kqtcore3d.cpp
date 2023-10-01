#include "kqtcore3d/kqtcore3d.h"

namespace kqtcore3d {

static RendererApi s_graphic = RendererApi::Unknown;

bool kqtcore3dInit(RendererApi platform)
{
    switch (platform)
    {
    case RendererApi::OpenGL:
        s_graphic = RendererApi::OpenGL;
    break;
    case RendererApi::Unknown:
        s_graphic = RendererApi::Unknown;
        return false;
    }
    return false;
}

RendererApi getRendererApi()
{
    return s_graphic;
}

}
