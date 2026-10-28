// Header communication
#include "GUI_Manager/gui_mngr.hpp"

// External include
#include <imgui/imgui.h>

// C++ include
#include <string>
#include <format>

// Project include
#include "System_Information_Obtainer/sys_info_obtainer.hpp"
#include "GUI_Manager/gui_element_mngr.hpp"
#include "Timestamp_System/timestamp_sys.hpp"
#include "Chrono_System/chrono_sys.hpp"
#include "Text_Format_System/text_format_sys.hpp"
#include "Alarm_Manager/alarm_mngr.hpp"


namespace GUI::Main_Menu
{
    /* Prototype. Do not remove.
    static int amount = 50;
    static int poop_amount = 50;
    */
    

    void Render_Main_Menu()
    {
        static auto ram_info = HW::Obtain_RAM_Info();
        static auto storage_info = HW::Obtain_Storage_Info(L"C:\\");

        static auto last_update = std::chrono::steady_clock::now();
        const auto current_time = std::chrono::steady_clock::now();

        if (current_time - last_update >= std::chrono::seconds(1))
        {
            ram_info = HW::Obtain_RAM_Info();
            storage_info = HW::Obtain_Storage_Info(L"C:\\");

            last_update = current_time;
        }

        static auto timestamp = Time::Get_Current_System_Clock_Time();
        
        static bool show_ccp_t1_panel_subwindow = true;
        static bool show_monitoring_panel_subwindow = true;
        static bool show_system_information_panel_subwindow = true;
        static bool show_notepad_panel_subwindow = true;
        static bool show_alarm_and_indicator_panel_subwindow = true;

        static char notepad_text_buffer[16384] = "";

        static Text_Data text_data_information;
            text_data_information.text_type = "blinking";
            text_data_information.blinking_speed = 1;
            text_data_information.text_color = Format::Format_ImGui_Vector_4("light_blue");
        static Text_Data text_data_warning;
            text_data_warning.text_type = "blinking";
            text_data_warning.blinking_speed = 4;
            text_data_warning.text_color = Format::Format_ImGui_Vector_4("yellow");
        static Text_Data text_data_critical;
            text_data_critical.text_type = "blinking";
            text_data_critical.blinking_speed = 7;
            text_data_critical.text_color = Format::Format_ImGui_Vector_4("red");
        static Text_Data text_data_default;
            text_data_default.text_type = "default";

            

        // Subwindow 1
        ImGui::SetNextWindowPos(ImVec2(20, 20), ImGuiCond_FirstUseEver);
        ImGui::Begin("Subwindow Subcontrol Panel");
            ImGui::Checkbox("Show 'CCP_T1 Information Panel", &show_ccp_t1_panel_subwindow);
            ImGui::Checkbox("Show 'Monitoring Panel", &show_monitoring_panel_subwindow);
            ImGui::Checkbox("Show 'Notepad Panel", &show_notepad_panel_subwindow);
            ImGui::Checkbox("Show 'Alarm Panel", &show_alarm_and_indicator_panel_subwindow);
        ImGui::End();



        // Subwindow 2
        if (show_ccp_t1_panel_subwindow)
        {
            ImGui::SetNextWindowPos(ImVec2(400, 20), ImGuiCond_FirstUseEver);
            ImGui::Begin("Information Panel");

                ImGui::Text("Computer Control Panel Type I");
                ImGui::Text("Version: 0.7.0.0");
                if (ImGui::TreeNode("Conventions"))
                {
                    if (ImGui::TreeNode("Versioning Format"))
                    {
                        ImGui::Text("\t\t\tMAJOR:  >0<.0.0.0");
                        ImGui::Text("\t\t\tMINOR:  0.>0<.0.0");
                        ImGui::Text("\t\t\tHOTFIX: 0.0.>0<.0");
                        ImGui::Text("\t\t\tSTAGE:  0.0.0.>0<");

                        ImGui::Text("\t\t\tSTAGES:\n\t\t\t\t\t\t0: Prototype\n\t\t\t\t\t\t1: Release\n\t\t\t\t\t\t2: Playtest (Special release type)");

                        ImGui::Text("\t\t\t The 'HOTFIX' number resets\n\t\t\t per minor version.\n\t\t\t Same goes for the 'Minor' number.");

                        ImGui::TreePop();
                    }

                    ImGui::TreePop();
                }
                GUI::Text("Special thanks to: ", text_data_default, Format::Format_ImGui_Vector_4("pink"));
                ImGui::SameLine();
                GUI::Text("GLFW, ", text_data_default, Format::Format_ImGui_Vector_4("blue"));
                ImGui::SameLine();
                GUI::Text("ImGui!", text_data_default, Format::Format_ImGui_Vector_4("yellow"));
            ImGui::End();
        }

        

        // Subwindow 3
        if (show_monitoring_panel_subwindow)
        {
            ImGui::SetNextWindowPos(ImVec2(20, 20), ImGuiCond_FirstUseEver);
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

                    const float storage_usage = storage_info.total_gb > 0 ? static_cast<float>(storage_info.used_gb / storage_info.total_gb) : 0;

                    ImGui::Text("Usage: %.2f %%", storage_usage * 100);
                    ImGui::ProgressBar(storage_usage, ImVec2(-1, 0));

                    ImGui::SeparatorText("Binary GiB");

                    ImGui::Text("Total: %.2f GiB", storage_info.total_gib);
                    ImGui::Text("Used: %.2f GiB", storage_info.used_gib);
                    ImGui::Text("Available: %.2f GiB", storage_info.available_gib);
                }
            ImGui::End();
        }



        // Subwindow 4
        if (show_notepad_panel_subwindow)
        {
            ImGui::SetNextWindowPos(ImVec2(400, 200), ImGuiCond_FirstUseEver);
            ImGui::Begin("Notepad Panel");
                ImGui::InputTextMultiline(
                    "##Notepad_Panel",
                    notepad_text_buffer,
                    sizeof(notepad_text_buffer),
                    ImVec2(-1, -1)
                );
            ImGui::End();
        }



        // Subwindow 5
        if (show_alarm_and_indicator_panel_subwindow)
        {
            ImGui::SetNextWindowPos({400, 200}, ImGuiCond_FirstUseEver);
            ImGui::Begin("Alarm/Indicator Panel");
                ImGui::BeginChild("Information", {225, 225}, true);
                    GUI::Text("INFORMATION", text_data_default, Format::Format_ImGui_Vector_4("dark_blue"));
                    ImGui::Separator();
                    for (const auto& alarm : GUI::alarms)
                    {
                        if (alarm.text_data.blinking_speed == 1) GUI::Text(alarm.message, alarm.text_data);
                    }
                ImGui::EndChild();

                ImGui::SameLine();

                ImGui::BeginChild("Warning", {225, 225}, true);
                    GUI::Text("WARNING", text_data_default, Format::Format_ImGui_Vector_4("dark_yellow"));
                    ImGui::Separator();
                    for (const auto& alarm : GUI::alarms)
                    {
                        if (alarm.text_data.blinking_speed == 4) GUI::Text(alarm.message, alarm.text_data);
                    }
                ImGui::EndChild();

                ImGui::SameLine();

                ImGui::BeginChild("Critical", {225, 225}, true);
                    GUI::Text("CRITICAL", text_data_default, Format::Format_ImGui_Vector_4("dark_red"));
                    ImGui::Separator();
                    for (const auto& alarm : GUI::alarms)
                    {
                        if (alarm.text_data.blinking_speed == 7) GUI::Text(alarm.message, alarm.text_data);
                    }
                ImGui::EndChild();
            ImGui::End();
        }
    }
}