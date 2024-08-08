#include <ap/trans/c/ops.hpp>

#include <ap/trans.hpp>
#include <ap/trait.hpp>
#include <ap/meta.hpp>
#include <ap/core.hpp>

#include <iostream>

using namespace ap::trans;

int main()                      {
    auto trans = ap::trans::ops (
        ap::c::ops(),

        ap::c::boolean(),
        ap::c::func(),
        ap::c::ari(),
        ap::c::bit(),
        ap::c::cmp(),
        ap::c::ord(),
        ap::c::mem()
    );

    auto v1 = ap::let (ap::i64_t)("a");
    auto v2 = ap::let (ap::u64_t)("b");
    auto v3 = ap::let (ap::u64_t)("c");


    auto ops = v1 + (v2 | v3);
    auto res = trans(ops);
    
    std::cout << res.as_str() << std::endl;
}