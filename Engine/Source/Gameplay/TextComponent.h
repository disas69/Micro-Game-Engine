#pragma once

#include "Gameplay/GraphicComponent.h"

namespace Micro
{
class Transform2dComponent;

class TextComponent : public GraphicComponent
{
public:
    TextComponent();

    void OnRender() override;

    std::string Text;
    float FontSize = 20.0f;
    raylib::Color Color;

private:
    Transform2dComponent* m_transform = nullptr;
};
}  // namespace Micro
