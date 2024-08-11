#ifndef AP_TRANS_C_OPS_CMP_HPP
#define AP_TRANS_C_OPS_CMP_HPP

#include <ap/trans/trans.hpp>
#include <ap/core/core.hpp>
#include <ap/meta/meta.hpp>

#include <ap/trans/c/ops/bin.hpp>
#include <ap/trans/c/ops/uni.hpp>
#include <ap/trans/c/ops.hpp>

namespace ap::trans::c                                 {
    class cmp                                          {
        using mem_t = std::pmr::polymorphic_allocator<>;
        using mre_t = std::pmr::memory_resource*;
        mre_t mre;
        mem_t mem;
    public:
        cmp(std::pmr::memory_resource*);
        cmp();

        ops cmp_eq();
        ops cmp_ne();
    };
}

namespace ap::c              {
    using cmp = trans::c::cmp;
}

#endif
