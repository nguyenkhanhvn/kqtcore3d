#include "kqtcore3d.h"

#include <QQuickWindow>

using namespace kqtcore3d;

static RendererApi s_graphic = RendererApi::Unknown;

bool initializeQQuickWindow(RendererApi platform)
{
    switch (platform)
    {
    case RendererApi::OpenGL:
#ifdef WIN32
    {
        s_graphic = RendererApi::OpenGL;
        QSurfaceFormat fmt;
        fmt.setVersion(3, 3);//use modern opengl
        fmt.setProfile(QSurfaceFormat::CoreProfile);
        QSurfaceFormat::setDefaultFormat(fmt);
        return true;
    }
#else
#ifdef EMSCRIPTEN
    {
        QSurfaceFormat fmt;
        fmt.setVersion(3, 0);//use modern opengl
        QSurfaceFormat::setDefaultFormat(fmt);
        return true;
    }
#else
        return false;
#endif
#endif
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
