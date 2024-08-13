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
        pack(std::string_view);

        std::string  as_str ();

        void var (std::string_view, std::string_view);

        void f64 (std::string_view);
        void f32 (std::string_view);

        void i64 (std::string_view);
        void u64 (std::string_view);

        void i32 (std::string_view);
        void u32 (std::string_view);

        void i16 (std::string_view);
        void u16 (std::string_view);

        void i8  (std::string_view);
        void u8  (std::string_view);
    };
}

#endif
