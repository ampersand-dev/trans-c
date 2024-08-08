#include <ap/trans/c/var.hpp>

#include <ap/trans.hpp>
#include <ap/trait.hpp>
#include <ap/meta.hpp>
#include <ap/core.hpp>

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

    auto i8s  = trans(i8);
    auto u8s  = trans(u8);

    auto i16s = trans(i16);
    auto u16s = trans(u16);

    auto i32s = trans(i32);
    auto u32s = trans(u32);

    auto i64s = trans(i64);
    auto u64s = trans(u64);

    std::cout << i8s .as_str() << std::endl;
    std::cout << u8s .as_str() << std::endl;

    std::cout << i16s.as_str() << std::endl;
    std::cout << u16s.as_str() << std::endl;

    std::cout << i32s.as_str() << std::endl;
    std::cout << u32s.as_str() << std::endl;

    std::cout << i64s.as_str() << std::endl;
    std::cout << u64s.as_str() << std::endl;
}