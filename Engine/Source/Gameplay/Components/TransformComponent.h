#pragma once

#include "Component.h"

namespace Micro
{
class TransformComponent : public Component
{
public:
    MVector3 Position = {0.0f, 0.0f, 0.0f};
    MVector3 Rotation = {0.0f, 0.0f, 0.0f};
    MVector3 Scale = {1.0f, 1.0f, 1.0f};

    TransformComponent() = default;

    MMatrix GetTransformMatrix() const;
};
}  // namespace Micro
