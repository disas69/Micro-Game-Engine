#include "GameBase.h"
#include "Gameplay/GameObject.h"

using namespace Micro;

void GameBase::Init()
{
    Resize(GetScreenWidth(), GetScreenHeight());
    OnInit();
}

void GameBase::Resize(int screenWidth, int screenHeight)
{
    m_screenWidth = screenWidth;
    m_screenHeight = screenHeight;
}

void GameBase::UpdateGameObjects(float deltaTime)
{
    for (auto* gameObject : m_gameObjects)
    {
        gameObject->OnUpdate(deltaTime);
    }
}

void GameBase::RenderGameObjects()
{
    for (auto* gameObject : m_gameObjects)
    {
        gameObject->OnRender();
    }
}