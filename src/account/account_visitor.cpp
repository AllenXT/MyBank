//
// Created by Tian_Xia on 2024/5/18.
//
#include "account_visitor.h"
#include "account.h"
#include <iostream>

void PrintAccountVisitor::visit(SavingsAccount& account) {
    std::cout << "Savings Account Balance: " << account.getBalance() << std::endl;
}

void PrintAccountVisitor::visit(CheckingAccount& account) {
    std::cout << "Checking Account Balance: " << account.getBalance() << std::endl;
}

void PrintAccountVisitor::visit(BusinessAccount& account) {
    std::cout << "Business Account Balance: " << account.getBalance() << std::endl;
}

void PrintAccountVisitor::visit(CreditAccount& account) {
    std::cout << "Credit Account Balance: " << account.getBalance() << std::endl;
}

void printAccountInfo(AccountVariant& accountVariant) {
    PrintAccountVisitor visitor;
    std::visit([&visitor](auto& account) { visitor.visit(account); }, accountVariant);
}


