#ifndef AP_TRANS_C_OPS_BIT_HPP
#define AP_TRANS_C_OPS_BIT_HPP

#include <ap/trans/trans.hpp>
#include <ap/core/core.hpp>
#include <ap/meta/meta.hpp>

#include <ap/trans/c/ops/bin.hpp>
#include <ap/trans/c/ops/uni.hpp>
#include <ap/trans/c/ops.hpp>

namespace ap::trans::c                                 {
    class bit                                          {
        using mem_t = std::pmr::polymorphic_allocator<>;
        using mre_t = std::pmr::memory_resource*;
        mre_t mre;
        mem_t mem;
    public:
        bit(std::pmr::memory_resource*);
        bit();

        ops bit_and_eq();
        ops bit_or_eq ();
        ops bit_xor_eq();

        ops bit_and();
        ops bit_or ();
        ops bit_xor();
        ops bit_not();

        ops bit_shl();
        ops bit_shr();
    };
}

namespace ap::c              {
    using bit = trans::c::bit;
}

#endif
