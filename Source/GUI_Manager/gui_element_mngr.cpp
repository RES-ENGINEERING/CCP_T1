
#include "GUI_Manager/gui_element_mngr.hpp"

namespace GUI
{
    bool Cycle_Blink(float time_multiplier)
    {
        return static_cast<int>(ImGui::GetTime() * time_multiplier) % 2 == 0;
    }

    void Blinking_Text(const std::string& blinking_type, const ImVec4& text_color, const char* text, float blinking_speed)
    {
        if (blinking_type == "flashing")
        {
            if (Cycle_Blink(blinking_speed))
            {
                ImGui::TextColored(text_color, "%s", text);
            }
            else
            {
                ImGui::Dummy(ImVec2(
                    ImGui::CalcTextSize("%s", text).x,
                    ImGui::GetTextLineHeight()
                ));
            }
        }
        else
        {
            ImGui::TextColored(text_color, "%s", text);
        }
    }
}
