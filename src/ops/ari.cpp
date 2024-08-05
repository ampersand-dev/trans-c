#include <ap/trans/c/ops/ari.hpp>
#include <ap/trans/c/ops.hpp>

namespace ap::trans::c {
    ops&
        ari::add_eq
            (ops& ops)                                       {
                if (ops.self.has_value() == false) return ops;
                if (ops.opc .has_value())          return ops;
                if (ops.arg .has_value())          return ops;
                if (ops.op  .has_value())          return ops;
                ops.opc = ap::opc::add_eq;

                ops.op = std::string ("+=");
                return ops;
    }

    ops&
        ari::sub_eq
            (ops& ops)                                       {
                if (ops.self.has_value() == false) return ops;
                if (ops.opc .has_value())          return ops;
                if (ops.arg .has_value())          return ops;
                if (ops.op  .has_value())          return ops;
                ops.opc = ap::opc::sub_eq;

                ops.op = std::string ("-=");
                return ops;
    }

    ops&
        ari::mul_eq
            (ops& ops)                                       {
                if (ops.self.has_value() == false) return ops;
                if (ops.opc .has_value())          return ops;
                if (ops.arg .has_value())          return ops;
                if (ops.op  .has_value())          return ops;
                ops.opc = ap::opc::mul_eq;

                ops.op = std::string ("*=");
                return ops;
    }

    ops&
        ari::div_eq
            (ops& ops)                                       {
                if (ops.self.has_value() == false) return ops;
                if (ops.opc .has_value())          return ops;
                if (ops.arg .has_value())          return ops;
                if (ops.op  .has_value())          return ops;
                ops.opc = ap::opc::div_eq;

                ops.op = std::string ("/=");
                return ops;
    }

    ops&
        ari::mod_eq
            (ops& ops)                                       {
                if (ops.self.has_value() == false) return ops;
                if (ops.opc .has_value())          return ops;
                if (ops.arg .has_value())          return ops;
                if (ops.op  .has_value())          return ops;
                ops.opc = ap::opc::mod_eq;

                ops.op = std::string ("%=");
                return ops;
    }

    ops&
        ari::add
            (ops& ops)                                       {
                if (ops.self.has_value() == false) return ops;
                if (ops.opc .has_value())          return ops;
                if (ops.arg .has_value())          return ops;
                if (ops.op  .has_value())          return ops;
                ops.opc = ap::opc::add;

                ops.op = std::string ("+");
                return ops;
    }

    ops&
        ari::sub
            (ops& ops)                                       {
                if (ops.self.has_value() == false) return ops;
                if (ops.opc .has_value())          return ops;
                if (ops.arg .has_value())          return ops;
                if (ops.op  .has_value())          return ops;
                ops.opc = ap::opc::sub;

                ops.op = std::string ("-");
                return ops;
    }

    ops&
        ari::mul
            (ops& ops)                                       {
                if (ops.self.has_value() == false) return ops;
                if (ops.opc .has_value())          return ops;
                if (ops.arg .has_value())          return ops;
                if (ops.op  .has_value())          return ops;
                ops.opc = ap::opc::mul;

                ops.op = std::string ("*");
                return ops;
    }

    ops&
        ari::div
            (ops& ops)                                       {
                if (ops.self.has_value() == false) return ops;
                if (ops.opc .has_value())          return ops;
                if (ops.arg .has_value())          return ops;
                if (ops.op  .has_value())          return ops;
                ops.opc = ap::opc::div;

                ops.op = std::string ("/");
                return ops;
    }

    ops&
        ari::mod
            (ops& ops)                                       {
                if (ops.self.has_value() == false) return ops;
                if (ops.opc .has_value())          return ops;
                if (ops.arg .has_value())          return ops;
                if (ops.op  .has_value())          return ops;
                ops.opc = ap::opc::mod;

                ops.op = std::string ("%");
                return ops;
    }
}