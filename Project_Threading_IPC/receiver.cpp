
#include <iostream>
#include <fstream>
#include <unistd.h>

int main() {
    std::ifstream pipe("my_pipe");  // Open the named pipe for reading
    if (!pipe) {
        std::cerr << "Error: Could not open pipe for reading!\n";
        return 1;
    }

    std::string receivedMessage;
    std::getline(pipe, receivedMessage);  // Read message from pipe

    std::cout << "Receiver: Received message - " << receivedMessage << std::endl;

    pipe.close();
    return 0;
}
