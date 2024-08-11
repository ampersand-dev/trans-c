#ifndef AP_TRANS_C_OPS_ARI_HPP
#define AP_TRANS_C_OPS_ARI_HPP

#include <ap/trans/trans.hpp>
#include <ap/core/core.hpp>
#include <ap/meta/meta.hpp>

#include <ap/trans/c/ops/bin.hpp>
#include <ap/trans/c/ops.hpp>

namespace ap::trans::c                                 {
    class ari                                          {
        using mem_t = std::pmr::polymorphic_allocator<>;
        using mre_t = std::pmr::memory_resource*;
        mre_t mre;
        mem_t mem;
    public:
        ari(std::pmr::memory_resource*);
        ari();

        ops add_eq();
        ops sub_eq();
        ops div_eq();
        ops mul_eq();
        ops mod_eq();

        ops add();
        ops sub();
        ops div();
        ops mul();
        ops mod();
    };
}


namespace ap::c              {
    using ari = trans::c::ari;
}

#endif
