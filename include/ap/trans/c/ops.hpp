#ifndef AP_TRNAS_C_OPS_HPP
#define AP_TRNAS_C_OPS_HPP

#include <ap/trans/trans.hpp>
#include <ap/core/core.hpp>
#include <ap/meta/meta.hpp>

#include <ap/trans/c/c.hpp>

#include <string_view>
#include <string>
#include <variant>

namespace ap::trans::c      {
    class ops               {
        friend class boolean;
        friend class ari;
        friend class bit;
        friend class cmp;
        friend class ord;

        using str_t = std::optional<std::string>;
        using opc_t = std::optional<ap::opc>;
        str_t self;
        opc_t opc;
        str_t arg;
        str_t str;
        str_t op;

        ops();
    public:
        std::string as_str();
        struct trait;
    };
}

namespace ap::trans::c                    {
    struct ops::trait                     {
        using str_t = std::string_view;
        static c::ops self(c::ops&, c::ops);
        static c::ops self(c::ops&, str_t);

        static c::ops arg(c::ops&, c::ops);
        static c::ops arg(c::ops&, str_t);

        static c::ops ops();
    };
}

#endif