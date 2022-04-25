#pragma once
#include "pch.hpp"

namespace constants {
    const LPCWSTR DLL_NAME { L"Generic" };
    const std::string VERSION { "0.0.8" };
    const std::wstring HIJACK_TEXT { L"Process hijacked" };
    static constexpr bool DBG = true;
}
