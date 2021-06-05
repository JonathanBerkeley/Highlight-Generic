#include "pch.h"
#include "flashpoint.h"
#include "constants.h"

void Init(HMODULE hModule) {
    AllocConsole();
    freopen_s((FILE**)stdout, "CONOUT$", "w", stdout); // Redirect stdout & stderr to new console
    freopen_s((FILE**)stderr, "CONOUT$", "w", stderr);

    LPCWSTR title = L"Highlight";
    SetConsoleTitleW(title);
    std::cout << "Highlight injected" << std::endl;
    std::cout << "Version - " << HIGHLIGHT_VERSION << std::endl;

    LogicLoop(hModule);
}

void LogicLoop(HMODULE hModule) {
    std::cout << "\nHighlight's main loop has started" << std::endl;
    for (;;) {
        if (GetAsyncKeyState(VK_END)) {
            // Uninject
            std::cout << "If you can read this, an attempted uninjection probably failed" << std::endl;
            fclose(stdout);
            fclose(stderr);
            FreeConsole();
            FreeLibraryAndExitThread(hModule, 0x0);
            exit(0);
        }
        Sleep(300);
    }
    
}