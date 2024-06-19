//
// Created by Tian_Xia on 2024/5/18.
//
#include "account_factory.h"

template<>
std::unique_ptr<Account> AccountFactory::createAccount<SavingsAccount>() {
    return std::make_unique<SavingsAccount>();
}

template<>
std::unique_ptr<Account> AccountFactory::createAccount<CheckingAccount>() {
    return std::make_unique<CheckingAccount>();
}

template<>
std::unique_ptr<Account> AccountFactory::createAccount<BusinessAccount>() {
    return std::make_unique<BusinessAccount>();
}

template<>
std::unique_ptr<Account> AccountFactory::createAccount<CreditAccount>() {
    return std::make_unique<CreditAccount>();
}