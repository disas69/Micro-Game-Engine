#pragma once

namespace Micro
{
void SetActiveCamera3D(const raylib::Camera3D* camera);
const raylib::Camera3D& GetActiveCamera3D();
}  // namespace Micro
