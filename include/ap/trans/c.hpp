#ifndef AP_TRANS_C_HPP
#define AP_TRANS_C_HPP

#include "c/fn.hpp"
#include "c/ops.hpp"
#include "c/pack.hpp"
#include "c/var.hpp"

#include "c/ops/ari.hpp"
#include "c/ops/bin.hpp"
#include "c/ops/bit.hpp"
#include "c/ops/boolean.hpp"
#include "c/ops/cmp.hpp"
#include "c/ops/control.hpp"
#include "c/ops/func.hpp"
#include "c/ops/mem.hpp"
#include "c/ops/opc.hpp"
#include "c/ops/ord.hpp"
#include "c/ops/uni.hpp"

#include <ap/trans.hpp>
#include <ap/trait.hpp>
#include <ap/meta.hpp>
#include <ap/core.hpp>
#include <ap/grammar.hpp>

namespace ap::c               {
    auto ops()                {
        return ap::trans::ops (
            ap::c::boolean(),
            ap::c::control(),
            ap::c::func(),
            ap::c::ari(),
            ap::c::bit(),
            ap::c::cmp(),
            ap::c::ord(),
            ap::c::mem()
        );
    }

    auto pack()                                   {
        return ap::trans::pack <trans::c::pack> ();
    }
}

#endif
