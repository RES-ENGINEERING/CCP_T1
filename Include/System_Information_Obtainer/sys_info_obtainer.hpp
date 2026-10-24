 // Header communication
#pragma once

// External include

// C++ include

// Project include


namespace HW
{
    struct RAM_Info
    {
        double total_gb;
        double used_gb;
        double available_gb;
        unsigned long usage_percentage;

        double total_gib;
        double used_gib;
        double available_gib;
    };

    RAM_Info Obtain_RAM_Info();

    struct Storage_Info
    {
        double total_gb{};
        double used_gb{};
        double available_gb{};

        double total_gib{};
        double used_gib{};
        double available_gib{};
    };

    Storage_Info Obtain_Storage_Info(const wchar_t* drive);
}
