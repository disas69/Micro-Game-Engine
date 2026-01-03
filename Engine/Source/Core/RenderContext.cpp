#include "RenderContext.h"

namespace Micro
{
static const MCamera3D* s_activeCamera = nullptr;

void SetActiveCamera3D(const MCamera3D* camera)
{
    s_activeCamera = camera;
}

const MCamera3D& GetActiveCamera3D()
{
    return *s_activeCamera;
}
}  // namespace Micro
