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

    Storage_Info Obtain_Storage_Info(const wchar_t* drive)
    {
        ULARGE_INTEGER available_bytes{};
        ULARGE_INTEGER total_bytes{};
        ULARGE_INTEGER free_bytes{};

        if (!GetDiskFreeSpaceExW(
            drive,
            &available_bytes,
            &total_bytes,
            &free_bytes))
        {
            return {};
        }

        constexpr double bytes_per_gb = 1'000'000'000.0;
        constexpr double bytes_per_gib = 1'073'741'824.0;

        const double total = static_cast<double>(total_bytes.QuadPart);
        const double available = static_cast<double>(available_bytes.QuadPart);
        const double used = total - static_cast<double>(free_bytes.QuadPart);

        return {
            total / bytes_per_gb,
            used / bytes_per_gb,
            available / bytes_per_gb,
            total / bytes_per_gib,
            used / bytes_per_gib,
            available / bytes_per_gib
        };
    }

    CPU_Info Obtain_CPU_Info()
    {
        static ULONGLONG previous_idle = 0;
        static ULONGLONG previous_kernel = 0;
        static ULONGLONG previous_user = 0;
        static bool initialized = false;

        FILETIME idle_time{};
        FILETIME kernel_time{};
        FILETIME user_time{};

        SYSTEM_INFO system_info{};
        GetSystemInfo(&system_info);

        if (!GetSystemTimes(
            &idle_time,
            &kernel_time,
            &user_time))
        {
            return {};
        }

        const auto to_uint64 = [](const FILETIME& time) -> ULONGLONG
        {
            return (static_cast<ULONGLONG>(time.dwHighDateTime) << 32)
                | time.dwLowDateTime;
        };

        const ULONGLONG idle = to_uint64(idle_time);
        const ULONGLONG kernel = to_uint64(kernel_time);
        const ULONGLONG user = to_uint64(user_time);

        CPU_Info info{};
        info.logical_processors = system_info.dwNumberOfProcessors;

        if (!initialized)
        {
            previous_idle = idle;
            previous_kernel = kernel;
            previous_user = user;
            initialized = true;

            return info;
        }

        const ULONGLONG idle_delta = idle - previous_idle;
        const ULONGLONG kernel_delta = kernel - previous_kernel;
        const ULONGLONG user_delta = user - previous_user;

        const ULONGLONG total_delta = kernel_delta + user_delta;

        if (total_delta > 0)
        {
            info.usage_percent =
                100.0 * static_cast<double>(total_delta - idle_delta)
                / static_cast<double>(total_delta);
        }

        previous_idle = idle;
        previous_kernel = kernel;
        previous_user = user;

        return info;
    }
}