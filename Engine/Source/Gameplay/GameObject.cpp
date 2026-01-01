#include "GameObject.h"

namespace Micro
{
GameObject::GameObject(ArenaAllocator& arena, std::string name) : m_arena(arena), m_name(std::move(name)) {}

GameObject::GameObject(ArenaAllocator& arena) : m_arena(arena), m_name("GameObject") {}

void GameObject::OnInit()
{
    for (auto* component : m_components)
    {
        component->OnInit();
    }
}

void GameObject::OnUpdate(float deltaTime)
{
    if (!m_isActive)
    {
        return;
    }

    for (auto* component : m_components)
    {
        if (component->IsActive())
        {
            component->OnUpdate(deltaTime);
        }
    }
}

void GameObject::OnRender()
{
    if (!m_isActive)
    {
        return;
    }

    for (auto* component : m_components)
    {
        if (component->IsActive())
        {
            component->OnRender();
        }
    }
}

void GameObject::OnDestroy()
{
    for (auto* component : m_components)
    {
        component->OnDestroy();
    }
}

void GameObject::SetActive(bool active)
{
    if (m_isActive == active)
    {
        return;
    }

    m_isActive = active;

    if (m_isActive)
    {
        OnEnable();
    }
    else
    {
        OnDisable();
    }
}
}  // namespace Micro
