#include <ap/trans/c/ops/boolean.hpp>
#include <ap/trans/c/ops.hpp>

namespace ap::trans::c {
    ops&
        boolean::bool_and
            (ops& ops)                                       {
                if (ops.self.has_value() == false) return ops;
                if (ops.opc .has_value())          return ops;
                if (ops.op  .has_value())          return ops;
                ops.opc = ap::opc::bool_and;

                ops.op = std::string ("&&");
                return ops;
    }

    ops&
        boolean::bool_or
            (ops& ops)                                       {
                if (ops.self.has_value() == false) return ops;
                if (ops.opc .has_value())          return ops;
                if (ops.op  .has_value())          return ops;
                ops.opc = ap::opc::bool_or;

                ops.op = std::string ("||");
                return ops;
    }

    ops&
        boolean::bool_not
            (ops& ops)                                       {
                if (ops.self.has_value() == false) return ops;
                if (ops.opc .has_value())          return ops;
                if (ops.op  .has_value())          return ops;
                ops.opc = ap::opc::bool_and;

                ops.op = std::string ("!");
                return ops;
    }
}