#include "RenderContext.h"

namespace Micro
{
static const raylib::Camera3D* s_activeCamera = nullptr;

void SetActiveCamera3D(const raylib::Camera3D* camera)
{
    s_activeCamera = camera;
}

const raylib::Camera3D& GetActiveCamera3D()
{
    return *s_activeCamera;
}
}  // namespace Micro
