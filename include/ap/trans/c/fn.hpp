#ifndef AP_TRANS_C_FN_HPP
#define AP_TRANS_C_FN_HPP

#include <ap/trans/c/c.hpp>
#include <ap/trans/trans.hpp>
#include <ap/meta/meta.hpp>

#include <optional>
#include <string_view>
#include <string>

#include <list>

namespace ap::trans::c                       {
    class fn                                 {
        using arg_t = std::list <std::string>;
        using str_t = std::string;
        str_t name;
        str_t ret;
        arg_t arg;
        str_t src;

        fn(std::string_view);
    public:
        std::string as_str();
        struct trait;
    };
}

namespace ap::trans::c                {
    struct fn::trait                  {
        using str_t = std::string_view;

        static fn make(str_t);

        static void arg (fn&, meta::type_id, str_t);
        static void arg (fn&, str_t, str_t);

        static void ret (fn&, meta::type_id);
        static void ret (fn&, str_t);

        static void src(fn&, ops);
    };
}

namespace ap::c                   {
    using fn = trans::c::fn::trait;
}

#endif
