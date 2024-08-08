#ifndef AP_TRANC_C_OPS_MEM_HPP
#define AP_TRANC_C_OPS_MEM_HPP

#include <ap/trans/trans.hpp>
#include <ap/core/core.hpp>
#include <ap/meta/meta.hpp>

#include <ap/trans/c/c.hpp>

namespace ap::trans::c {
    struct mem         {
        using str_t = std::string_view;

        ops& push(ops&);
        ops& move(ops&);
        ops& pop (ops&);
    };
}

namespace ap::c                  {
    using mem = ap::trans::c::mem;
}

#endif
