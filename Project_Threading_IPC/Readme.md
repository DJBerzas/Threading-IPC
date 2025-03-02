# Banking System and IPC Project

## Banking System

### Overview
This project simulates a banking system with concurrent transactions, demonstrating safe and unsafe money transfers between two bank accounts. It highlights multithreading, mutex locks, and potential deadlock risks when handling concurrent transactions.

### Development Environment
- **Built on:** Visual Studio Code
- **Language:** C++
- **Concurrency:** `std::thread`, `std::mutex`, `std::scoped_lock`
- **Compilation:** g++

### Project Structure
- `BankAccount.h`: Defines the `BankAccount` class with balance management and thread synchronization.
- `TransactionManager.h`: Handles safe and unsafe transactions between accounts.
- `main.cpp`: Creates the banking system, runs transactions using multiple threads, and displays the final balances.

### How to Build and Run
1. **Clone the Repository:**
   ```sh
   git clone <repository-url>
   cd Project_Threading_IPC
   ```
2. **Compile the Code:**
   ```sh
   g++ Project_Threading_IPC.cpp -o run
   ```
3. **Run the Program:**
   ```sh
   ./run
   ```

### Dependencies
Ensure you have:
- **G++ Compiler** (`g++` with C++11 or later support)
- **POSIX Threads (`pthread`)**
- **Visual Studio Code (Recommended IDE)**

### Coding Process
The program uses:
- **Mutex locks (`std::mutex`)** to synchronize access to shared resources.
- **Scoped locks (`std::scoped_lock`)** to prevent deadlocks during concurrent transactions.
- **Threading (`std::thread`)** to perform multiple transactions simultaneously.
- **Safe and unsafe transaction modes**, demonstrating correct and incorrect ways to handle concurrency.

---

## IPC Project

### Overview
This project demonstrates **Inter-Process Communication (IPC)** using **Named Pipes (FIFO)** in Linux. A sender process writes a message to a named pipe, and a receiver process reads it.

### Development Environment
- **Developed in:** Linux Terminal
- **Language:** C++
- **IPC Mechanism:** Named Pipes (FIFO)
- **Compilation:** g++
- **Version Control:** Git (Pushed through terminal)

### Project Structure
- `sender.cpp`: Sends a message through a named pipe (`my_pipe`).
- `receiver.cpp`: Reads the message from the named pipe and displays it.

### How to Build and Run
1. **Clone the Repository:**
   ```sh
   git clone <repository-url>
   cd ipc-project
   ```
2. **Compile the Code:**
   ```sh
   g++ sender.cpp -o sender
   g++ receiver.cpp -o receiver
   ```
3. **Create a Named Pipe:**
   ```sh
   mkfifo my_pipe
   ```
4. **Run the Receiver First:**
   ```sh
   ./receiver
   ```
5. **Run the Sender in a Separate Terminal:**
   ```sh
   ./sender
   ```

### Dependencies
Ensure you have:
- **G++ Compiler (`g++`)**
- **Linux-based OS** (for Named Pipes support)
- **Git** (for version control and pushing to GitHub)

### Coding Process
- **Used Named Pipes (FIFO)** to enable communication between two separate processes.
- **Sender writes a message** to the pipe.
- **Receiver reads and prints the message.**
- **Demonstrates IPC concepts** in Linux.
- **Pushed to GitHub through Linux Terminal** using:
   ```sh
   git add .
   git commit -m "Added IPC project"
   git push origin main
   ```

---

### Author
**DJ Berzas**

### License
This project is open-source and available under the MIT License.
