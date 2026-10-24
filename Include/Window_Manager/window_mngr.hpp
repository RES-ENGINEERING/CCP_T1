// Header communication
#pragma once

// External include
#include <GLFW/glfw3.h>

// C++ include


// Project include



class Window
{
public:
    Window(int width, int height, const char* title);
    ~Window();

    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    bool Should_Close() const;
    void Poll_Events() const;
    void Swap_Buffers() const;

    GLFWwindow* Get_Handle() const;

private:
    GLFWwindow* handle = nullptr;
};
