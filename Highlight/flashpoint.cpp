#include "pch.h"
#include "flashpoint.h"
#include "constants.h"

void Init(HMODULE selfModule) {
    // Redirect stdout & stderr to new console
    AllocConsole();
    freopen_s((FILE**)stdout, "CONOUT$", "w", stdout); 
    freopen_s((FILE**)stderr, "CONOUT$", "w", stderr);

    // Set title to console and output info on DLL
    SetConsoleTitleW(DLL_NAME);
    std::wcout << DLL_NAME << L" injected" << '\n';
    std::cout << "Version - " << VERSION << '\n';
    
    std::wcout << '\n' << DLL_NAME << L"'s main loop has started" << '\n';
    LogicLoop(selfModule);
}

void LogicLoop(HMODULE selfModule) {
    // Main Logic Loop
    for (;;) {
        if (GetAsyncKeyState(VK_END) & 1) {
            // Uninject
            fclose(stdout);
            fclose(stderr);
            FreeConsole();
            FreeLibraryAndExitThread(selfModule, 0x0);
        }
        Sleep(1);
    }
}