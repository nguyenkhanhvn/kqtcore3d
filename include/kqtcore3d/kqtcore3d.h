#ifndef KQTCORE3D_H
#define KQTCORE3D_H


#include "common.h"
#include "core/core.h"
#include "interfaces/interfaces.h"
#include "renderers/renderers.h"

namespace kqtcore3d {

bool initializeQQuickWindow(RendererApi platform = RendererApi::OpenGL);

RendererApi getRendererApi();

}

#endif // KQTCORE3D_H
