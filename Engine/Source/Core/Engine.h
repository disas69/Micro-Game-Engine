#pragma once

#include "EngineConfig.h"
#include "raylib-cpp.hpp"

namespace Micro
{
class Engine final
{
public:
    Engine();
    int Run();

    static constexpr std::string_view version()
    {
        return ENGINE_VERSION_STRING;
    }

private:
    raylib::Window m_window;
};
}