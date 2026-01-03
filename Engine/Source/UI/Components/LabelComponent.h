#pragma once

#include "Gameplay/Components/Transform2dComponent.h"
#include "Gameplay/Components/GraphicComponent.h"

namespace Micro
{
class LabelComponent : public GraphicComponent
{
public:
    LabelComponent();

    MVector2 Size;

    void OnRender() override;

    void SetText(const std::string& text);

private:
    std::string m_text;
    Transform2dComponent* m_transform = nullptr;
};
}  // namespace Micro
