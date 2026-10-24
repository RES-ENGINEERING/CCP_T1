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



        ImGuiStyle& style = ImGui::GetStyle();
        ImVec4* colors = style.Colors;

        // Window and panel backgrounds
        colors[ImGuiCol_WindowBg]         = ImVec4(0.08f, 0.08f, 0.08f, 1.00f);
        colors[ImGuiCol_ChildBg]          = ImVec4(0.10f, 0.10f, 0.10f, 1.00f);
        colors[ImGuiCol_PopupBg]          = ImVec4(0.12f, 0.12f, 0.12f, 1.00f);

        // Headers
        colors[ImGuiCol_Header]           = ImVec4(0.00f, 0.35f, 0.50f, 1.00f);
        colors[ImGuiCol_HeaderHovered]    = ImVec4(0.00f, 0.50f, 0.70f, 1.00f);
        colors[ImGuiCol_HeaderActive]     = ImVec4(0.00f, 0.60f, 0.80f, 1.00f);

        // Buttons
        colors[ImGuiCol_Button]           = ImVec4(0.00f, 0.30f, 0.45f, 1.00f);
        colors[ImGuiCol_ButtonHovered]    = ImVec4(0.00f, 0.45f, 0.65f, 1.00f);
        colors[ImGuiCol_ButtonActive]     = ImVec4(0.00f, 0.55f, 0.75f, 1.00f);

        // Frames (checkboxes, input fields, etc.)
        colors[ImGuiCol_FrameBg]          = ImVec4(0.16f, 0.16f, 0.16f, 1.00f);
        colors[ImGuiCol_FrameBgHovered]   = ImVec4(0.22f, 0.22f, 0.22f, 1.00f);
        colors[ImGuiCol_FrameBgActive]    = ImVec4(0.28f, 0.28f, 0.28f, 1.00f);

        // Progress bars
        colors[ImGuiCol_PlotHistogram]    = ImVec4(0.00f, 0.75f, 1.00f, 1.00f);

        style.WindowRounding    = 5.0f;
        style.ChildRounding     = 3.0f;
        style.FrameRounding     = 3.0f;
        style.PopupRounding     = 3.0f;
        style.ScrollbarRounding = 3.0f;
        style.GrabRounding      = 3.0f;

        style.WindowPadding     = ImVec2(10.0f, 10.0f);
        style.FramePadding      = ImVec2(6.0f, 4.0f);
        style.ItemSpacing       = ImVec2(8.0f, 6.0f);



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