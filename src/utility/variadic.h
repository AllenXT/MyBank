//
// Created by Tian_Xia on 2024/5/18.
//

#ifndef MYBANK_VARIADIC_H
#define MYBANK_VARIADIC_H

#include <iostream>

template<typename... Args>
void print(Args... args) {
    (std::cout << ... << args) << std::endl;
}

#endif //MYBANK_VARIADIC_H
