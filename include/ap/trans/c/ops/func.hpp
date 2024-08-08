#ifndef AP_TRANS_C_FUNC_HPP
#define AP_TRANS_C_FUNC_HPP

#include <ap/trans/trans.hpp>
#include <ap/core/core.hpp>
#include <ap/meta/meta.hpp>

#include <ap/trans/c/c.hpp>
#include <string_view>

namespace ap::trans::c                {
    struct func                       {
        using str_t = std::string_view;
        void call(ops&);
        void ret (ops&);
    };
}

namespace ap::c                    {
    using func = ap::trans::c::func;
}

#endif
