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

namespace ap::trans::c                {
    struct var::trait                 {
        using str_t = std::string_view;
        using ret_t = var;

        static var pack(var&, str_t, str_t);

        static var f64 (var&, str_t);
        static var f32 (var&, str_t);

        static var u64 (var&, str_t);
        static var i64 (var&, str_t);

        static var u32 (var&, str_t);
        static var i32 (var&, str_t);

        static var u16 (var&, str_t);
        static var i16 (var&, str_t);

        static var u8  (var&, str_t);
        static var i8  (var&, str_t);
    };
}

#endif
