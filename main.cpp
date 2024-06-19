#include "src/account/account_factory.h"
#include "src/account/account_manager.h"
#include "src/account/account_visitor.h"
#include "src/transaction/transaction_manager.h"
#include "src/utility/variadic.h"
#include "src/transaction/transaction.h"
#include <iostream>
#include <thread>
#include <vector>

// Function to perform a series of transactions on an account using TransactionManager
template<typename Func>
void performTransactions(AccountManager& manager, TransactionManager& transactionManager, const std::string& accountId, Func&& func) {
    transactionManager.beginTransaction();

    try {
        func(transactionManager, manager, accountId);
        transactionManager.commitTransaction();
    } catch (const std::exception& e) {
        std::cerr << "Transaction failed: " << e.what() << ". Rolling back." << std::endl;
        transactionManager.rollbackTransaction();
    }
}

// Different transaction operations for different accounts
void savingsTransactions(TransactionManager& transactionManager, AccountManager& manager, const std::string& accountId) {
    transactionManager.addOperation([&manager, accountId]() { manager.deposit(accountId, 300); });
    transactionManager.addOperation([&manager, accountId]() { manager.withdraw(accountId, 150); });
}

void checkingTransactions(TransactionManager& transactionManager, AccountManager& manager, const std::string& accountId) {
    transactionManager.addOperation([&manager, accountId]() { manager.deposit(accountId, 500); });
    transactionManager.addOperation([&manager, accountId]() { manager.withdraw(accountId, 200); });
}

void businessTransactions(TransactionManager& transactionManager, AccountManager& manager, const std::string& accountId) {
    transactionManager.addOperation([&manager, accountId]() { manager.deposit(accountId, 1000); });
    transactionManager.addOperation([&manager, accountId]() { manager.withdraw(accountId, 500); });
}

void creditTransactions(TransactionManager& transactionManager, AccountManager& manager, const std::string& accountId) {
    transactionManager.addOperation([&manager, accountId]() { manager.deposit(accountId, 700); });
    transactionManager.addOperation([&manager, accountId]() { manager.withdraw(accountId, 300); });
}

void printTransactions(const Account& account) {
    std::cout << account.getType() << " transactions:" << std::endl;
    for (const auto& transaction : account.getTransactions()) {
        std::cout << " - " << transaction.getType() << ": " << transaction.getAmount() << std::endl;
    }
}

