#include <ap/trans/c/ops.hpp>

namespace ap::trans::c                                   {
    std::string 
        do_call
            (ops& ops)                                      {
                if (ops.self.has_value() == false) return {};
                if (ops.opc .has_value() == false) return {};
                std::string str;

                str += ops.self
                          .value()
                          .first;

                str += '('; for (auto& arg : ops.arg) str += (arg.first + ", ");
                str += ')';

                ops.str = str;
                return    str;
    }
}

namespace ap::trans::c {
    ops::ops() 
        : self (std::nullopt),
          str  (std::nullopt) {
    }

    std::string
        ops::as_str()                                       {
                if (!self.has_value()) return std::string {};
                if (!opc .has_value()) return std::string {};
                if (str  .has_value()) return str.value();
                ap::opc     opc = this->opc.value();
                std::string str;

                if (opc == ap::opc::call) return do_call(*this);
                if (!op.has_value())      return std::string {};
                auto self = this->self.value();
                auto arg  = this->arg .front();
                
                if (opc == ap::opc::bool_not) goto not_bool;
                if (opc == ap::opc::bit_not)  goto not_bit;
                str += self.first;
                str += this->op.value();
                str += arg.first;

                this ->str = str;
                return str;

not_bool:       str +=  '!';
                str += self.first;

                this ->str = str;
                return str;
not_bit:        str += '~';
                str += self.first;

                this ->str = str;
                return str;
    }

    void
        ops::trait::self
            (c::ops& ops, c::ops self) {
                std::string str;
                str += '('; str += self.as_str();
                str += ')';

                if(!ops.self)                {
                    ops.self = var_t(str, {});
                    return;
                }

                auto var = ops.self.value();
                auto ret = var.first;
                ret += str;

                var.first = ret;
    }

    void
        ops::trait::self
            (c::ops& ops, str_t type, str_t self) {
                if (ops.self) return;
                ops.self = var_t (self, type);
    }

    void
        ops::trait::self
            (c::ops& ops, meta::type_id type, str_t self) {
                if (ops.self) return;
                ops.self = var_t (self, type);
    }

    void
        ops::trait::arg
            (c::ops& ops, c::ops arg)                    {
                if (ops.self.has_value() == false) return;
                if (ops.opc .has_value() == false) return;
                std::string str;

                str += '('; str += arg.as_str();
                str += ')';

                ops.arg.push_back (var_t (std::move(str), {}));
    }

    void
        ops::trait::arg
            (c::ops& ops, str_t type, str_t arg)         {
                if (ops.self.has_value() == false) return;
                if (ops.opc .has_value() == false) return;

                ops.arg.push_back (var_t (arg, type));
    }

    void
        ops::trait::arg
            (c::ops& ops, meta::type_id type, str_t arg) {
                if (ops.self.has_value() == false) return;
                if (ops.opc .has_value() == false) return;

                ops.arg.push_back (var_t (arg, type));
    }

    c::ops
        ops::trait::ops()   {
            return c::ops {};
    }
}