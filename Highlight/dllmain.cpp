#include "pch.h"
#include "flashpoint.h"

// Entry point for the application
BOOL APIENTRY DllMain(HMODULE selfModule, DWORD callReason, LPVOID lpReserved) {
    if (callReason == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(selfModule);

        HANDLE thread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Init, selfModule, 0, NULL);
        if (thread != 0)
            CloseHandle(thread);
    }
    return TRUE;
}