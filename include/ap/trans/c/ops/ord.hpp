#ifndef AP_TRANS_C_OPS_ORD_HPP
#define AP_TRANS_C_OPS_ORD_HPP

#include <ap/trans/trans.hpp>
#include <ap/core/core.hpp>
#include <ap/meta/meta.hpp>

#include <ap/trans/c/ops/bin.hpp>
#include <ap/trans/c/ops.hpp>

namespace ap::trans::c   {
    class ord            {
        using mem_t = std::pmr::polymorphic_allocator<>;
        using mre_t = std::pmr::memory_resource*;
        mre_t mre;
        mem_t mem;
    public:
        ord(std::pmr::memory_resource*);
        ord();

    public:
        ops ord_gt();
        ops ord_ge();
        ops ord_lt();
        ops ord_le();
    };
}

namespace ap::c              {
    using ord = trans::c::ord;
}

#endif
