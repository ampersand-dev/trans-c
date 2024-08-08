#include <ap/trans/c/ops/cmp.hpp>
#include <ap/trans/c/ops.hpp>

namespace ap::trans::c {
    ops&
        cmp::cmp_eq
            (ops& ops)                                       {
                if (ops.self.has_value() == false) return ops;
                if (ops.opc .has_value())          return ops;
                if (ops.op  .has_value())          return ops;
                ops.opc = ap::opc::cmp_eq;

                ops.op = std::string ("==");
                return ops;
    }

    ops&
        cmp::cmp_ne
            (ops& ops)                                       {
                if (ops.self.has_value() == false) return ops;
                if (ops.opc .has_value())          return ops;
                if (ops.op  .has_value())          return ops;
                ops.opc = ap::opc::cmp_ne;

                ops.op = std::string ("!=");
                return ops;
    }
}