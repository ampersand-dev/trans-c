#ifndef AP_TRANS_C_OPS_ARI_HPP
#define AP_TRANS_C_OPS_ARI_HPP

#include <ap/trans/trans.hpp>
#include <ap/core/core.hpp>
#include <ap/meta/meta.hpp>

#include <ap/trans/c/c.hpp>

namespace ap::trans::c   {
    struct ari           {
        ops& add_eq(ops&);
        ops& sub_eq(ops&);
        ops& div_eq(ops&);
        ops& mul_eq(ops&);
        ops& mod_eq(ops&);

        ops& add(ops&);
        ops& sub(ops&);
        ops& div(ops&);
        ops& mul(ops&);
        ops& mod(ops&);
    };
}

namespace ap::c              {
    using ari = trans::c::ari;
}

#endif
