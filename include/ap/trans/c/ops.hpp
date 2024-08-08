#ifndef AP_TRNAS_C_OPS_HPP
#define AP_TRNAS_C_OPS_HPP

#include <ap/core/core.hpp>
#include <ap/meta/meta.hpp>
#include <ap/trans/trans.hpp>

#include <ap/trans/c/c.hpp>

#include <string_view>
#include <string>

#include <optional>
#include <variant>
#include <list>

#include "ops/boolean.hpp"
#include "ops/func.hpp"
#include "ops/ari.hpp"
#include "ops/bit.hpp"
#include "ops/cmp.hpp"
#include "ops/ord.hpp"
#include "ops/mem.hpp"

namespace ap::trans::c       {
    class ops                {
        friend struct boolean;
        friend struct func;
        friend struct mem;
        friend struct ari;
        friend struct bit;
        friend struct cmp;
        friend struct ord;

        using var_t = std::pair<std::string, std::variant<meta::type_id, std::string_view>>;
        using str_t = std::optional<std::string>;

        using opc_t = std::optional<ap::opc>;
        using ope_t = std::optional<var_t>;
        using arg_t = std::list    <var_t>;

        friend std::string do_call(ops&);
        ope_t self;
        opc_t opc;
        arg_t arg;
        str_t str;
        str_t op;

        ops();
    public:
        std::string as_str();
        struct trait;
    };
}

namespace ap::trans::c                                   {
    struct ops::trait                                    {
        using str_t = std::string_view;
        static void self(c::ops&, meta::type_id, str_t);
        static void self(c::ops&, str_t, str_t);
        static void self(c::ops&, c::ops);

        static void arg(c::ops&, meta::type_id, str_t);
        static void arg(c::ops&, str_t, str_t);
        static void arg(c::ops&, c::ops);

        template <std::floating_point T> static void self(c::ops&, T);
        template <std::integral T>       static void self(c::ops&, T);

        template <std::floating_point T> static void arg (c::ops&, T);
        template <std::integral T>       static void arg (c::ops&, T);
        
        static c::ops ops();
    };
}

namespace ap::trans::c                                   {
    template <std::floating_point T> 
    void 
        ops::trait::self
            (c::ops& ops, T self)    {
                meta::type_id id;

                if constexpr (std::same_as<T, double>) id = meta::type_id::f64;
                if constexpr (std::same_as<T, float>)  id = meta::type_id::f32;
                ops.self = var_t (std::to_string(self), id);
    }
    
    template <std::integral T> 
    void 
        ops::trait::self
            (c::ops& ops, T self)    {
                meta::type_id id;

                if constexpr (std::same_as<T, std::uint64_t>) id = meta::type_id::u64;
                if constexpr (std::same_as<T, std::uint32_t>) id = meta::type_id::u32;
                if constexpr (std::same_as<T, std::uint16_t>) id = meta::type_id::u16;
                if constexpr (std::same_as<T, std::uint8_t>)  id = meta::type_id::u8;

                if constexpr (std::same_as<T, std::int64_t>)  id = meta::type_id::i64;
                if constexpr (std::same_as<T, std::int32_t>)  id = meta::type_id::i32;
                if constexpr (std::same_as<T, std::int16_t>)  id = meta::type_id::i16;
                if constexpr (std::same_as<T, std::int8_t>)   id = meta::type_id::i8;
                ops.self = var_t (std::to_string (self), id);
    }


    template <std::floating_point T> 
    void 
        ops::trait::arg
            (c::ops& ops, T self)    {
                meta::type_id id;

                if constexpr (std::same_as<T, double>) id = meta::type_id::f64;
                if constexpr (std::same_as<T, float>)  id = meta::type_id::f32;
                ops.arg.push_back (var_t (std::to_string (self), id));
    }
    
    template <std::integral T> 
    void 
        ops::trait::arg
            (c::ops& ops, T self)    {
                meta::type_id id;

                if constexpr (std::same_as<T, std::uint64_t>) id = meta::type_id::u64;
                if constexpr (std::same_as<T, std::uint32_t>) id = meta::type_id::u32;
                if constexpr (std::same_as<T, std::uint16_t>) id = meta::type_id::u16;
                if constexpr (std::same_as<T, std::uint8_t>)  id = meta::type_id::u8;

                if constexpr (std::same_as<T, std::int64_t>)  id = meta::type_id::i64;
                if constexpr (std::same_as<T, std::int32_t>)  id = meta::type_id::i32;
                if constexpr (std::same_as<T, std::int16_t>)  id = meta::type_id::i16;
                if constexpr (std::same_as<T, std::int8_t>)   id = meta::type_id::i8;
                ops.arg.push_back (var_t (std::to_string (self), id));
    }
}

namespace ap::c                     {
    using ops = trans::c::ops::trait;
}

#endif