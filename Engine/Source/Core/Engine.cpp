#include "Engine.h"

using namespace Micro;

Engine::Engine()
{
    std::cout << "Initializing Micro Engine..." << std::endl;
    std::cout << "Version: " << version() << std::endl;

    int screenWidth = 800;
    int screenHeight = 450;

    m_window.SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE);
    m_window.Init(screenWidth, screenHeight, "raylib-cpp - basic window");
    m_window.SetTargetFPS(60);
}

int Engine::Run()
{
    while (!m_window.ShouldClose())
    {
        m_window.BeginDrawing();
        m_window.ClearBackground(RAYWHITE);

        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        m_window.EndDrawing();
    }

    return 0;
}