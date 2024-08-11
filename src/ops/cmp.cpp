#include <ap/trans/c/ops/cmp.hpp>
#include <ap/trans/c/ops.hpp>

namespace ap::trans::c                              {
    cmp::cmp(std::pmr::memory_resource* mre)
        : mre (mre),
          mem (mre)
            {}
    
    cmp::cmp()
        : mre (std::pmr::get_default_resource()),
          mem (std::pmr::get_default_resource())
            {}
}

namespace ap::trans::c                                                              {
    ops cmp::cmp_eq() { bin* ret = mem.new_object<bin>("=="); return ops(ret, mre); }
    ops cmp::cmp_ne() { bin* ret = mem.new_object<bin>("!="); return ops(ret, mre); }
}