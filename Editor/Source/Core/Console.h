#pragma once

#include <vector>
#include <string>

namespace Micro
{
struct LogEntry
{
    int Level;
    std::string Text;
};

class Console
{
public:
    static Console& Get()
    {
        static Console Instance;
        return Instance;
    }

    Console(const Console&) = delete;
    Console(Console&&) = delete;
    Console& operator=(const Console&) = delete;
    Console& operator=(Console&&) = delete;

    std::vector<LogEntry> GetEntries() const { return m_entries; }
    bool ShouldScrollToBottom() const { return m_scrollToBottom; }

    void Initialize();
    void AddLog(int level, const std::string& text);
    void Clear();
    void ResetAutoScroll();

private:
    std::vector<LogEntry> m_entries = {};
    bool m_scrollToBottom = false;

    Console() = default;
};
}  // namespace Micro
