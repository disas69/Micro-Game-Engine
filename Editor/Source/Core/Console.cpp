#include "Console.h"

#include "raylib.h"

using namespace Micro;

void ConsoleTraceLogCallback(int logLevel, const char* text, va_list args)
{
    char buffer[1024];
    vsnprintf(buffer, sizeof(buffer), text, args);
    Console::Get().AddLog(logLevel, buffer);
}

void Console::Initialize()
{
    SetTraceLogCallback(ConsoleTraceLogCallback);
}

void Console::AddLog(int level, const std::string& text)
{
    m_entries.emplace_back(LogEntry{level, text});
    m_scrollToBottom = true;
}

void Console::Clear()
{
    m_entries.clear();
}

void Console::ResetAutoScroll()
{
    m_scrollToBottom = false;
}