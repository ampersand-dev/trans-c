#ifndef AP_TRANS_C_OPS_BIT_HPP
#define AP_TRANS_C_OPS_BIT_HPP

#include <ap/trans/trans.hpp>
#include <ap/core/core.hpp>
#include <ap/meta/meta.hpp>

#include <ap/trans/c/c.hpp>

namespace ap::trans::c       {
    struct bit               {
        ops& bit_and_eq(ops&);
        ops& bit_or_eq (ops&);
        ops& bit_xor_eq(ops&);

        ops& bit_and(ops&);
        ops& bit_or (ops&);
        ops& bit_xor(ops&);
        ops& bit_not(ops&);

        ops& bit_shl(ops&);
        ops& bit_shr(ops&);
    };
}

namespace ap::c              {
    using bit = trans::c::bit;
}

#endif
