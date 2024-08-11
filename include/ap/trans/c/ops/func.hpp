#ifndef AP_TRANS_C_FUNC_HPP
#define AP_TRANS_C_FUNC_HPP

#include <ap/trans/trans.hpp>
#include <ap/core/core.hpp>
#include <ap/meta/meta.hpp>

#include <ap/trans/c/ops.hpp>
#include <string_view>

namespace ap::trans::c                                 {
    class func                                         {
        using mem_t = std::pmr::polymorphic_allocator<>;
        using mre_t = std::pmr::memory_resource*;
        mre_t mre;
        mem_t mem;
    public:
        func(std::pmr::memory_resource*);
        func();
    public:
        using str_t = std::string_view;
        class call;
        class ret;

        ops call();
        ops ret ();
    };
}

namespace ap::trans::c            {
    class func::call : public opc {
        using str_t = std::string;
        str_t func;
        str_t str;
    public:
        std::string as_str();
        call();
    public:
        void arg(meta::type_id   , std::string_view, std::string_view);
        void arg(std::string_view, std::string_view, std::string_view);

        void arg(meta::type_id   , std::string_view);
        void arg(std::string_view, std::string_view);

        void arg(std::uint64_t);
        void arg(std::uint32_t);
        void arg(std::uint16_t);
        void arg(std::uint8_t) ;

        void arg(std::int64_t) ;
        void arg(std::int32_t) ;
        void arg(std::int16_t) ;
        void arg(std::int8_t)  ;

        void arg(double);
        void arg(float) ;

        void arg(ops&);
    };

    class func::ret : public opc {
        using str_t = std::string;
        str_t str;
    public:
        std::string as_str();
        ret();
    public:
        void arg(meta::type_id   , std::string_view, std::string_view);
        void arg(std::string_view, std::string_view, std::string_view);

        void arg(meta::type_id   , std::string_view);
        void arg(std::string_view, std::string_view);

        void arg(std::uint64_t);
        void arg(std::uint32_t);
        void arg(std::uint16_t);
        void arg(std::uint8_t) ;

        void arg(std::int64_t) ;
        void arg(std::int32_t) ;
        void arg(std::int16_t) ;
        void arg(std::int8_t)  ;

        void arg(double);
        void arg(float) ;

        void arg(ops&);
        void src(ops&);
    };
}

namespace ap::c                    {
    using func = ap::trans::c::func;
}

#endif
