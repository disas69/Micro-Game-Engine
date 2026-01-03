#include "Component.h"

namespace Micro
{
void Component::SetActive(bool active)
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
