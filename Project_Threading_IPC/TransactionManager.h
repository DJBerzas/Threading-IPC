#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H

#include "BankAccount.h"
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

class TransactionManager {
public:
    static void performTransaction(int id, BankAccount& from, BankAccount& to, int amount, bool safeTransfer) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100 * id)); // Simulate processing delay

        if (safeTransfer) {
            std::cout << "Thread " << id << " attempting a SAFE transfer from Account A to B...\n";

            // SAFE LOCKING: Uses std::scoped_lock for proper ordering
            std::scoped_lock lock(from.getMutex(), to.getMutex());

            from.updateBalance(-amount, true);
            to.updateBalance(amount, true);

            std::cout << "Thread " << id << " completed a SAFE transfer.\n";
        }
        else {
            std::cout << "Thread " << id << " attempting a DEADLOCK RISK transfer from Account B to A...\n";

            // Ensure locks are acquired in a consistent order to prevent deadlocks
            std::lock(from.getMutex(), to.getMutex());
            std::lock_guard<std::mutex> lockA(from.getMutex(), std::adopt_lock);
            std::lock_guard<std::mutex> lockB(to.getMutex(), std::adopt_lock);

            from.updateBalance(-amount, true);
            to.updateBalance(amount, true);

            std::cout << "Thread " << id << " completed a DEADLOCK RISK transfer.\n";
        }
    }
};

#endif
