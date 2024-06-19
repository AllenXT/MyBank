cmake_minimum_required(VERSION 3.27)
project(MyBank)

set(CMAKE_CXX_STANDARD 20)

add_library(account
        src/account/account.cpp
        src/account/account_factory.cpp
        src/account/account_manager.cpp
        src/account/account_visitor.cpp
)

add_library(transaction
        src/transaction/transaction.cpp
        src/transaction/transaction_manager.cpp
)

add_executable(main main.cpp)
target_link_libraries(main account transaction)
