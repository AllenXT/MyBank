//
// Created by Tian_Xia on 2024/5/23.
//

#ifndef MYBANK_TRANSACTION_MANAGER_H
#define MYBANK_TRANSACTION_MANAGER_H

#include <mutex>
#include <vector>
#include <functional>

class TransactionManager {
public:
    void beginTransaction();
    void commitTransaction();
    void rollbackTransaction();
    void addOperation(const std::function<void()>& operation);

private:
    std::vector<std::function<void()>> operations;
    std::mutex mtx;
};

#endif //MYBANK_TRANSACTION_MANAGER_H
