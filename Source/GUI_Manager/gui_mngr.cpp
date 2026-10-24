#include "GUI_Manager/gui_mngr.hpp"

// External include
#include <imgui/imgui.h>
#include <imgui/backends/imgui_impl_glfw.h>
#include <imgui/backends/imgui_impl_opengl3.h>

// Project include
#include "Window_Manager/window_mngr.hpp"

namespace GUI
{
    bool Initialize(Window& window)
    {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();

        ImGui::StyleColorsDark();

        GLFWwindow* handle = window.Get_Handle();

        if (handle == nullptr)
        {
            ImGui::DestroyContext();
            return false;
        }

        if (!ImGui_ImplGlfw_InitForOpenGL(handle, true))
        {
            ImGui::DestroyContext();
            return false;
        }

        if (!ImGui_ImplOpenGL3_Init("#version 330 core"))
        {
            ImGui_ImplGlfw_Shutdown();
            ImGui::DestroyContext();
            return false;
        }

        return true;
    }

    void Begin_Frame()
    {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
    }

    void Render()
    {
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());;
    }

    void End_Frame()
    {
        
    }

    void Shutdown()
    {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
    }
}