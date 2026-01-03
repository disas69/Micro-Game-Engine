#pragma once

#include "Component.h"

namespace Micro
{
class Transform2dComponent : public Component
{
public:
    MVector2 Position = {0.0f, 0.0f};
    float Rotation = 0.0f;
    MVector2 Scale = {1.0f, 1.0f};

    Transform2dComponent() = default;
};
}  // namespace Micro
