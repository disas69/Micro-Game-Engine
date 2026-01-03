#include "LabelComponent.h"
#include "Gameplay/Components/Transform2dComponent.h"
#include "Gameplay/GameObject.h"

namespace Micro
{
LabelComponent::LabelComponent() : GraphicComponent(GraphicComponentType::GraphicTypeUI)
{
    m_text = "Label";
}

void LabelComponent::SetText(const std::string& text)
{
    m_text = text;
}

void LabelComponent::OnRender()
{
    if (m_transform == nullptr)
    {
        m_transform = GetOwner()->GetComponent<Transform2dComponent>();
    }

    if (m_transform != nullptr)
    {
        auto position = m_transform->Position;

        GuiLabel({position.x, position.y, Size.x, Size.y}, m_text.c_str());
    }
}
}  // namespace Micro
