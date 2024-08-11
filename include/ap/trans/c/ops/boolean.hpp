#ifndef AP_TRANS_C_OPS_BOOLEAN_HPP
#define AP_TRANS_C_OPS_BOOLEAN_HPP

#include <ap/trans/trans.hpp>
#include <ap/core/core.hpp>
#include <ap/meta/meta.hpp>

#include <ap/trans/c/ops/bin.hpp>
#include <ap/trans/c/ops/uni.hpp>
#include <ap/trans/c/ops.hpp>

namespace ap::trans::c                                 {
    class boolean                                      {
        using mem_t = std::pmr::polymorphic_allocator<>;
        using mre_t = std::pmr::memory_resource*;
        mre_t mre;
        mem_t mem;
    public:
        boolean(std::pmr::memory_resource*);
        boolean();

        ops bool_and();
        ops bool_or ();
        ops bool_not();
    };
}

namespace ap::c                      {
    using boolean = trans::c::boolean;
}

#endif
