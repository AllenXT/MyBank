//
// Created by Tian_Xia on 2024/5/18.
//
#ifndef MYBANK_ACCOUNT_FACTORY_H
#define MYBANK_ACCOUNT_FACTORY_H

#include <memory>
#include "account.h"
#include "../utility/typelist.h"

using AccountTypes = Typelist<SavingsAccount, CheckingAccount, BusinessAccount, CreditAccount>;

class AccountFactory {
public:
    template<typename AccountType>
    std::unique_ptr<Account> createAccount();

    template<typename NewAccountType>
    void addAccountType();
};

template<typename AccountType>
std::unique_ptr<Account> AccountFactory::createAccount() {
    return std::make_unique<AccountType>();
}

template<typename NewAccountType>
void AccountFactory::addAccountType() {
    using NewAccountTypes = typename Append<AccountTypes, NewAccountType>::type;
}

#endif //MYBANK_ACCOUNT_FACTORY_H
