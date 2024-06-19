//
// Created by Tian_Xia on 2024/5/23.
//

#include "transaction.h"

#include <utility>

Transaction::Transaction(std::string  type, double amount)
        : type_(std::move(type)), amount_(amount) {}

std::string Transaction::getType() const {
    return type_;
}

double Transaction::getAmount() const {
    return amount_;
}

