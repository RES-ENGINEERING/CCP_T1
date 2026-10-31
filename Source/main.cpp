// Header communication
#define GLFW_EXPOSE_NATIVE_WIN32

// External include
#include <imgui/imgui.h>
#include <imgui/backends/imgui_impl_glfw.h>
#include <imgui/backends/imgui_impl_opengl3.h>
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

// C++ include
#include <stdexcept>
#include <windows.h>
#include <print>
#include <dwmapi.h>

// Project include
#include "Window_Manager/window_mngr.hpp"
#include "GUI_Manager/gui_mngr.hpp"
#include "GUI_Code/Main_GUI/main_gui.hpp"
#include "Chrono_System/chrono_sys.hpp"


int main()
{

    Window window(1280, 720, "CCP_T1");

    HWND hwnd = glfwGetWin32Window(window.Get_Handle());

    COLORREF title_bar_color = RGB(20, 20, 20);
    COLORREF text_color = RGB(255, 255, 255);

    DwmSetWindowAttribute(hwnd, DWMWA_CAPTION_COLOR, &title_bar_color, sizeof(title_bar_color));
    DwmSetWindowAttribute(hwnd, DWMWA_TEXT_COLOR, &text_color, sizeof(text_color));

    if (!GUI::Initialize(window))
        return 1;

    glfwSwapInterval(1);
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    while (!window.Should_Close())
    {
        window.Poll_Events();
        glClear(GL_COLOR_BUFFER_BIT);


        GUI::Begin_Frame();
        GUI::Main_GUI::Render_Main_GUI();
        GUI::Render();

        
        window.Swap_Buffers();
    }

    GUI::Shutdown();

    return 0;
}
