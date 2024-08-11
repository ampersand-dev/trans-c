#include <ap/trans/c/ops/ord.hpp>
#include <ap/trans/c/ops.hpp>

namespace ap::trans::c                      {
    ord::ord(std::pmr::memory_resource* mre)
        : mre (mre),
          mem (mre)
            {}

    ord::ord()
        : mre (std::pmr::get_default_resource()),
          mem (std::pmr::get_default_resource())
            {}
}

namespace ap::trans::c                                                              {
    ops ord::ord_gt() { bin* ret = mem.new_object<bin>(">") ; return ops(ret, mre); }
    ops ord::ord_ge() { bin* ret = mem.new_object<bin>(">-"); return ops(ret, mre); }
    ops ord::ord_lt() { bin* ret = mem.new_object<bin>("<") ; return ops(ret, mre); }
    ops ord::ord_le() { bin* ret = mem.new_object<bin>("<="); return ops(ret, mre); }
}