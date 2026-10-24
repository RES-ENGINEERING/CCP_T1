// Header communication
#include "GUI_Manager/gui_mngr.hpp"

// External include
#include <imgui/imgui.h>

// C++ include


// Project include
#include "System_Information_Obtainer/sys_info_obtainer.hpp"




namespace GUI::Main_Menu
{
    static int amount = 50;
    static int poop_amount = 50;

    void Render_Main_Menu()
    {
        const auto ram_info = HW::Obtain_RAM_Info();

        // Subwindow 1
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

        ImGui::Begin("Monitoring Panel");
            if (ImGui::TreeNode("RAM"))
            {
                ImGui::Text("Available RAM (GB): %.3f GB", ram_info.available_gb);
                ImGui::Text("Physical RAM (GB): %.3f GB", ram_info.total_gb);
                ImGui::SeparatorText("Binary GiB");
                ImGui::Text("Available RAM (GiB): %.3f GiB", ram_info.available_gib);
                ImGui::Text("Physical RAM (GiB): %.3f GiB", ram_info.total_gib);

                ImGui::TreePop();
            }
            
        ImGui::End();
    }
}
