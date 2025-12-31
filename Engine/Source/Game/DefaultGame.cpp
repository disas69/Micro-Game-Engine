#include "DefaultGame.h"
#include "Gameplay/GameObject.h"
#include "Gameplay/Transform2DComponent.h"
#include "Gameplay/SpriteComponent.h"

using namespace Micro;

DefaultGame::DefaultGame(ArenaAllocator& persistentArena) : GameBase(persistentArena)
{
    m_windowTitle = "Default Game";
}

void DefaultGame::OnInit()
{
    GameObject* gameObject = CreateGameObject<GameObject>(std::string("TestObject"));
    Transform2DComponent* transform2d = gameObject->AddComponent<Transform2DComponent>();
    transform2d->Position = {m_screenWidth / 2.0f, m_screenHeight / 2.0f};
    SpriteComponent* sprite = gameObject->AddComponent<SpriteComponent>();
    sprite->Tint = BLUE;

    // Note: SpriteTexture is not loaded here, so it won't render anything yet
    // but the system is set up.
}

void DefaultGame::Update(ArenaAllocator& frameArena, float deltaTime)
{
    UpdateGameObjects(deltaTime);
}

void DefaultGame::Render()
{
    RenderGameObjects();

    int textWidth = MeasureText("Default game is running!", 20);
    DrawText("Default game is running!", m_screenWidth / 2.0f - textWidth / 2.0f, m_screenHeight / 2.0f - 10, 20, LIGHTGRAY);
}