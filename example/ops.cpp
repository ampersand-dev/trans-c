#include <ap/trans/c.hpp>

#include <iostream>

using namespace ap::trans;

int main()                   {
    auto trans = ap::c::ops();

    auto v1 = ap::let (ap::i64_t)("a");
    auto v2 = ap::let (ap::u64_t)("b");
    auto v3 = ap::let (ap::u64_t)("c");


    std::cout << trans(v1 + v2).as_str() << std::endl;
    std::cout << trans(v1 - v2).as_str() << std::endl;
    std::cout << trans(v1 * v2).as_str() << std::endl;
    std::cout << trans(v1 / v2).as_str() << std::endl;
    std::cout << trans(v1 % v2).as_str() << std::endl;
}