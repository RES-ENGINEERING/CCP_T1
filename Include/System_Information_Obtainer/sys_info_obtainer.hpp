// Header communication

// External include

// C++ include
#include <windows.h>

// Project include


namespace HW
{
    struct RAM_Info
    {
        double total_gb;
        double used_gb;
        double available_gb;
        DWORD memory_load;
        double total_gib;
        double used_gib;
        double available_gib;
    };

    struct Storage_Info
    {
        double total_gb;
        double used_gb;
        double available_gb;
        double total_gib;
        double used_gib;
        double available_gib;
    };

    RAM_Info Obtain_RAM_Info();
    Storage_Info Obtain_Storage_Info(const wchar_t* drive);
}