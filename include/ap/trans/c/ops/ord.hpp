#ifndef AP_TRANS_C_OPS_ORD_HPP
#define AP_TRANS_C_OPS_ORD_HPP

#include <ap/trans/trans.hpp>
#include <ap/core/core.hpp>
#include <ap/meta/meta.hpp>

#include <ap/trans/c/c.hpp>

namespace ap::trans::c          {
    struct ord                  {
        static ops& ord_gt(ops&);
        static ops& ord_ge(ops&);
        static ops& ord_lt(ops&);
        static ops& ord_le(ops&);
    };
}

namespace ap::c              {
    using ord = trans::c::ord;
}

#endif
