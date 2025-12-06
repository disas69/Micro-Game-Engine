#pragma once

#include "raylib-cpp.hpp"

namespace Micro
{
class EditorApp
{
public:
    EditorApp();
    int Run();

private:
    raylib::Window m_window;
};
}  // namespace Micro