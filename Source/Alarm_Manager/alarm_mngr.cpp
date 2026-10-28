// Header communication
#include "Alarm_Manager/alarm_mngr.hpp"

// External include
#include <imgui/imgui.h>

// C++ include
#include <string>
#include <vector>

// Project include
#include "GUI_Manager/gui_element_mngr.hpp"


namespace GUI
{
    void Add_Alarm(const std::string& message, const Text_Data& text_data)
    {
        alarms.push_back({message, text_data});
    }
}
