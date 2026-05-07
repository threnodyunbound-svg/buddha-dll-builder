// steam_api64_stub.cpp
// Compile as steam_api64.dll – a stub to fix "Entry Point Not Found" errors in Sleeping Dogs DE

#include <windows.h>

// List of functions the game might import.
// Windows .def file or __declspec(dllexport) both work; we'll use __declspec(dllexport).

extern "C" {
    // --- SteamAPI ---
    __declspec(dllexport) bool __cdecl SteamAPI_Init() { return true; }
    __declspec(dllexport) void __cdecl SteamAPI_Shutdown() {}
    __declspec(dllexport) bool __cdecl SteamAPI_IsSteamRunning() { return true; }
    __declspec(dllexport) bool __cdecl SteamAPI_RestartAppIfNecessary() { return false; }

    // --- SteamUserStats ---
    __declspec(dllexport) bool __cdecl SteamUserStats() { return true; }
    __declspec(dllexport) bool __cdecl SteamUserStats_RequestCurrentStats() { return true; }
    __declspec(dllexport) bool __cdecl SteamUserStats_StoreStats() { return true; }
    __declspec(dllexport) int  __cdecl SteamUserStats_GetStatInt(const char*, int*) { return 1; }
    __declspec(dllexport) bool __cdecl SteamUserStats_SetStat(const char*, int) { return true; }
    __declspec(dllexport) bool __cdecl SteamUserStats_GetAchievement(const char*, bool*) {
        static bool achieved = false;
        return false;
    }
    __declspec(dllexport) bool __cdecl SteamUserStats_SetAchievement(const char*) { return true; }
    __declspec(dllexport) bool __cdecl SteamUserStats_ClearAchievement(const char*) { return true; }

    // --- SteamFriends ---
    __declspec(dllexport) const char* __cdecl SteamFriends_GetPersonaName() { return "Player"; }

    // --- SteamRemoteStorage ---
    __declspec(dllexport) bool __cdecl SteamRemoteStorage_IsCloudEnabledForApp() { return false; }
    __declspec(dllexport) bool __cdecl SteamRemoteStorage_IsCloudEnabledForAccount() { return false; }

    // --- SteamUtils ---
    __declspec(dllexport) bool __cdecl SteamUtils_IsOverlayEnabled() { return true; }

    // --- SteamUser ---
    __declspec(dllexport) bool __cdecl SteamUser_BLoggedOn() { return true; }

    // A few more functions that sometimes cause issues
    __declspec(dllexport) void* __cdecl SteamInternal_ContextInit(void*) { return 0; }
    __declspec(dllexport) void* __cdecl SteamAPI_GetHSteamPipe() { return 0; }
    __declspec(dllexport) void* __cdecl SteamAPI_GetHSteamUser() { return 0; }
    __declspec(dllexport) void* __cdecl SteamClient() { return 0; }
    __declspec(dllexport) void* __cdecl SteamAPI_SteamUser() { return 0; }
    __declspec(dllexport) void* __cdecl SteamAPI_SteamFriends() { return 0; }
    __declspec(dllexport) void* __cdecl SteamAPI_SteamUtils() { return 0; }
    __declspec(dllexport) void* __cdecl SteamAPI_SteamUserStats() { return 0; }
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID) {
    return TRUE;
}