int main() {
    AccountFactory factory;
    AccountManager manager;
    TransactionManager transactionManager;

    auto savings = factory.createAccount<SavingsAccount>();
    auto checking = factory.createAccount<CheckingAccount>();
    auto business = factory.createAccount<BusinessAccount>();
    auto credit = factory.createAccount<CreditAccount>();

    manager.addAccount("savings1", std::move(savings));
    manager.addAccount("checking1", std::move(checking));
    manager.addAccount("business1", std::move(business));
    manager.addAccount("credit1", std::move(credit));

    manager.deposit("savings1", 1000);
    manager.deposit("checking1", 2000);
    manager.deposit("business1", 5000);
    manager.deposit("credit1", 3000);

    // Get variant objects
    std::shared_ptr<Account> savingsAccount = manager.getAccount("savings1");
    std::shared_ptr<Account> checkingAccount = manager.getAccount("checking1");
    std::shared_ptr<Account> businessAccount = manager.getAccount("business1");
    std::shared_ptr<Account> creditAccount = manager.getAccount("credit1");

    AccountVariant savingsVariant = *dynamic_cast<SavingsAccount*>(savingsAccount.get());
    AccountVariant checkingVariant = *dynamic_cast<CheckingAccount*>(checkingAccount.get());
    AccountVariant businessVariant = *dynamic_cast<BusinessAccount*>(businessAccount.get());
    AccountVariant creditVariant = *dynamic_cast<CreditAccount*>(creditAccount.get());

    // Print account information
    printAccountInfo(savingsVariant);
    printAccountInfo(checkingVariant);
    printAccountInfo(businessVariant);
    printAccountInfo(creditVariant);

    // Perform transactions using TransactionManager
    performTransactions(manager, transactionManager, "savings1", savingsTransactions);
    performTransactions(manager, transactionManager, "checking1", checkingTransactions);
    performTransactions(manager, transactionManager, "business1", businessTransactions);
    performTransactions(manager, transactionManager, "credit1", creditTransactions);

    // Update variant objects
    savingsVariant = *dynamic_cast<SavingsAccount*>(manager.getAccount("savings1").get());
    checkingVariant = *dynamic_cast<CheckingAccount*>(manager.getAccount("checking1").get());
    businessVariant = *dynamic_cast<BusinessAccount*>(manager.getAccount("business1").get());
    creditVariant = *dynamic_cast<CreditAccount*>(manager.getAccount("credit1").get());

    // Using variadic template to print info
    print("Transaction completed. Updated balances:");
    printAccountInfo(savingsVariant);
    printAccountInfo(checkingVariant);
    printAccountInfo(businessVariant);
    printAccountInfo(creditVariant);

    // Print transactions for each account
    printTransactions(*dynamic_cast<SavingsAccount*>(manager.getAccount("savings1").get()));
    printTransactions(*dynamic_cast<CheckingAccount*>(manager.getAccount("checking1").get()));
    printTransactions(*dynamic_cast<BusinessAccount*>(manager.getAccount("business1").get()));
    printTransactions(*dynamic_cast<CreditAccount*>(manager.getAccount("credit1").get()));

    // Apply interest using concepts
    manager.applyInterest(*dynamic_cast<SavingsAccount*>(manager.getAccount("savings1").get()), 0.05);
    manager.applyInterest(*dynamic_cast<CheckingAccount*>(manager.getAccount("checking1").get()), 0.03);
    manager.applyInterest(*dynamic_cast<BusinessAccount*>(manager.getAccount("business1").get()), 0.02);

    // Update variant objects
    savingsVariant = *dynamic_cast<SavingsAccount*>(manager.getAccount("savings1").get());
    checkingVariant = *dynamic_cast<CheckingAccount*>(manager.getAccount("checking1").get());
    businessVariant = *dynamic_cast<BusinessAccount*>(manager.getAccount("business1").get());
    creditVariant = *dynamic_cast<CreditAccount*>(manager.getAccount("credit1").get());

    print("After applying interest:");
    printAccountInfo(savingsVariant);
    printAccountInfo(checkingVariant);
    printAccountInfo(businessVariant);
    printAccountInfo(creditVariant);

    // Simulate multiple clients performing deposits and withdrawals concurrently using multithreading
    std::vector<std::thread> threads;
    threads.emplace_back([](AccountManager& manager, TransactionManager& transactionManager) {
        performTransactions(manager, transactionManager, "savings1", savingsTransactions);
    }, std::ref(manager), std::ref(transactionManager));
    threads.emplace_back([](AccountManager& manager, TransactionManager& transactionManager) {
        performTransactions(manager, transactionManager, "checking1", checkingTransactions);
    }, std::ref(manager), std::ref(transactionManager));
    threads.emplace_back([](AccountManager& manager, TransactionManager& transactionManager) {
        performTransactions(manager, transactionManager, "business1", businessTransactions);
    }, std::ref(manager), std::ref(transactionManager));
    threads.emplace_back([](AccountManager& manager, TransactionManager& transactionManager) {
        performTransactions(manager, transactionManager, "credit1", creditTransactions);
    }, std::ref(manager), std::ref(transactionManager));

    for (auto& thread : threads) {
        thread.join();
    }

    // Update variant objects and print final balances
    savingsVariant = *dynamic_cast<SavingsAccount*>(manager.getAccount("savings1").get());
    checkingVariant = *dynamic_cast<CheckingAccount*>(manager.getAccount("checking1").get());
    businessVariant = *dynamic_cast<BusinessAccount*>(manager.getAccount("business1").get());
    creditVariant = *dynamic_cast<CreditAccount*>(manager.getAccount("credit1").get());

    print("After multithreading transactions:");
    printAccountInfo(savingsVariant);
    printAccountInfo(checkingVariant);
    printAccountInfo(businessVariant);
    printAccountInfo(creditVariant);

    return 0;
}
