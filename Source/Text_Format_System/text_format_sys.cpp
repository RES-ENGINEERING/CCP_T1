// Header communication
#include "Text_Format_System/text_format_sys.hpp"

// External include
#include <imgui/imgui.h>

// C++ include
#include <string>
#include <format>

// Project include
#include "Timestamp_System/timestamp_sys.hpp"


namespace Format
{
    std::string Format_Timestamp_Message(const std::string& message)
    {
        static const auto timestamp = Time::Get_Current_System_Clock_Time();
        return std::format("[{}]: {}", timestamp, message);
    }

    ImVec4 Format_ImGui_Vector_4(const std::string& color_name){
        if (color_name == "red") return {1, 0, 0, 1};
        if (color_name == "blue") return {0, 0, 1, 1};
        if (color_name == "green") return {0, 1, 0, 1};
        if (color_name == "yellow") return {1, 1, 0, 1};

        if (color_name == "light_red") return {1, 0.5, 0.5, 1};
        if (color_name == "light_blue") return {0, 0.5, 1, 1};

        if (color_name == "dark_red") return {1, 0, 0, 0.5};
        if (color_name == "dark_blue") return {0, 0, 1, 0.5};
        if (color_name == "dark_green") return {0, 1, 0, 0.5};
        if (color_name == "dark_yellow") return {1, 1, 0, 0.5};

        if (color_name == "pink") return {1, 0.7, 0.8, 1};
        
        else return {1, 1, 1, 1};
    }
}