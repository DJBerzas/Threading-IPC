#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <iostream>
#include <mutex>

class BankAccount {
private:
    int balance;
    std::mutex account_mutex;

public:
    BankAccount(int initial_balance) : balance(initial_balance) {}

    int getBalance() {
        return balance;
    }

    //  Optional mutex locking 
    void updateBalance(int amount, bool alreadyLocked = false) {
        if (!alreadyLocked) {
            std::lock_guard<std::mutex> lock(account_mutex);
        }
        int old_balance = balance;
        balance += amount;
        std::cout << "Transaction: " << amount
            << ". Old Balance: " << old_balance
            << ", New Balance: " << balance
            << "\n";
    }

    std::mutex& getMutex() {
        return account_mutex;
    }
};

#endif
