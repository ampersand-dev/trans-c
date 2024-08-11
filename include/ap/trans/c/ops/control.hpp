#ifndef AP_TRANS_C_OPS_CONTROL_HPP
#define AP_TRANS_C_OPS_CONTROL_HPP

#include <ap/trans/trans.hpp>
#include <ap/core/core.hpp>
#include <ap/meta/meta.hpp>

#include <ap/trans/c/ops.hpp>

namespace ap::trans::c                                 {
    class control                                      {
        using mem_t = std::pmr::polymorphic_allocator<>;
        using mre_t = std::pmr::memory_resource*;
        mre_t mre;
        mem_t mem;
    public:
        control(std::pmr::memory_resource*);
        control();
    public:
        class loop_while;
        class loop_for;
        class cond;

        ops loop_while();
        ops loop_for  ();
        ops cond      ();
    };
}

namespace ap::trans::c                     {
    class control::loop_while : public opc {
        using str_t = std::string;
        str_t loop;
        str_t op1;
    public:
        std::string as_str();
        void arg(ops&);
        void src(ops&);
    };

    class control::loop_for : public opc {
        using str_t = std::string;
        str_t loop;
        str_t op1;
        str_t op2;
        str_t op3;
    public:
        std::string as_str();
        void arg(ops&);
        void src(ops&);
    };

    class control::cond : public opc {
        using str_t = std::string;
        str_t next;
        str_t cond;
        str_t op1;
    public:
        std::string as_str();
        void arg(ops&);
        void src(ops&);
    };
}

namespace ap::c                      {
    using control = trans::c::control;
}

#endif