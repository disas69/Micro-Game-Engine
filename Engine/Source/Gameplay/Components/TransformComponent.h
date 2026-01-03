#pragma once

#include "Component.h"

namespace Micro
{
class TransformComponent : public Component
{
public:
    raylib::Vector3 Position = {0.0f, 0.0f, 0.0f};
    raylib::Vector3 Rotation = {0.0f, 0.0f, 0.0f};
    raylib::Vector3 Scale = {1.0f, 1.0f, 1.0f};

    TransformComponent() = default;

    raylib::Matrix GetTransformMatrix() const;
};
}  // namespace Micro
