//
// Created by Tian_Xia on 2024/5/18.
//
#include "account.h"

SavingsAccount::SavingsAccount() : balance(0.0) {}

void SavingsAccount::deposit(double amount) {
    balance += amount;
    addTransaction("Deposit", amount);
}

void SavingsAccount::withdraw(double amount) {
    balance -= amount;
    addTransaction("Withdraw", amount);
}

double SavingsAccount::getBalance() const {
    return balance;
}

std::string SavingsAccount::getType() const {
    return "SavingsAccount";
}

CheckingAccount::CheckingAccount() : balance(0.0) {}

void CheckingAccount::deposit(double amount) {
    balance += amount;
    addTransaction("Deposit", amount);
}

void CheckingAccount::withdraw(double amount) {
    balance -= amount;
    addTransaction("Withdraw", amount);
}

double CheckingAccount::getBalance() const {
    return balance;
}

std::string CheckingAccount::getType() const {
    return "CheckingAccount";
}

BusinessAccount::BusinessAccount() : balance(0.0) {}

void BusinessAccount::deposit(double amount) {
    balance += amount;
    addTransaction("Deposit", amount);
}

void BusinessAccount::withdraw(double amount) {
    balance -= amount;
    addTransaction("Withdraw", amount);
}

double BusinessAccount::getBalance() const {
    return balance;
}

std::string BusinessAccount::getType() const {
    return "BusinessAccount";
}

CreditAccount::CreditAccount() : balance(0.0), creditLimit(5000.0) {}

void CreditAccount::deposit(double amount) {
    balance += amount;
    addTransaction("Deposit", amount);
}

void CreditAccount::withdraw(double amount) {
    if (balance - amount < -creditLimit) {
        throw std::runtime_error("Credit limit exceeded");
    }
    balance -= amount;
    addTransaction("Withdraw", amount);
}

double CreditAccount::getBalance() const {
    return balance;
}

std::string CreditAccount::getType() const {
    return "CreditAccount";
}

