//
// Created by Tian_Xia on 2024/5/18.
//
#ifndef MYBANK_ACCOUNT_H
#define MYBANK_ACCOUNT_H

#include <string>
#include <vector>
#include <memory>
#include "../transaction//transaction.h"

class Account {
public:
    virtual ~Account() = default;
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
    [[nodiscard]] virtual double getBalance() const = 0;
    [[nodiscard]] virtual std::string getType() const = 0;
    void addTransaction(const std::string& type, double amount) {
        transactions_.emplace_back(type, amount);
    }
    [[nodiscard]] const std::vector<Transaction>& getTransactions() const {
        return transactions_;
    }

protected:
    std::vector<Transaction> transactions_;
};

class SavingsAccount : public Account {
public:
    SavingsAccount();
    void deposit(double amount) override;
    void withdraw(double amount) override;
    [[nodiscard]] double getBalance() const override;
    [[nodiscard]] std::string getType() const override;

private:
    double balance;
};

class CheckingAccount : public Account {
public:
    CheckingAccount();
    void deposit(double amount) override;
    void withdraw(double amount) override;
    [[nodiscard]] double getBalance() const override;
    [[nodiscard]] std::string getType() const override;

private:
    double balance;
};

class BusinessAccount : public Account {
public:
    BusinessAccount();
    void deposit(double amount) override;
    void withdraw(double amount) override;
    [[nodiscard]] double getBalance() const override;
    [[nodiscard]] std::string getType() const override;

private:
    double balance;
};

class CreditAccount : public Account {
public:
    CreditAccount();
    void deposit(double amount) override;
    void withdraw(double amount) override;
    [[nodiscard]] double getBalance() const override;
    [[nodiscard]] std::string getType() const override;

private:
    double balance;
    double creditLimit;
};

#endif //MYBANK_ACCOUNT_H
