// Header communication
#include "System_Information_Obtainer/sys_info_obtainer.hpp"

// External include

// C++ include
#include <windows.h>
#include <print>

// Project include


namespace HW
{
    RAM_Info Obtain_RAM_Info()
    {
        MEMORYSTATUSEX memory_status{};
        memory_status.dwLength = sizeof(memory_status);

        if (!GlobalMemoryStatusEx(&memory_status))
        {
            return {};
        }

        std::println("Physical RAM: {} bytes", memory_status.ullTotalPhys);
        std::println("Commit limit: {} bytes", memory_status.ullTotalPageFile);
        std::println("Available physical RAM: {} bytes", memory_status.ullAvailPhys);

        constexpr double bytes_per_gb = 1'000'000'000.0;
        constexpr double bytes_per_gib = 1'073'741'824.0;

        const double total_gb =
            static_cast<double>(memory_status.ullTotalPhys) / bytes_per_gb;

        const double available_gb =
            static_cast<double>(memory_status.ullAvailPhys) / bytes_per_gb;

        const double total_gib =
            static_cast<double>(memory_status.ullTotalPhys) / bytes_per_gib;

        const double available_gib =
            static_cast<double>(memory_status.ullAvailPhys) / bytes_per_gib;

        return {
            total_gb,
            total_gb - available_gb,
            available_gb,
            memory_status.dwMemoryLoad,
            total_gib,
            total_gib - available_gib,
            available_gib
        };
    }
}