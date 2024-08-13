#include <ap/trans/c.hpp>
#include <iostream>

auto test1()                         {
    auto a = ap::let (ap::i64_t)("a");
    auto b = ap::let (ap::i64_t)("b");
    auto c = ap::let (ap::i64_t)("c");

    auto d = ap::let (ap::i64_t, 3)("d");

    d[1] = 5;

    a = 3;
    b = 4;
    c = a + b;

    ap::While()(a != b)([&]() {
        c += 1;
    });

    return (a + b + c);
}

int main()                                          {
    auto fn = ap::Fn(ap::i64_t)()("test1", test1);
    auto op = fn();

    auto trans = ap::c::ops();

    auto func = ap::trans::fn (ap::c::fn(), trans);

    auto res = func(fn);
    std::cout << res.head() << std::endl;
    std::cout << res.all () << std::endl;
}