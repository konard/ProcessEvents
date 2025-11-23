#include <iostream>
#include <thread>
#include <csignal>

// SIGBREAK is only available on Windows
#ifndef SIGBREAK
    #ifdef _WIN32
        // Should be defined by the system on Windows
    #else
        // On Unix/Linux, SIGBREAK (CTRL+Break) does not exist.
        // This is a placeholder to make the code compile.
        // The functionality will not work on Unix systems.
        #define SIGBREAK 21
    #endif
#endif

void on_break(int signal_value)
{
    if (signal_value == SIGBREAK)
    {
        std::signal(SIGBREAK, on_break);
        std::cout << "Break cancelled." << std::endl;
    }
}

int main()
{
#ifdef _WIN32
    std::signal(SIGBREAK, on_break);
    std::cout << "Break event handler registered (Windows only - use CTRL+Break)." << std::endl;
#else
    std::cout << "Warning: SIGBREAK is not supported on this platform. This functionality is Windows-only." << std::endl;
#endif

    int i = 0;
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << i++ << std::endl;
    }
}
