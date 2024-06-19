//
// Created by Tian_Xia on 2024/5/23.
//
#ifndef MYBANK_TRANSACTION_H
#define MYBANK_TRANSACTION_H

#include <string>

class Transaction {
public:
    Transaction(std::string  type, double amount);

    [[nodiscard]] std::string getType() const;
    [[nodiscard]] double getAmount() const;

private:
    std::string type_;
    double amount_;
};

#endif //MYBANK_TRANSACTION_H
