#ifndef AP_TRANS_C_OPS_CMP_HPP
#define AP_TRANS_C_OPS_CMP_HPP

#include <ap/trans/trans.hpp>
#include <ap/core/core.hpp>
#include <ap/meta/meta.hpp>

#include <ap/trans/c/c.hpp>

namespace ap::trans::c          {
    struct cmp                  {
        static ops& cmp_eq(ops&);
        static ops& cmp_ne(ops&);
    };
}

#endif
