//
// Created by Tian_Xia on 2024/5/18.
//
#include "account_manager.h"

void AccountManager::addAccount(const std::string& id, std::unique_ptr<Account> account) {
    ScopedWriteLock lock(mutex_);
    accounts_[id] = std::move(account);
}

std::shared_ptr<Account> AccountManager::getAccount(const std::string& id) {
    ScopedReadLock lock(mutex_);
    auto it = accounts_.find(id);
    if (it != accounts_.end()) {
        return it->second;
    }
    return nullptr;
}

void AccountManager::deposit(const std::string& id, double amount) {
    executeTransaction(id, &Account::deposit, amount);
}

void AccountManager::withdraw(const std::string& id, double amount) {
    executeTransaction(id, &Account::withdraw, amount);
}
