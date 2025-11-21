#include <iostream>
#include <thread>
#include <csignal>

void on_interruption(int signal_value)
{
    if (signal_value == SIGINT)
    {
        std::cout << "Interrupted." << std::endl;
        std::exit(0); // Terminate the process to match .NET Core behavior on Unix systems
    }
}

int main()
{
    std::signal(SIGINT, on_interruption);

    int i = 0;
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << i++ << std::endl;
    }
}
