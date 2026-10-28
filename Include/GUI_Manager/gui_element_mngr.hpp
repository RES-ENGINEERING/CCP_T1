// Header communication
#pragma once

// External include
#include <imgui/imgui.h>

// C++ include
#include <string>


// Project include


namespace GUI
{
    struct Text_Data
    {
        std::string text_type = "default";
        ImVec4 text_color = {1, 1, 1, 1};
        float blinking_speed = 1.0f;
    };
    
    bool Cycle_True_False(float time_multiplier);
    
    void Text(const std::string& text, const Text_Data& data);
    void Text(const std::string& text, const Text_Data& data, const ImVec4& text_color);
}