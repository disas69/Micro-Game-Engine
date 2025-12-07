#include "EditorApp.h"
#include "imgui.h"
#include "rlImGui.h"

using namespace Micro;

EditorApp::EditorApp()
{
    std::cout << "Editor App Initialized" << std::endl;

    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();

    m_window.SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE);
    m_window.Init(screenWidth, screenHeight, "Micro Engine");
    m_window.SetTargetFPS(60);

    rlImGuiSetup(true);
    ImGui::GetIO().ConfigWindowsMoveFromTitleBarOnly = true;
    ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_DockingEnable;
}

int EditorApp::Run()
{
    while (!m_window.ShouldClose())
    {
        m_window.BeginDrawing();
        m_window.ClearBackground(DARKGRAY);

        rlImGuiBegin();

        // if (ImGui::BeginMainMenuBar())
        // {
        //     if (ImGui::BeginMenu("File"))
        //     {
        //         if (ImGui::MenuItem("Open"))
        //         {
        //         }
        //
        //         if (ImGui::MenuItem("Quit"))
        //         {
        //             m_window.Close();
        //             return EXIT_SUCCESS;
        //         }
        //         ImGui::EndMenu();
        //     }
        //
        //     if (ImGui::BeginMenu("Window"))
        //     {
        //         if (ImGui::MenuItem("Demo"))
        //         {
        //             open = !open;
        //         }
        //         ImGui::EndMenu();
        //     }
        //
        //     ImGui::EndMainMenuBar();
        // }

        ImGui::DockSpaceOverViewport(0, ImGui::GetMainViewport(), ImGuiDockNodeFlags_PassthruCentralNode);
        ImGui::Begin("Scene");
        // Draw your scene, gizmos, etc.
        ImGui::End();

        ImGui::Begin("Project");
        ImGui::End();

        ImGui::Begin("Console");
        ImGui::End();

        ImGui::Begin("Inspector");
        ImGui::End();

        ImGui::Begin("Hierarchy");
        ImGui::End();

        rlImGuiEnd();
        m_window.EndDrawing();
    }

    rlImGuiShutdown();

    return 0;
}
