
#include "GUI_Manager/gui_element_mngr.hpp"

namespace GUI
{
    bool Cycle_True_False(float time_multiplier)
    {
        return static_cast<int>(ImGui::GetTime() * time_multiplier) % 2 == 0;
    }

    void Text(const Text_Data& data, const std::string& text)
    {
        if (data.text_type == "blinking" && !Cycle_True_False(data.blinking_speed))
            ImGui::Dummy({ImGui::CalcTextSize(text.c_str()).x, ImGui::GetTextLineHeight()});
        else
            ImGui::TextColored(data.text_color, "%s", text.c_str());
    }
}
