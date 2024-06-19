//
// Created by Tian_Xia on 2024/5/18.
//
#ifndef MYBANK_ACCOUNT_VISITOR_H
#define MYBANK_ACCOUNT_VISITOR_H

#include <variant>

class SavingsAccount;
class CheckingAccount;
class BusinessAccount;
class CreditAccount;

struct AccountVisitor {
    virtual void visit(SavingsAccount& account) = 0;
    virtual void visit(CheckingAccount& account) = 0;
    virtual void visit(BusinessAccount& account) = 0;
    virtual void visit(CreditAccount& account) = 0;
};

class Account;
using AccountVariant = std::variant<SavingsAccount, CheckingAccount, BusinessAccount, CreditAccount>;

class PrintAccountVisitor : public AccountVisitor {
public:
    void visit(SavingsAccount& account) override;
    void visit(CheckingAccount& account) override;
    void visit(BusinessAccount& account) override;
    void visit(CreditAccount& account) override;
};

void printAccountInfo(AccountVariant& accountVariant);

#endif //MYBANK_ACCOUNT_VISITOR_H
