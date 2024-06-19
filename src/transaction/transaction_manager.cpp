//
// Created by Tian_Xia on 2024/5/23.
//
#include "transaction_manager.h"

void TransactionManager::beginTransaction() {
    std::lock_guard<std::mutex> lock(mtx);
    operations.clear();
}

void TransactionManager::commitTransaction() {
    std::lock_guard<std::mutex> lock(mtx);
    for (auto& operation : operations) {
        operation();
    }
    operations.clear();
}

void TransactionManager::rollbackTransaction() {
    std::lock_guard<std::mutex> lock(mtx);
    operations.clear();
}

void TransactionManager::addOperation(const std::function<void()>& operation) {
    std::lock_guard<std::mutex> lock(mtx);
    operations.push_back(operation);
}
