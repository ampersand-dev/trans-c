#ifndef AP_TRANS_C_OPS_BIT_HPP
#define AP_TRANS_C_OPS_BIT_HPP

#include <ap/trans/trans.hpp>
#include <ap/core/core.hpp>
#include <ap/meta/meta.hpp>

#include <ap/trans/c/c.hpp>

namespace ap::trans::c              {
    struct bit                      {
        static ops& bit_and_eq(ops&);
        static ops& bit_or_eq (ops&);
        static ops& bit_xor_eq(ops&);

        static ops& bit_and(ops&);
        static ops& bit_or (ops&);
        static ops& bit_xor(ops&);
        static ops& bit_not(ops&);
    };
}

#endif
