// buddha.cpp
// Fix "Entry Point Not Found (SteamUserStats)" in Sleeping Dogs: Definitive Edition

#include <windows.h>

extern "C" {
    __declspec(dllexport) bool __cdecl SteamUserStats() { return true; }
    __declspec(dllexport) bool __cdecl SteamAPI_Init() { return true; }
    __declspec(dllexport) void __cdecl SteamAPI_Shutdown() {}
    __declspec(dllexport) bool __cdecl SteamAPI_RestartAppIfNecessary() { return false; }
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID) {
    return TRUE;
}
