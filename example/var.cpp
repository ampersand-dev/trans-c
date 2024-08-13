#include <ap/trans/c.hpp>

#include <iostream>


int main()                   {
    auto trans = ap::c::var();

    auto i8  = ap::let (ap::i8_t) ("a");
    auto u8  = ap::let (ap::u8_t) ("a");

    auto i16 = ap::let (ap::i16_t)("a");
    auto u16 = ap::let (ap::u16_t)("a");

    auto i32 = ap::let (ap::i32_t)("a");
    auto u32 = ap::let (ap::u32_t)("a");

    auto i64 = ap::let (ap::i64_t)("a");
    auto u64 = ap::let (ap::u64_t)("a");

    std::cout << trans(i8) .value().as_str() << std::endl;
    std::cout << trans(u8) .value().as_str() << std::endl;

    std::cout << trans(i16).value().as_str() << std::endl;
    std::cout << trans(u16).value().as_str() << std::endl;

    std::cout << trans(i32).value().as_str() << std::endl;
    std::cout << trans(u32).value().as_str() << std::endl;

    std::cout << trans(i64).value().as_str() << std::endl;
    std::cout << trans(u64).value().as_str() << std::endl;
}