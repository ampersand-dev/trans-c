#ifndef AP_TRANS_C_VAR_HPP
#define AP_TRANS_C_VAR_HPP

#include <ap/trans/trans.hpp>
#include <ap/core/core.hpp>
#include <ap/meta/meta.hpp>

#include <string_view>
#include <string>

#include <optional>

namespace ap::trans::c                                      {
    class var                                               {
        template <typename... T> friend class ap::trans::var;
        using str_t = std::string;
        str_t type;
        str_t name;
        str_t str;
        var();
    public:
        
        std::string as_str();
        struct trait;
    };
}

namespace ap::trans::c                  {
    struct var::trait                   {
        using ret_t = std::optional<var>;
        using str_t = std::string_view;
        
        static ret_t pack(str_t, str_t);
        static ret_t err ();

        static ret_t f64 (str_t);
        static ret_t f32 (str_t);

        static ret_t u64 (str_t);
        static ret_t i64 (str_t);

        static ret_t u32 (str_t);
        static ret_t i32 (str_t);

        static ret_t u16 (str_t);
        static ret_t i16 (str_t);

        static ret_t u8  (str_t);
        static ret_t i8  (str_t);
    };
}

namespace ap::c                                 {
    using var = trans::var<trans::c::var::trait>;
}

#endif
