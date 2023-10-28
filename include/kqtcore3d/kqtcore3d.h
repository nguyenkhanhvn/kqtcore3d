#ifndef KQTCORE3D_H
#define KQTCORE3D_H


#include "common.h"
#include "core/core.h"
#include "interfaces/interfaces.h"
#include "components/components.h"

namespace kqtcore3d {

bool kqtcore3dInit(RendererApi platform = RendererApi::OpenGL);

RendererApi getRendererApi();

}

#endif // KQTCORE3D_H
