#pragma once

#include "Gameplay/Components/Transform2dComponent.h"
#include "Gameplay/Components/GraphicComponent.h"

#include <raylib-cpp.hpp>

namespace Micro
{
class ButtonComponent : public GraphicComponent
{
public:
    ButtonComponent();

    MVector2 Size;

    void OnRender() override;

    void SetText(const std::string& text);
    void SetOnClick(const std::function<void()>& onClick);

private:
    std::string m_text;
    std::function<void()> m_onClick;
    Transform2dComponent* m_transform = nullptr;
};
}  // namespace Micro