//
// Created by Tian_Xia on 2024/5/18.
//

#ifndef MYBANK_CONCEPTS_H
#define MYBANK_CONCEPTS_H

#include <type_traits>
#include "../account/account.h"

template<typename T>
concept IsAccount = std::is_base_of_v<Account, T>;

template<typename T>
concept IsNumeric = std::is_arithmetic_v<std::decay_t<T>>;

#endif //MYBANK_CONCEPTS_H
