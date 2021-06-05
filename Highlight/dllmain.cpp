// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "flashpoint.h"
#include <iostream>

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
    if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
        HANDLE thread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Init, NULL, 0, NULL);

        if (thread != 0)
            CloseHandle(thread);
    }
    else {
        return FALSE;
    }
    return TRUE;
}

