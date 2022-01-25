#include "pch.h"
#include "flashpoint.h"
#include "constants.h"
#include "data.h"

#include <vector>

using namespace data;

DWORD WINAPI Init(LPVOID lpParam) {
    // Redirect stdout & stderr to new console
    AllocConsole();
    freopen_s(reinterpret_cast<FILE**>(stdout), "CONOUT$", "w", stdout);
    freopen_s(reinterpret_cast<FILE**>(stderr), "CONOUT$", "w", stderr);

    // Set title to console and output info on DLL
    SetConsoleTitle(constants::DLL_NAME);
    std::wcout << constants::DLL_NAME << L" injected" << '\n';
    std::cout << "Version - " << constants::VERSION << '\n';

    LogicLoop();

    // ReSharper disable once CppZeroConstantCanBeReplacedWithNullptr
    return 0;
}

void RenameWindows(LPCWSTR lpString) {
    HWND window = nullptr;
    const auto pid = GetCurrentProcessId();
    do {
        window = FindWindowEx(
            nullptr,
            window,
            nullptr,
            nullptr
        );
        DWORD check_pid = 0;
        GetWindowThreadProcessId(window, &check_pid);

        if (check_pid == pid) SetWindowText(window, lpString);
    }
	while (window != nullptr);
}

void LogicLoop() {
    std::wcout << '\n' << constants::DLL_NAME << L"'s main loop has started" << '\n';
    auto progress = 0u;

    // Main Logic Loop
    while (running) {
        if (GetAsyncKeyState(input::HK_UNLOAD) & 1) {
            // Uninject
            fclose(stdout);
            fclose(stderr);
            FreeConsole();
            FreeLibraryAndExitThread(proc::self_module, 0x0);
        }

        progress++;
        if (progress > constants::HIJACK_TEXT.length()) progress = 0u;

        RenameWindows(constants::HIJACK_TEXT.substr(0, progress).c_str());

        Sleep(300);
    }
}