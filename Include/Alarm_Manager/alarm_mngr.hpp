// Header communication
#pragma once

// External include
#include <imgui/imgui.h>

// C++ include
#include <string>
#include <vector>

// Project include
#include "GUI_Manager/gui_element_mngr.hpp"


namespace GUI
{
    struct Alarm
    {
        std::string message;
        Text_Data text_data;
    };

    inline std::vector<Alarm> alarms;

    void Add_Alarm(const std::string& message, const Text_Data& text_data);
}
