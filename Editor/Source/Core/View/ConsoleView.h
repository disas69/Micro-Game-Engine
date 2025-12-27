#pragma once

#include "Core/Log.h"

namespace Micro
{
class ConsoleView
{
public:
    ConsoleView() = default;
    ConsoleView(const ConsoleView&) = delete;
    ConsoleView& operator=(const ConsoleView&) = delete;

    void Render();

private:
    static bool CheckboxLogLevelFlags(const char* label, LogLevelFlags* flags, LogLevelFlags flag);
};
}  // namespace Micro
