include_directories(../include)

add_library                         (
    trans-c
    STATIC

    ../include/ap/trans/c/ops/move.hpp
    ../include/ap/trans/c/ops/ari.hpp
    ../include/ap/trans/c/ops/bit.hpp
    ../include/ap/trans/c/ops/cmp.hpp
    ../include/ap/trans/c/ops/ord.hpp
    ../include/ap/trans/c/ops.hpp

    ../include/ap/trans/c/pack.hpp
    ../include/ap/trans/c/var.hpp
    ../include/ap/trans/c/c.hpp

    ops/move.cpp
    ops/ari.cpp
    ops/bit.cpp
    ops/cmp.cpp
    ops/ord.cpp
    ops.cpp

    pack.cpp
    var.cpp
)