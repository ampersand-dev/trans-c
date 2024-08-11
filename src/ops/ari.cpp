#include <ap/trans/c/ops/ari.hpp>

namespace ap::trans::c                       {
    ari::ari (std::pmr::memory_resource* mre)
        : mre (mre),
          mem (mre)
            {}

    ari::ari()
        : mre (std::pmr::get_default_resource()),
          mem (std::pmr::get_default_resource())
            {}
}

namespace ap::trans::c                                                                     {
    ops ari::add_eq() { bin_eq* ret = mem.new_object<bin_eq>("+="); return ops (ret, mre); }
    ops ari::sub_eq() { bin_eq* ret = mem.new_object<bin_eq>("-="); return ops (ret, mre); }
    ops ari::mul_eq() { bin_eq* ret = mem.new_object<bin_eq>("*="); return ops (ret, mre); }
    ops ari::div_eq() { bin_eq* ret = mem.new_object<bin_eq>("/="); return ops (ret, mre); }
    ops ari::mod_eq() { bin_eq* ret = mem.new_object<bin_eq>("%="); return ops (ret, mre); }

    ops ari::add() { bin* ret = mem.new_object<bin>("+"); return ops (ret, mre); }
    ops ari::sub() { bin* ret = mem.new_object<bin>("-"); return ops (ret, mre); }
    ops ari::mul() { bin* ret = mem.new_object<bin>("*"); return ops (ret, mre); }
    ops ari::div() { bin* ret = mem.new_object<bin>("/"); return ops (ret, mre); }
    ops ari::mod() { bin* ret = mem.new_object<bin>("%"); return ops (ret, mre); }
}