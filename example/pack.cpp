#include <ap/trans/c/pack.hpp>
#include <ap/trans.hpp>
#include <ap/trait.hpp>
#include <ap/meta.hpp>
#include <ap/core.hpp>

#include <iostream>

struct MyPack                             {
    static auto name() { return "MyPack"; }
};

int main()                    {
    auto trans = ap::c::pack();
    auto pack = ap::pack     {
        MyPack             {},
        ap::let(ap::i8_t) ("a"),
        ap::let(ap::i16_t)("b"),
        ap::let(ap::i32_t)("c"),
        ap::let(ap::i64_t)("d"),

        ap::let(ap::u8_t) ("e"),
        ap::let(ap::u16_t)("f"),
        ap::let(ap::u32_t)("g"),
        ap::let(ap::u64_t)("h"),
    };

    auto res = trans (pack);

    std::cout << res.as_str() << std::endl;
}