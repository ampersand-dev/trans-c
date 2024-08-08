#include <ap/trans/c/ops/func.hpp>
#include <ap/trans/c/ops.hpp>

namespace ap::trans::c {
    void
        func::call
            (ops& ops)                                   {
                if (ops.self.has_value() == false) return;
                if (ops.opc .has_value())          return;
                if (ops.op  .has_value())          return;

                ops.opc = ap::opc::call;
                return;
    }

    void
        func::ret
            (ops& ops)                                   {
                if (ops.self.has_value() == false) return;
                if (ops.opc .has_value())          return;
                if (ops.op  .has_value())          return;
                ops.opc = ap::opc::ret;
                
                std::string str;
                str += "return ";
                str += ops.self.value().first;
                
                ops.str = str;
                return;
    }
}