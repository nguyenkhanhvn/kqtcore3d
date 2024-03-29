#ifndef KQTCORE3D_H
#define KQTCORE3D_H


#include "kqtcore3dutils.h"
#include "core/core.h"
#include "interfaces/interfaces.h"
#include "components/components.h"
#include "callbacks/callbacks.h"

namespace kqtcore3d {

bool kqtcore3dInit(kqtcore3d::RendererApi platform = RendererApi::OpenGL);

RendererApi getRendererApi();

}

#endif // KQTCORE3D_H
