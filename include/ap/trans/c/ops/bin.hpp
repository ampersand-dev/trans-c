#ifndef AP_TRANS_C_OPS_BIN_HPP
#define AP_TRANS_C_OPS_BIN_HPP

#include "opc.hpp"
#include <ap/trans/c/ops.hpp>

#include <string_view>
#include <string>

namespace ap::trans::c           {
    class bin : public opc       {
        using str_t = std::string;
        str_t op1;
        str_t op2;
        str_t op;
    public:
        std::string as_str();
        bin (str_t);
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

    class bin_eq : public opc    {
        using str_t = std::string;
        str_t op1;
        str_t op2;
        str_t op;
    public:
        std::string as_str();
        bin_eq(str_t);
    public:
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

#endif
