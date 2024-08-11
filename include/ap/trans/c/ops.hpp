#ifndef AP_TRNAS_C_OPS_HPP
#define AP_TRNAS_C_OPS_HPP

#include <ap/trans/trans.hpp>
#include <ap/core/core.hpp>
#include <ap/meta/meta.hpp>

#include <ap/trans/c/c.hpp>

#include <string_view>
#include <string>

#include <optional>
#include <variant>
#include <list>

#include "ops/opc.hpp"

namespace ap::trans::c       {
    class ops                {
        friend class boolean;
        friend class control;
        friend class func;
        friend class mem;
        friend class ari;
        friend class bit;
        friend class cmp;
        friend class ord;

        using mem_t = std::pmr::polymorphic_allocator<>;
        using opc_t = c::opc*;
        mem_t mem;
        opc_t opc;
        ops (opc_t, std::pmr::memory_resource*);
        ops (opc_t);
    public:
        ops(const ops&);
        ops(ops&&);
        ~ops();
    public:
        std::string as_str();

        using str_t = std::string_view;
        using len_t = std::uint64_t;

        void arg(std::floating_point auto arg) { return opc->arg(arg); }
        void arg(std::integral       auto arg) { return opc->arg(arg); }
        
        void arg(meta::type_id, len_t, str_t, str_t);
        void arg(str_t        , len_t, str_t, str_t);

        void arg(meta::type_id, str_t, str_t);
        void arg(str_t        , str_t, str_t);

        void arg(meta::type_id, len_t, str_t);
        void arg(str_t        , len_t, str_t);

        void arg(meta::type_id, str_t);
        void arg(str_t        , str_t);

        void arg(ops);
        void src(ops);
        
    };
}

#endif