#include "Engine.h"

using namespace Micro;

Engine::Engine()
{
    std::cout << "Initializing Micro Engine..." << std::endl;
    std::cout << "Version: " << version() << std::endl;

    int screenWidth = 800;
    int screenHeight = 450;

    m_Window.Init(screenWidth, screenHeight, "raylib-cpp - basic window");
    m_Window.SetTargetFPS(60);
}

int Engine::Run()
{
    while (!m_Window.ShouldClose())
    {
        m_Window.BeginDrawing();
        m_Window.ClearBackground(RAYWHITE);

        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        m_Window.EndDrawing();
    }

    return 0;
}