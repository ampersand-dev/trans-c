#include <ap/trans/c/ops/opc.hpp>

namespace ap::trans::c                                 {
    void opc::arg(meta::type_id, len_t, str_t, str_t) {} // For Fundamental Type Array Reference (Self : Compound Type)
    void opc::arg(str_t        , len_t, str_t, str_t) {} // For Compound Type Array Reference (Self : Compound Type)

    void opc::arg(meta::type_id, str_t, str_t) {} // For Fundamental Type Variable Reference (Self : Compound Type)
    void opc::arg(str_t        , str_t, str_t) {} // For Compound Type Variable Reference (Self : Compound Type)

    void opc::arg(meta::type_id, len_t, str_t) {} // For Fundamental Type Array
    void opc::arg(str_t        , len_t, str_t) {} // For Compound Type Array

    void opc::arg(meta::type_id, str_t) {} // For Fundamental Type Variable
    void opc::arg(str_t        , str_t) {} // For Compound Type Variable

    void opc::arg(std::uint64_t) {}
    void opc::arg(std::uint32_t) {}
    void opc::arg(std::uint16_t) {}
    void opc::arg(std::uint8_t)  {}

    void opc::arg(std::int64_t) {}
    void opc::arg(std::int32_t) {}
    void opc::arg(std::int16_t) {}
    void opc::arg(std::int8_t)  {}

    void opc::arg(double) {}
    void opc::arg(float)  {}

    void opc::arg(ops&) {}
    void opc::src(ops&) {}

    std::string opc::as_str() { return {}; }
}