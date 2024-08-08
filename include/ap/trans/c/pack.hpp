#ifndef AP_TRANS_C_PACK_HPP
#define AP_TRANS_C_PACK_HPP

#include <ap/trans/c/c.hpp>
#include <ap/trans/trans.hpp>

#include <optional>

#include <filesystem>
#include <fstream>

#include <string_view>
#include <string>

namespace ap::trans::c           {
    class pack                   {
        using str_t = std::string;
        str_t name;
        str_t str;
    public:
        std::fstream as_file(std::filesystem::path);
        std::string  as_str ();
        struct trait;  
    };
}

namespace ap::trans::c                {
    struct pack::trait                {
        using str_t = std::string_view;
        using ret_t = void;
        static pack make(str_t);

        static void var (pack&, str_t, str_t);

        static void f64 (pack&, str_t);
        static void f32 (pack&, str_t);

        static void i64 (pack&, str_t);
        static void u64 (pack&, str_t);

        static void i32 (pack&, str_t);
        static void u32 (pack&, str_t);

        static void i16 (pack&, str_t);
        static void u16 (pack&, str_t);

        static void i8  (pack&, str_t);
        static void u8  (pack&, str_t);
    };
}

namespace ap::c                                    {
    using pack = trans::pack<trans::c::pack::trait>;
}

#endif
