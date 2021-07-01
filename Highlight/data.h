#pragma once
#include "pch.h"

namespace data {

    // Used for looping, setting to false will deactivate continued module functionality
    extern bool running;

    namespace proc {
        // Windows
        extern HMODULE selfModule;
    }
    
    namespace input {
        // Hot-Keys
        const int8_t HK_MENU = VK_INSERT;
        const int8_t HK_UNLOAD = VK_END;

        const int8_t HK_Q = 0x51;
        const int8_t HK_E = 0x45;
        const int8_t HK_R = 0x52;
    }

    namespace offset {
    }
}