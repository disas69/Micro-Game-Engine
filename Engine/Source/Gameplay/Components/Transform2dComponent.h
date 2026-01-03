#pragma once

#include "Component.h"

namespace Micro
{
class Transform2dComponent : public Component
{
public:
    raylib::Vector2 Position = {0.0f, 0.0f};
    float Rotation = 0.0f;
    raylib::Vector2 Scale = {1.0f, 1.0f};

    Transform2dComponent() = default;
};
}  // namespace Micro
