#include <ap/trans/c/ops.hpp>
#include <ap/trans/c/fn.hpp>

#include <ap/trans.hpp>
#include <ap/trait.hpp>
#include <ap/meta.hpp>
#include <ap/core.hpp>
#include <iostream>

auto test1()                         {
    auto a = ap::let (ap::i64_t)("a");
    auto b = ap::let (ap::i64_t)("b");
    auto c = ap::let (ap::i64_t)("c");

    a = 3;
    b = 4;
    c = a + b;

    return (a + b + c);
}

auto test2(ap::var<ap::types::i64_t>) {
    return 1;
}

int main()                                          {
    auto fn1 = ap::func(ap::i64_t)()("test1", test1);
    auto op1 = fn1();

    auto trans = ap::trans::ops(
        ap::c::ops(),

        ap::c::boolean(),
        ap::c::func(),
        ap::c::ari(),
        ap::c::bit(),
        ap::c::cmp(),
        ap::c::ord(),
        ap::c::mem()
    );

    auto func = ap::trans::fn (ap::c::fn(), trans);

    auto res = func(fn1);
    std::cout << res.as_str() << std::endl;
}