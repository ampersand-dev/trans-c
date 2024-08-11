#ifndef AP_TRANS_C_OPS_OPC_HPP
#define AP_TRANS_C_OPS_OPC_HPP

#include <ap/trait.hpp>

#include <ap/trans/c/c.hpp>
#include <ap/meta/meta.hpp>

#include <string_view>

namespace ap::trans::c                                          {
    struct opc                                                  {
        using str_t = std::string_view;
        using len_t = std::uint64_t;
        
        virtual void arg(meta::type_id, len_t, str_t, str_t); // For Fundamental Type Array Reference (Self : Compound Type)
        virtual void arg(str_t        , len_t, str_t, str_t); // For Compound Type Array Reference (Self : Compound Type)

        virtual void arg(meta::type_id, str_t, str_t); // For Fundamental Type Variable Reference (Self : Compound Type)
        virtual void arg(str_t        , str_t, str_t); // For Compound Type Variable Reference (Self : Compound Type)

        virtual void arg(meta::type_id, len_t, str_t); // For Fundamental Type Array
        virtual void arg(str_t        , len_t, str_t); // For Compound Type Array

        virtual void arg(meta::type_id, str_t); // For Fundamental Type Variable
        virtual void arg(str_t        , str_t); // For Compound Type Variable

        virtual void arg(std::uint64_t);
        virtual void arg(std::uint32_t);
        virtual void arg(std::uint16_t);
        virtual void arg(std::uint8_t) ;

        virtual void arg(std::int64_t) ;
        virtual void arg(std::int32_t) ;
        virtual void arg(std::int16_t) ;
        virtual void arg(std::int8_t)  ;

        virtual void arg(double);
        virtual void arg(float) ;

        virtual void arg(ops&);
        virtual void src(ops&);

        virtual std::string as_str();
    };
}

#endif
