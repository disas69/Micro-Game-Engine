#pragma once

#include "GraphicComponent.h"

namespace Micro
{
class TransformComponent;

class SpriteComponent : public GraphicComponent
{
public:
    SpriteComponent();

    void OnRender() override;

    raylib::Texture2D SpriteTexture;
    raylib::Rectangle SourceRect = {0, 0, 100, 100};

private:
    TransformComponent* m_transform = nullptr;
};
}  // namespace Micro