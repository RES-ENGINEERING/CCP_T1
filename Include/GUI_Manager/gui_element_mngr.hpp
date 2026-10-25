// Header communication
#pragma once

// External include
#include <imgui/imgui.h>

// C++ include
#include <string>


// Project include


namespace GUI
{
    bool Cycle_Blink(float time_multiplier);
    void Blinking_Text(const std::string& blinking_type, const ImVec4& text_color, const char* text, float blinking_speed);
}