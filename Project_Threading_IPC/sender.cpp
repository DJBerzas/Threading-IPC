#include <iostream>
#include <fstream>
#include <unistd.h>

int main() {
    std::ofstream pipe("my_pipe");  // Open the named pipe for writing

    if (!pipe) {
        std::cerr << "Error: Could not open pipe for writing!\n";
        return 1;
    }

    std::string message = "Hello, this is a custom IPC message!";
    pipe << message << std::endl;  // Write message to pipe
    std::cout << "Sender: Sent message to pipe.\n";

    pipe.close();
    return 0;
}

