#ifndef AP_TRANS_C_FN_HPP
#define AP_TRANS_C_FN_HPP

#include <ap/trans/c/ops.hpp>
#include <ap/trans/trans.hpp>
#include <ap/meta/meta.hpp>

#include <optional>
#include <string_view>
#include <string>

#include <list>

namespace ap::trans::c           {
    class fn                     {
        using str_t = std::string;
        str_t name;
        str_t fret;
        str_t farg;
        str_t fsrc;
    public:
        fn(std::string_view);
        fn();
        std::string head();
        std::string all ();

        void arg(meta::type_id   , std::string_view);
        void arg(std::string_view, std::string_view);

        void ret(meta::type_id);
        void ret(std::string_view);

        void src(ops);
    };
}

namespace ap::c            {
    using fn = trans::c::fn;
}

#endif