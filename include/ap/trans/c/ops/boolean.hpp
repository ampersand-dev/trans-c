#ifndef AP_TRANS_C_OPS_BOOLEAN_HPP
#define AP_TRANS_C_OPS_BOOLEAN_HPP

#include <ap/trans/trans.hpp>
#include <ap/core/core.hpp>
#include <ap/meta/meta.hpp>

#include <ap/trans/c/c.hpp>

namespace ap::trans::c     {
    struct boolean         {
        ops& bool_and(ops&);
        ops& bool_or (ops&);
        ops& bool_not(ops&);
    };
}

namespace ap::c                      {
    using boolean = trans::c::boolean;
}

#endif
