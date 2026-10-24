// Header communication
#pragma once

// External include


// C++ include


// Project include


class Window;

namespace GUI
{
    bool Initialize(Window& window);
    void Begin_Frame();
    void Render();
    void End_Frame();
    void Shutdown();
}