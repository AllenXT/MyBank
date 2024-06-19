//
// Created by Tian_Xia on 2024/5/18.
//

#ifndef MYBANK_TYPELIST_H
#define MYBANK_TYPELIST_H

template<typename... Ts>
struct Typelist {};

template<typename List, typename T>
struct Append;

template<typename... Ts, typename T>
struct Append<Typelist<Ts...>, T> {
    using type = Typelist<Ts..., T>;
};

#endif //MYBANK_TYPELIST_H
