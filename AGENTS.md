# AI Agent Coding Guidelines - MicroEngine

This document provides instructions and guidelines for AI agents working on the MicroEngine project. MicroEngine is a custom C++ game engine built on top of [raylib](https://www.raylib.com/), with an editor UI powered by [ImGui](https://github.com/ocornut/imgui).

## Project Overview

- **Engine Core**: Located in `Engine/Source/Core`.
- **Editor**: Located in `Editor/Source`, uses ImGui and `rlImGui`.
- **Games**: Example games are in the `Games/` directory.
- **Dependencies**: Managed via CMake (raylib, imgui, rlImGui, tinyfiledialogs).

## Tech Stack

- **Language**: C++17 (or newer as per CMake configuration).
- **Graphics**: raylib (via `raylib-cpp` wrappers where applicable).
- **UI**: ImGui for Editor tools.
- **Build System**: CMake.

## Code Style & Conventions

- **Namespace**: All engine code should reside within the `Micro` namespace.
- **Naming Conventions**:
    - **Classes/Structs**: `PascalCase` (e.g., `ArenaAllocator`).
    - **Methods/Functions**: `PascalCase` (e.g., `OnInit`, `Update`).
    - **Member Variables**: `m_` prefix followed by `camelCase` (e.g., `m_windowTitle`, `m_persistentArena`).
    - **Local Variables**: `camelCase` (e.g., `screenWidth`).
    - **Constants/Macros**: `UPPER_SNAKE_CASE` (e.g., `DEFAULT_EDITOR_SCREEN_WIDTH`).
- **Files**: Use `.h` for headers and `.cpp` for implementations. Use `#pragma once` in headers.
- **Includes**:
    - Prefer `#include "Path/To/Header.h"` for internal engine files.
    - Use `<system_header>` or library headers (e.g., `<raylib.h>`) appropriately.

## Architectural Patterns

### 1. Memory Management (Arena Allocation)
MicroEngine emphasizes the use of `ArenaAllocator` for memory management to minimize fragmentation and improve performance.
- **Persistent Arena**: For data that lives as long as the game/engine.
- **Frame Arena**: For temporary data that is reset every frame.
- **Avoid**: Raw `new` and `delete` where possible. Use `arena.Allocate<T>(args...)` instead.

### 2. Engine Loop & Game Base
Games should inherit from `Micro::GameBase` and implement:
- `OnInit()`: Initialization logic.
- `Update(ArenaAllocator& frameArena, float deltaTime)`: Logic updates, using the provided `frameArena` for temporary allocations.
- `Render()`: raylib drawing commands.

### 3. Logging
Use the provided logging macros:
- `MICRO_LOG_INFO(msg)`
- `MICRO_LOG_WARNING(msg)`
- `MICRO_LOG_ERROR(msg)`
- `MICRO_LOG_FATAL(msg)`

### 4. Editor Development
- The editor uses a docking layout.
- New editor windows should be added to `EditorApp::DrawMainViewport`.
- Use `rlImGui` functions to bridge raylib and ImGui (e.g., `rlImGuiImageRenderTextureFit`).

## Workflow for Agents

1.  **Analyze**: Before making changes, explore the existing class hierarchy and memory usage patterns.
2.  **Memory First**: When adding new systems, consider how they will be allocated. Prefer `ArenaAllocator`.
3.  **Style Match**: Ensure new code matches the exact style of the file it's being added to.
4.  **CMake**: If adding new files, remember to update the corresponding `CMakeLists.txt`.
5.  **Headers**: Keep headers clean. Use forward declarations where possible to reduce compilation times.
