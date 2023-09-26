#include "kqtcore3d.h"

#include <QQuickWindow>

using namespace kqtcore3d;

bool initializeQQuickWindow(GraphicApi platform)
{
    switch (platform)
    {
    case OpenGL:
#ifdef WIN32
    {
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
    case Unknown:
        return false;
    }
    return false;
}
