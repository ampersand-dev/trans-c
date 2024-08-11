#include <ap/trans/c/ops/boolean.hpp>
#include <ap/trans/c/ops.hpp>

namespace ap::trans::c                              {
    boolean::boolean(std::pmr::memory_resource* mre)
        : mre (mre),
          mem (mre)
            {}
    
    boolean::boolean()
        : mre (std::pmr::get_default_resource()),
          mem (std::pmr::get_default_resource())
            {}
}

namespace ap::trans::c                                                                    {
    ops boolean::bool_and() { bin* ret = mem.new_object<bin>("&&"); return ops(ret, mre); }
    ops boolean::bool_or () { bin* ret = mem.new_object<bin>("||"); return ops(ret, mre); }
    ops boolean::bool_not() { uni* ret = mem.new_object<uni>("!");  return ops(ret, mre); }
}