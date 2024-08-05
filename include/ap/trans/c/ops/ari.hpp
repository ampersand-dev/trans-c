#ifndef AP_TRANS_C_OPS_ARI_HPP
#define AP_TRANS_C_OPS_ARI_HPP

#include <ap/trans/trans.hpp>
#include <ap/core/core.hpp>
#include <ap/meta/meta.hpp>

#include <ap/trans/c/c.hpp>

namespace ap::trans::c          {
    struct ari                  {
        static ops& add_eq(ops&);
        static ops& sub_eq(ops&);
        static ops& div_eq(ops&);
        static ops& mul_eq(ops&);
        static ops& mod_eq(ops&);

        static ops& add(ops&);
        static ops& sub(ops&);
        static ops& div(ops&);
        static ops& mul(ops&);
        static ops& mod(ops&);
    };
}

#endif
