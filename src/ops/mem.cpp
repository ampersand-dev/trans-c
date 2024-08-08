#include <ap/trans/c/ops/mem.hpp>
#include <ap/trans/c/ops.hpp>

namespace ap::trans::c {
    ops&
        mem::move
            (ops& ops)                                       {
                if (ops.self.has_value() == false) return ops;
                if (ops.opc .has_value())          return ops;
                if (ops.op  .has_value())          return ops;
                ops.opc = ap::opc::move;

                ops.op = std::string ("=");
                return ops; 
    }

    ops&
        mem::push
            (ops& ops)                                       {
                if (ops.self.has_value() == false) return ops;
                if (ops.opc .has_value())          return ops;
                if (ops.op  .has_value())          return ops;
                ops.opc = ap::opc::push;
                std::string str;

                auto& self = ops.self.value(). first;
                auto& type = ops.self.value().second;

                if (type.index() == 1) {
                    str += "struct ";
                    str += std::get<1>(type);
                         + " "
                         + self;

                    ops.str = str;
                    return    ops;
                }

                auto id = std::get<0> (type);
                if (id == meta::type_id::f64) str += "double ";
                if (id == meta::type_id::f32) str += "float ";

                if (id == meta::type_id::u64) str += "unsigned long long ";
                if (id == meta::type_id::u32) str += "unsigned int ";
                if (id == meta::type_id::u16) str += "unsigned short ";
                if (id == meta::type_id::u8)  str += "unsigned char ";
                
                if (id == meta::type_id::i64) str += "long long ";
                if (id == meta::type_id::i32) str += "int ";
                if (id == meta::type_id::i16) str += "short ";
                if (id == meta::type_id::i8)  str += "char ";
                str += self;
                
                ops.str = str;
                return ops; 
    }

    ops&
        mem::pop(ops& ops) {
            return ops;
    }
}