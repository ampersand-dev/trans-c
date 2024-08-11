#include <ap/trans/c/ops/bit.hpp>

namespace ap::trans::c                       {
    bit::bit (std::pmr::memory_resource* mre)
        : mre (mre),
          mem (mre)
            {}

    bit::bit()
        : mre (std::pmr::get_default_resource()),
          mem (std::pmr::get_default_resource())
            {}
}

namespace ap::trans::c                                                                         {
    ops bit::bit_and_eq() { bin_eq* ret = mem.new_object<bin_eq>("&="); return ops (ret, mre); }
    ops bit::bit_xor_eq() { bin_eq* ret = mem.new_object<bin_eq>("|="); return ops (ret, mre); }
    ops bit::bit_or_eq () { bin_eq* ret = mem.new_object<bin_eq>("^="); return ops (ret, mre); }
    
    ops bit::bit_shl() { bin* ret = mem.new_object<bin>("<<"); return ops (ret, mre); }
    ops bit::bit_shr() { bin* ret = mem.new_object<bin>(">>"); return ops (ret, mre); }

    ops bit::bit_and() { bin* ret = mem.new_object<bin>("&"); return ops (ret, mre); }
    ops bit::bit_xor() { bin* ret = mem.new_object<bin>("^"); return ops (ret, mre); }
    ops bit::bit_or () { bin* ret = mem.new_object<bin>("|"); return ops (ret, mre); }
    ops bit::bit_not() { uni* ret = mem.new_object<uni>("~"); return ops (ret, mre); }
}