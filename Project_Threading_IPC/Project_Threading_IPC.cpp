#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>
#include "BankAccount.h"
#include "TransactionManager.h"

class BankSystem {
private:
    BankAccount accountA;
    BankAccount accountB;
    std::vector<std::thread> threads;

public:
    BankSystem(int initial_balance_A, int initial_balance_B)
        : accountA(initial_balance_A), accountB(initial_balance_B) {}

    void runTransactions() {
        const int num_threads = 6;
        int transactions[num_threads] = { 200, -150, 300, -100, 50, -200 };
        bool safe_transfers[num_threads] = { true, false, true, false, true, false }; // Alternate safety

        // Create threads for transactions
        for (int i = 0; i < num_threads; ++i) {
            threads.push_back(std::thread(TransactionManager::performTransaction, i + 1,
                std::ref(accountA), std::ref(accountB), transactions[i], safe_transfers[i]));
        }

        // Join threads to ensure execution completes
        for (auto& t : threads) {
            t.join();
        }

        std::cout << "Final Balances: Account A = " << accountA.getBalance()
            << ", Account B = " << accountB.getBalance() << std::endl;
    }
};

int main() {
    BankSystem bank(1000, 1000);
    bank.runTransactions();
    return 0;
}
