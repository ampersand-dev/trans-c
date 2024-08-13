#include <ap/trans/c.hpp>

#include <iostream>

int main()                    {
    auto trans = ap::c::pack();
    auto var   = ap::c::var ();

    auto pack = Pack(MyPack)   (
        ap::let(ap::i8_t) ("a"),
        ap::let(ap::i16_t)("b"),
        ap::let(ap::i32_t)("c"),
        ap::let(ap::i64_t)("d"),

        ap::let(ap::u8_t) ("e"),
        ap::let(ap::u16_t)("f"),
        ap::let(ap::u32_t)("g"),
        ap::let(ap::u64_t)("h")
    );

    auto sub = ap::let(pack)("my_pack");

    std::cout << trans(pack).as_str()         << std::endl;
    std::cout << var  (sub) .value().as_str() << std::endl;
}