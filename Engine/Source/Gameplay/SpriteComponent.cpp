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
        raylib::Vector3 up = {0.0f, 1.0f, 0.0f};
        raylib::Vector3 scale = m_transform->Scale;
        raylib::Vector2 size = (Vector2){SourceRect.width * scale.x, SourceRect.height * scale.y};
        raylib::Vector2 origin = Vector2Scale(size, 0.5);

        DrawBillboardPro(GetActiveCamera3D(), SpriteTexture, SourceRect, m_transform->Position, up, size, origin, m_transform->Rotation.y, Tint);
    }
}
}  // namespace Micro
