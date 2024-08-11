include_directories(../include)

add_library                         (
    trans-c
    STATIC

    ../include/ap/trans/c/ops/mem.hpp
    ../include/ap/trans/c/ops/ari.hpp
    ../include/ap/trans/c/ops/boolean.hpp
    ../include/ap/trans/c/ops/func.hpp
    ../include/ap/trans/c/ops/control.hpp
    ../include/ap/trans/c/ops/bit.hpp
    ../include/ap/trans/c/ops/cmp.hpp
    ../include/ap/trans/c/ops/ord.hpp
    ../include/ap/trans/c/ops/opc.hpp


    ../include/ap/trans/c/ops/uni.hpp
    ../include/ap/trans/c/ops/bin.hpp
    ../include/ap/trans/c/ops.hpp

    ../include/ap/trans/c/pack.hpp
    ../include/ap/trans/c/fn.hpp
    ../include/ap/trans/c/var.hpp
    ../include/ap/trans/c/c.hpp
    ../include/ap/trans/c.hpp

    ops/boolean.cpp
    ops/func.cpp
    ops/control.cpp
    ops/mem.cpp
    ops/ari.cpp
    ops/bit.cpp
    ops/cmp.cpp
    ops/ord.cpp
    ops/bin.cpp
    ops/uni.cpp
    ops/opc.cpp
    ops.cpp

    pack.cpp
    var.cpp
    fn.cpp
)