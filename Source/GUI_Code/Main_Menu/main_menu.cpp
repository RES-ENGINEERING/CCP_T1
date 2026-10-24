// Header communication
#include "GUI_Manager/gui_mngr.hpp"

// External include
#include <imgui/imgui.h>

// C++ include
#include <string>

// Project include
#include "System_Information_Obtainer/sys_info_obtainer.hpp"



namespace GUI::Main_Menu
{
    static int amount = 50;
    static int poop_amount = 50;

    void Render_Main_Menu()
    {
        const auto ram_info = HW::Obtain_RAM_Info();
        const auto storage_info = HW::Obtain_Storage_Info(L"C:\\");
        
        static bool show_ccp_t1_panel_subwindow = true;
        static bool show_monitoring_panel_subwindow = true;
        static bool show_system_information_panel_subwindow = true;
        static bool show_notepad_panel_subwindow = true;

        static char notepad_text_buffer[16384] = "";
        static char notepad_directory_file_buffer[4096] = "";
        const std::string& notepad_directory_file_open = notepad_directory_file_buffer;



        // Subwindow 1
        ImGui::SetNextWindowPos(ImVec2(20.0f, 20.0f), ImGuiCond_FirstUseEver);
        ImGui::Begin("Subwindow Subcontrol Panel");
            ImGui::Checkbox("Show 'CCP_T1 Information Panel", &show_ccp_t1_panel_subwindow);
            ImGui::Checkbox("Show 'Monitoring Panel", &show_monitoring_panel_subwindow);
            ImGui::Checkbox("Show 'Notepad Panel", &show_notepad_panel_subwindow);
        ImGui::End();



        // Subwindow 2
        if (show_ccp_t1_panel_subwindow)
        {
            ImGui::SetNextWindowPos(ImVec2(400.0f, 20.0f), ImGuiCond_FirstUseEver);
            ImGui::Begin("Information Panel");

                ImGui::Text("Computer Control Panel Type I");
                ImGui::Text("Version: 0.1.0.0");
                if (ImGui::TreeNode("Conventions"))
                {
                    if (ImGui::TreeNode("Versioning Format"))
                    {
                        ImGui::Text("\t\t\tMAJOR:  >0<.0.0.0");
                        ImGui::Text("\t\t\tMINOR:  0.>0<.0.0");
                        ImGui::Text("\t\t\tHOTFIX: 0.0.>0<.0");
                        ImGui::Text("\t\t\tSTAGE:  0.0.0.>0<");

                        ImGui::Text("\t\t\tSTAGES:\n\t\t\t\t\t\t0: Prototype\n\t\t\t\t\t\t1: Release\n\t\t\t\t\t\t2: Playtest (Special release type)");

                        ImGui::TreePop();
                    }

                    ImGui::TreePop();
                }
            ImGui::End();
        }

        

        // Subwindow 3
        if (show_monitoring_panel_subwindow)
        {
            ImGui::SetNextWindowPos(ImVec2(20.0f, 20.0f), ImGuiCond_FirstUseEver);
            ImGui::Begin("Monitoring Panel");
                if (ImGui::CollapsingHeader("RAM"))
                {
                    ImGui::Text("Available RAM (GB): %.3f GB", ram_info.available_gb);
                    ImGui::Text("Physical RAM (GB): %.3f GB", ram_info.total_gb);
                    ImGui::SeparatorText("Binary GiB");
                    ImGui::Text("Available RAM (GiB): %.3f GiB", ram_info.available_gib);
                    ImGui::Text("Physical RAM (GiB): %.3f GiB", ram_info.total_gib);
                }

                if (ImGui::CollapsingHeader("Storage"))
                {
                    ImGui::Text("Total: %.2f GB", storage_info.total_gb);
                    ImGui::Text("Used: %.2f GB", storage_info.used_gb);
                    ImGui::Text("Available: %.2f GB", storage_info.available_gb);

                    const float storage_usage = storage_info.total_gb > 0.0
                        ? static_cast<float>(storage_info.used_gb / storage_info.total_gb)
                        : 0.0f;

                    ImGui::Text("Usage: %.2f %%", storage_usage * 100);

                    ImGui::ProgressBar(storage_usage, ImVec2(-1.0f, 0.0f));

                    ImGui::SeparatorText("Binary GiB");

                    ImGui::Text("Total: %.2f GiB", storage_info.total_gib);
                }
            ImGui::End();
        }



        // Subwindow 4
        if (show_notepad_panel_subwindow)
        {
            ImGui::SetNextWindowPos(ImVec2(400.0f, 200.0f), ImGuiCond_FirstUseEver);
            ImGui::Begin("Notepad Panel");

                ImGui::InputTextMultiline(
                    "##Notepad_Panel",
                    notepad_text_buffer,
                    sizeof(notepad_text_buffer),
                    ImVec2(-1.0f, -1.0f)
                );
                
            ImGui::End();
        }
    }
}