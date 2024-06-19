# MyBank Project

This project is a demonstration of a bank system implemented using modern C++ techniques. The system includes multiple account types, transaction management, and multithreading to simulate concurrent transactions.

## Features

- **Account Management:** Supports multiple account types including savings, checking, business, and credit accounts.
- **Transaction Management:** Uses a `TransactionManager` to manage and execute transactions with support for rollback.
- **Concurrency:** Simulates multiple clients performing transactions concurrently using multithreading.
- **Logging Transactions:** Each account records its transactions which can be printed for review.

## C++ Techniques Used

- **Concepts:** Used to define constraints on template parameters, ensuring type safety.
- **Variadic Templates:** Used for printing account information.
- **RAII (Resource Acquisition Is Initialization):** Ensures resources are properly managed and released.
- **Scoped Locks:** Manages thread synchronization using scoped locks.
- **Custom Type Traits and Type Lists:** Used for compile-time type manipulation and ensuring type safety.
- **Visitor Pattern:** Used for applying operations on account variants.
- **Transactional Memory:** Simulated using `TransactionManager` to handle transactions with commit and rollback.
- **Multithreading:** Simulates concurrent transactions using the C++ thread library.

## Project Structure

- **src/account/**: Contains account-related classes and their implementations.
    - `account.h`
    - `account.cpp`
    - `account_factory.h`
    - `account_factory.cpp`
    - `account_manager.h`
    - `account_manager.cpp`
    - `account_visitor.h`
    - `account_visitor.cpp`
- **src/transaction/**: Contains the transaction management classes.
    - `transaction.h`
    - `transaction.cpp`
    - `transaction_manager.h`
    - `transaction_manager.cpp`
- **src/utility/**: Contains utility classes and type traits.
    - `concepts.h`
    - `scoped_locks.h`
    - `typelist.h`
    - `variadic.h`

## Running the Project

After building the project, you can run the executable `./main`. The program will output the initial balances, perform a series of transactions, apply interest, and simulate concurrent transactions. The final balances and transaction logs will be printed to the console.
