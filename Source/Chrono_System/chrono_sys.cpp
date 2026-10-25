// Header communication
#include "Chrono_System/chrono_sys.hpp"

// External include

// C++ include
#include <chrono>
#include <thread>
#include <stdexcept>

// Project include



namespace Chrono
{
    void Sleep(const std::string& time_unit = "seconds", int amount = 0)
    {
        if (amount <= 0) return;

        if (time_unit == "hours") std::this_thread::sleep_for(std::chrono::hours(amount));
        else if (time_unit == "minutes") std::this_thread::sleep_for(std::chrono::minutes(amount));
        else if (time_unit == "seconds") std::this_thread::sleep_for(std::chrono::seconds(amount));
        else if (time_unit == "milliseconds") std::this_thread::sleep_for(std::chrono::milliseconds(amount));
        else if (time_unit == "microseconds") std::this_thread::sleep_for(std::chrono::microseconds(amount));
        else if (time_unit == "nanoseconds") std::this_thread::sleep_for(std::chrono::nanoseconds(amount));
        else  throw std::invalid_argument("Unknown time unit: " + time_unit);
    }
}