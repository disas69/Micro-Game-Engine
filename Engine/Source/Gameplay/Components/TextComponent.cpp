#include "TextComponent.h"
#include "Gameplay/GameObject.h"
#include "Gameplay/Components/Transform2dComponent.h"

namespace Micro
{
TextComponent::TextComponent() : GraphicComponent(GraphicComponentType::GraphicTypeUI)
{
    Color = MColor(0, 0, 0, 255);
}

void TextComponent::OnRender()
{
    if (m_transform == nullptr)
    {
        m_transform = GetOwner()->GetComponent<Transform2dComponent>();
    }

    if (m_transform != nullptr)
    {
        DrawText(Text, m_transform->Position.x, m_transform->Position.y, FontSize, Color);
    }
}
}  // namespace Micro
