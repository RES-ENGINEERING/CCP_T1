// Header communication
#pragma once

// External include
#include <imgui/imgui.h>

// C++ include
#include <string>
#include <format>

// Project include
#include "Timestamp_System/timestamp_sys.hpp"


namespace Format
{
    std::string Format_Timestamp_Message(const std::string& message);
    ImVec4 Format_ImGui_Vector_4(const std::string& color_name);
}