//
// Created by Tian_Xia on 2024/5/18.
//
#ifndef MYBANK_ACCOUNT_MANAGER_H
#define MYBANK_ACCOUNT_MANAGER_H

#include <shared_mutex>
#include <unordered_map>
#include <string>
#include <memory>
#include "account.h"
#include "../utility/scoped_locks.h"
#include "../utility/concepts.h"
#include "../utility/typelist.h"

class AccountManager {
public:
    void addAccount(const std::string& id, std::unique_ptr<Account> account);
    std::shared_ptr<Account> getAccount(const std::string& id);
    void deposit(const std::string& id, double amount);
    void withdraw(const std::string& id, double amount);

    template<typename Func, IsNumeric... Args>
    void executeTransaction(const std::string& id, Func&& func, Args&&... args);

    template<IsAccount T>
    void applyInterest(T& account, double rate);

private:
    std::unordered_map<std::string, std::shared_ptr<Account>> accounts_;
    mutable std::shared_mutex mutex_;
};

template<typename Func, IsNumeric... Args>
void AccountManager::executeTransaction(const std::string& id, Func&& func, Args&&... args) {
    std::shared_ptr<Account> account = getAccount(id);
    if (account) {
        ScopedWriteLock lock(mutex_);
        (account.get()->*func)(std::forward<Args>(args)...);
    }
}

template<IsAccount T>
void AccountManager::applyInterest(T& account, double rate) {
    ScopedWriteLock lock(mutex_);
    double balance = account.getBalance();
    account.deposit(balance * rate);
}

#endif //MYBANK_ACCOUNT_MANAGER_H
