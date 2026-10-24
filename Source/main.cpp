
 // Header communication


// External include
#include <imgui/imgui.h>
#include <imgui/backends/imgui_impl_glfw.h>
#include <imgui/backends/imgui_impl_opengl3.h>
#include <GLFW/glfw3.h>

// C++ include
#include <stdexcept>
#include <windows.h>
#include <print>

// Project include
#include "Window_Manager/window_mngr.hpp"
#include "GUI_Manager/gui_mngr.hpp"
#include "GUI_Code/Main_Menu/main_menu.hpp"


int main()
{

    Window window(1280, 720, "CCP_T1");

    if (!GUI::Initialize(window))
        return 1;

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    while (!window.Should_Close())
    {
        window.Poll_Events();
        glClear(GL_COLOR_BUFFER_BIT);


        GUI::Begin_Frame();
        GUI::Main_Menu::Render_Main_Menu();
        GUI::Render();

        
        window.Swap_Buffers();
    }

    GUI::Shutdown();

    return 0;
}
