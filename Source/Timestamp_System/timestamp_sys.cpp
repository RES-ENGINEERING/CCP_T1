#include "Timestamp_System/timestamp_sys.hpp"

#include <chrono>
#include <ctime>
#include <format>

namespace Time
{
    std::string Get_Current_System_Clock_Time()
    {
        const auto now = std::chrono::system_clock::now();
        const std::time_t time = std::chrono::system_clock::to_time_t(now);

        std::tm local_time{};

        #ifdef _WIN32
            localtime_s(&local_time, &time);
        #elif defined(__unix__) || defined(__APPLE__)
            localtime_r(&time, &local_time);
        #else
            #error Unsupported operating system
        #endif

        return std::format(
            "{:02}:{:02}:{:02}",
            local_time.tm_hour,
            local_time.tm_min,
            local_time.tm_sec
        );
    }
}