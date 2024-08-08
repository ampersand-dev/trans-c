#include <ap/trans/c/ops/bit.hpp>
#include <ap/trans/c/ops.hpp>

namespace ap::trans::c {
    ops&
        bit::bit_and_eq
            (ops& ops)                                       {
                if (ops.self.has_value() == false) return ops;
                if (ops.opc .has_value())          return ops;
                if (ops.op  .has_value())          return ops;
                ops.opc = ap::opc::bit_and_eq;

                ops.op = std::string ("&=");
                return ops;
    }

    ops&
        bit::bit_or_eq
            (ops& ops)                                       {
                if (ops.self.has_value() == false) return ops;
                if (ops.opc .has_value())          return ops;
                if (ops.op  .has_value())          return ops;
                ops.opc = ap::opc::bit_or_eq;

                ops.op = std::string ("|=");
                return ops;
    }

    ops&
        bit::bit_xor_eq
            (ops& ops)                                       {
                if (ops.self.has_value() == false) return ops;
                if (ops.opc .has_value())          return ops;
                if (ops.op  .has_value())          return ops;
                ops.opc = ap::opc::bit_xor_eq;

                ops.op = std::string ("^=");
                return ops;
    }

    ops&
        bit::bit_and
            (ops& ops)                                       {
                if (ops.self.has_value() == false) return ops;
                if (ops.opc .has_value())          return ops;
                if (ops.op  .has_value())          return ops;
                ops.opc = ap::opc::bit_and;

                ops.op = std::string ("&");
                return ops;
    }

    ops&
        bit::bit_or
            (ops& ops)                                       {
                if (ops.self.has_value() == false) return ops;
                if (ops.opc .has_value())          return ops;
                if (ops.op  .has_value())          return ops;
                ops.opc = ap::opc::bit_or;

                ops.op = std::string ("|");
                return ops;
    }

    ops&
        bit::bit_xor
            (ops& ops)                                       {
                if (ops.self.has_value() == false) return ops;
                if (ops.opc .has_value())          return ops;
                if (ops.op  .has_value())          return ops;
                ops.opc = ap::opc::bit_xor;

                ops.op = std::string ("^");
                return ops;
    }

    ops&
        bit::bit_not
            (ops& ops)                                       {
                if (ops.self.has_value() == false) return ops;
                if (ops.opc .has_value())          return ops;
                if (ops.op  .has_value())          return ops;
                ops.opc = ap::opc::bit_not;
                ops.op  = std::string("~");

                return ops;
    }

    ops&
        bit::bit_shl
            (ops& ops)                                       {
                if (ops.self.has_value() == false) return ops;
                if (ops.opc .has_value())          return ops;
                if (ops.op  .has_value())          return ops;
                ops.opc = ap::opc::bit_shl;

                ops.op = std::string ("<<");
                return ops;
    }

    ops&
        bit::bit_shr
            (ops& ops)                                       {
                if (ops.self.has_value() == false) return ops;
                if (ops.opc .has_value())          return ops;
                if (ops.op  .has_value())          return ops;
                ops.opc = ap::opc::bit_shr;

                ops.op  = std::string(">>");
                return ops;
    }
}