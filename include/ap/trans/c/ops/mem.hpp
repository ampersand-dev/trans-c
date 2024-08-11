#ifndef AP_TRANC_C_OPS_MEM_HPP
#define AP_TRANC_C_OPS_MEM_HPP

#include <ap/trans/trans.hpp>
#include <ap/core/core.hpp>
#include <ap/meta/meta.hpp>

#include <ap/trans/c/ops.hpp>

namespace ap::trans::c                                 {
    class mem                                          {
        using mem_t = std::pmr::polymorphic_allocator<>;
        using mre_t = std::pmr::memory_resource*;
        mre_t mre;
        mem_t alo;
    public:
        using str_t = std::string_view;
        class move;
        class push;
        class pop;
        class idx;

        mem(std::pmr::memory_resource*);
        mem();

        ops push();
        ops move();
        ops pop ();
        ops idx ();
    };
}

namespace ap::trans::c           {
    class mem::move : public opc {
        using str_t = std::string;
        str_t op1;
        str_t op2;
    public:
        std::string as_str();

        void arg(meta::type_id   , std::string_view);
        void arg(std::string_view, std::string_view);

        void arg(std::uint64_t);
        void arg(std::uint32_t);
        void arg(std::uint16_t);
        void arg(std::uint8_t);

        void arg(std::int64_t);
        void arg(std::int32_t);
        void arg(std::int16_t);
        void arg(std::int8_t);

        void arg(double);
        void arg(float);

        void arg(ops&);
    };

    class mem::push : public opc {
        using str_t = std::string;
        str_t op;
    public:
        std::string as_str();

        void arg(meta::type_id   , std::uint64_t, std::string_view);
        void arg(std::string_view, std::uint64_t, std::string_view);

        void arg(meta::type_id   , std::string_view);
        void arg(std::string_view, std::string_view);
    };

    class mem::pop : public opc  {
        using str_t = std::string;
        str_t op;
    public:
    };

    class mem::idx : public opc  {
        using str_t = std::string;
        str_t op1;
        str_t op2;
    public:
        std::string as_str();

        void arg(meta::type_id   , std::uint64_t, std::string_view);
        void arg(std::string_view, std::uint64_t, std::string_view);

        void arg(std::uint64_t);
        void arg(std::uint32_t);
        void arg(std::uint16_t);
        void arg(std::uint8_t);

        void arg(std::int64_t);
        void arg(std::int32_t);
        void arg(std::int16_t);
        void arg(std::int8_t);

        void arg(double);
        void arg(float);

        void arg(ops&);
        void src(ops&);
    };
}

namespace ap::c                  {
    using mem = ap::trans::c::mem;
}

#endif
