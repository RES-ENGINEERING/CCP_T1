// Header communication
#include "Text_Format_System/text_format_sys.hpp"

// External include

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
}