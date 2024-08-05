#include <ap/trans/c/ops.hpp>

namespace ap::trans::c {
    ops::ops() 
        : self (std::nullopt),
          arg  (std::nullopt),
          str  (std::nullopt) {
    }

    std::string
        ops::as_str()                           {
                if (!self.has_value()) return {};
                if (!opc .has_value()) return {};
                if (!str .has_value()) return {};
                if (!op  .has_value()) return {};
                return str.value();
    }

    c::ops
        ops::trait::self
            (c::ops& ops, c::ops self)   {
                if (!self.str) return ops;
                if (ops.self)  return ops;
                std::string str;

                str += '('; str += self.str.value();
                str += ')';

                ops.self = str;
                return ops;
    }

    c::ops
        ops::trait::self
            (c::ops& ops, str_t self)   {
                if (ops.self) return ops;
                ops.self = self;
                return ops;
    }

    c::ops
        ops::trait::arg
            (c::ops& ops, c::ops arg)                        {
                if (ops.self.has_value() == false) return ops;
                if (ops.opc .has_value() == false) return ops;
                if (ops.arg .has_value())          return ops;
                if (arg.str)                       return ops;
                std::string str;

                str += '('; str += arg.str.value();
                str += ')';

                ops.arg = str;
                ops.str = ops.self.value()
                        + ops.op  .value()
                        + str;
                return ops;
    }

    c::ops
        ops::trait::arg
            (c::ops& ops, str_t arg)                         {
                if (ops.self.has_value() == false) return ops;
                if (ops.opc .has_value() == false) return ops;
                if (ops.arg .has_value())          return ops;
                std::string str (arg);

                ops.arg = str;
                ops.str = ops.self.value()
                        + ops.op  .value()
                        + str;

                return ops;
    }

    c::ops
        ops::trait::ops()   {
            return c::ops {};
    }

    
}