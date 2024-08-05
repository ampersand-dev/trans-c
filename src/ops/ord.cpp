#include <ap/trans/c/ops/ord.hpp>
#include <ap/trans/c/ops.hpp>

namespace ap::trans::c {
    ops&
        ord::ord_gt
            (ops& ops)                                       {
                if (ops.self.has_value() == false) return ops;
                if (ops.opc .has_value())          return ops;
                if (ops.arg .has_value())          return ops;
                if (ops.op  .has_value())          return ops;
                ops.opc = ap::opc::ord_gt;

                ops.op = std::string (">");
                return ops;
    }

    ops&
        ord::ord_ge
            (ops& ops)                                       {
                if (ops.self.has_value() == false) return ops;
                if (ops.opc .has_value())          return ops;
                if (ops.arg .has_value())          return ops;
                if (ops.op  .has_value())          return ops;
                ops.opc = ap::opc::ord_ge;

                ops.op = std::string (">=");
                return ops;
    }

    ops&
        ord::ord_lt
            (ops& ops)                                       {
                if (ops.self.has_value() == false) return ops;
                if (ops.opc .has_value())          return ops;
                if (ops.arg .has_value())          return ops;
                if (ops.op  .has_value())          return ops;
                ops.opc = ap::opc::ord_lt;

                ops.op = std::string ("<");
                return ops;
    }

    ops&
        ord::ord_le
            (ops& ops)                                       {
                if (ops.self.has_value() == false) return ops;
                if (ops.opc .has_value())          return ops;
                if (ops.arg .has_value())          return ops;
                if (ops.op  .has_value())          return ops;
                ops.opc = ap::opc::ord_le;

                ops.op = std::string ("<=");
                return ops;
    }
}