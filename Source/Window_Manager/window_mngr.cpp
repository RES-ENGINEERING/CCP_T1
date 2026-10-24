// Header communication
#include "Window_Manager/window_mngr.hpp"

// External include


// C++ include
#include <stdexcept>

// Project include




Window::Window(int width, int height, const char* title)
{
    if (!glfwInit())
        throw std::runtime_error("Failed to initialize GLFW.");

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    handle = glfwCreateWindow(
        width,
        height,
        title,
        nullptr,
        nullptr
    );

    if (handle == nullptr)
    {
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window.");
    }

    glfwMakeContextCurrent(handle);
    glfwSwapInterval(1);
}

Window::~Window()
{
    if (handle != nullptr)
        glfwDestroyWindow(handle);

    glfwTerminate();
}

bool Window::Should_Close() const
{
    return glfwWindowShouldClose(handle);
}

void Window::Poll_Events() const
{
    glfwPollEvents();
}

void Window::Swap_Buffers() const
{
    glfwSwapBuffers(handle);
}

GLFWwindow* Window::Get_Handle() const
{
    return handle;
}
