#include "pch.h"
#include "SpriteComponent.h"
#include "Gameplay/GameObject.h"
#include "Gameplay/TransformComponent.h"
#include "Core/RenderContext.h"

namespace Micro
{
SpriteComponent::SpriteComponent() : GraphicComponent(GraphicComponentType::GraphicType3D) {}

void SpriteComponent::OnRender()
{
    if (m_transform == nullptr)
    {
        m_transform = GetOwner()->GetComponent<TransformComponent>();
    }

    if (m_transform != nullptr)
    {
        DrawBillboard(GetActiveCamera3D(), SpriteTexture, m_transform->Position, SourceRect.width * m_transform->Scale.x, Tint);
    }
}
}  // namespace Micro
