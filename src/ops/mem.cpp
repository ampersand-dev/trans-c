#include <ap/trans/c/ops/mem.hpp>
#include <ap/trans/c/ops.hpp>

namespace ap::trans::c                       {
    mem::mem(std::pmr::memory_resource* mre)
        : mre (mre),
          alo (mre)
            {}

    mem::mem()
        : mre (std::pmr::get_default_resource()),
          alo (std::pmr::get_default_resource())
            {}
}

namespace ap::trans::c {
    std::string 
        mem::push::as_str() {
            return op;
    }

    void 
        mem::push::arg
            (meta::type_id idx, std::uint64_t len, std::string_view name) {
                if (!op.empty()) return;
                str_t type;

                switch (idx)                                                    {
                    case meta::type_id::f64: type = "double ";             break;
                    case meta::type_id::f32: type = "float ";              break;

                    case meta::type_id::u64: type = "unsigned long long "; break;
                    case meta::type_id::u32: type = "unsigned int ";       break;
                    case meta::type_id::u16: type = "unsigned short ";     break;
                    case meta::type_id::u8 : type = "unsigned char ";      break;

                    case meta::type_id::i64: type = "long long ";          break;
                    case meta::type_id::i32: type = "int ";                break;
                    case meta::type_id::i16: type = "short ";              break;
                    case meta::type_id::i8:  type = "char ";               break;
                }

                op += type;
                op += name;
                op +=  "["; op += std::to_string(len);
                op +=  "]";
    }

    void 
        mem::push::arg
            (std::string_view type, std::uint64_t len, std::string_view name) {
                if (!op.empty()) return;
                op += "struct ";
                op += type;
                op += " ";

                op += name;
                op +=  "["; op += std::to_string(len);
                op +=  "]";
    }

    void 
        mem::push::arg
            (meta::type_id idx, std::string_view name) {
                if (!op.empty()) return;
                str_t type;

                switch (idx)                                                    {
                    case meta::type_id::f64: type = "double ";             break;
                    case meta::type_id::f32: type = "float ";              break;

                    case meta::type_id::u64: type = "unsigned long long "; break;
                    case meta::type_id::u32: type = "unsigned int ";       break;
                    case meta::type_id::u16: type = "unsigned short ";     break;
                    case meta::type_id::u8 : type = "unsigned char ";      break;

                    case meta::type_id::i64: type = "long long ";          break;
                    case meta::type_id::i32: type = "int ";                break;
                    case meta::type_id::i16: type = "short ";              break;
                    case meta::type_id::i8:  type = "char ";               break;
                }

                op += type;
                op += name;
    }

    void 
        mem::push::arg
            (std::string_view type, std::string_view name) {
                if (!op.empty()) return;
                op += "struct ";
                op += type;
                op += " ";

                op += name;
    }
}

namespace ap::trans::c {
    std::string 
        mem::move::as_str()           {
            if (op1.empty()) return {};
            if (op2.empty()) return {};
            return op1 
                 + " = "
                 + op2;
    }

    void 
        mem::move::arg
            (meta::type_id idx, std::string_view name) {
                if (op1.empty()) goto op1;
                if (op2.empty()) goto op2;
                return;

        op1:    op1 += name;
                return;
        op2:    op2 += name;
                return;
    }

    void 
        mem::move::arg
            (std::string_view type, std::string_view name) {
                if (op1.empty()) goto op1;
                if (op2.empty()) goto op2;
                return;

        op1:    op1 += name;
                return;
        op2:    op2 += name;
                return;
    }

    void 
        mem::move::arg
            (std::uint64_t arg)                 {
                if (op2.empty() == false) return;
                if (op1.empty())          return;
                op2 = std::to_string (arg);
    }

    void 
        mem::move::arg
            (std::uint32_t arg)                 {
                if (op2.empty() == false) return;
                if (op1.empty())          return;
                op2 = std::to_string (arg);
    }

    void 
        mem::move::arg
            (std::uint16_t arg)                 {
                if (op2.empty() == false) return;
                if (op1.empty())          return;
                op2 = std::to_string (arg);
    }

    void 
        mem::move::arg
            (std::uint8_t arg)                  {
                if (op2.empty() == false) return;
                if (op1.empty())          return;
                op2 = std::to_string (arg);
    }

    void 
        mem::move::arg
            (std::int64_t arg)                  {
                if (op2.empty() == false) return;
                if (op1.empty())          return;
                op2 = std::to_string (arg);
    }

    void 
        mem::move::arg
            (std::int32_t arg)                  {
                if (op2.empty() == false) return;
                if (op1.empty())          return;
                op2 = std::to_string (arg);
    }

    void 
        mem::move::arg
            (std::int16_t arg)                  {
                if (op2.empty() == false) return;
                if (op1.empty())          return;
                op2 = std::to_string (arg);
    }

    void 
        mem::move::arg
            (std::int8_t arg)                   {
                if (op2.empty() == false) return;
                if (op1.empty())          return;
                op2 = std::to_string (arg);
    }

    void 
        mem::move::arg
            (double arg)                        {
                if (op2.empty() == false) return;
                if (op1.empty())          return;
                op2 = std::to_string (arg);
    }

    void 
        mem::move::arg
            (float arg)                         {
                if (op2.empty() == false) return;
                if (op1.empty())          return;
                op2 = std::to_string (arg);
    }

    void 
        mem::move::arg
            (ops& arg)                      {
                if (op1.empty()) goto do_op1;
                if (op2.empty()) goto do_op2;
                return;
        do_op1: op1 += "("; op1 += arg.as_str();
                op1 += ")";
                return;

        do_op2: op2 += "("; op2 += arg.as_str();
                op2 += ")";
                return;
    }
}

namespace ap::trans::c {
    std::string 
        mem::idx::as_str()           {
            if (op1.empty()) return {};
            if (op2.empty()) return {};
            std::string ret;

            ret = op1;
            ret += "["; ret += op2;
            ret += "]";

            return ret;
    }

    void 
        mem::idx::arg
            (meta::type_id idx, std::uint64_t len, std::string_view name) {
                if (op1.empty()) goto op1;
                if (op2.empty()) goto op2;
                return;

        op1:    op1 += name;
                return;
        op2:    op2 += name;
                return;
    }

    void 
        mem::idx::arg
            (std::string_view type, std::uint64_t len, std::string_view name) {
                if (op1.empty()) goto op1;
                if (op2.empty()) goto op2;
                return;

        op1:    op1 += name;
                return;
        op2:    op2 += name;
                return;
    }

    void 
        mem::idx::arg
            (std::uint64_t arg)                 {
                if (op2.empty() == false) return;
                if (op1.empty())          return;
                op2 = std::to_string (arg);
    }

    void 
        mem::idx::arg
            (std::uint32_t arg)                 {
                if (op2.empty() == false) return;
                if (op1.empty())          return;
                op2 = std::to_string (arg);
    }

    void 
        mem::idx::arg
            (std::uint16_t arg)                 {
                if (op2.empty() == false) return;
                if (op1.empty())          return;
                op2 = std::to_string (arg);
    }

    void 
        mem::idx::arg
            (std::uint8_t arg)                  {
                if (op2.empty() == false) return;
                if (op1.empty())          return;
                op2 = std::to_string (arg);
    }

    void 
        mem::idx::arg
            (std::int64_t arg)                  {
                if (op2.empty() == false) return;
                if (op1.empty())          return;
                op2 = std::to_string (arg);
    }

    void 
        mem::idx::arg
            (std::int32_t arg)                  {
                if (op2.empty() == false) return;
                if (op1.empty())          return;
                op2 = std::to_string (arg);
    }

    void 
        mem::idx::arg
            (std::int16_t arg)                  {
                if (op2.empty() == false) return;
                if (op1.empty())          return;
                op2 = std::to_string (arg);
    }

    void 
        mem::idx::arg
            (std::int8_t arg)                   {
                if (op2.empty() == false) return;
                if (op1.empty())          return;
                op2 = std::to_string (arg);
    }

    void mem::idx::arg(double) {}
    void mem::idx::arg(float)  {}

    void 
        mem::idx::arg
            (ops& arg)                          {
                if (op2.empty() == false) return;
                if (op1.empty())          return;

                op2 += "("; op2 += arg.as_str();
                op2 += ")";
    }

    void mem::idx::src(ops&) {}
}

namespace ap::trans::c                                                                       {
    ops mem::move() { class move* ret = alo.new_object<class move>(); return ops (ret, mre); }
    ops mem::push() { class push* ret = alo.new_object<class push>(); return ops (ret, mre); }
    ops mem::pop () { class pop*  ret = alo.new_object<class pop> (); return ops (ret, mre); }
    ops mem::idx () { class idx*  ret = alo.new_object<class idx> (); return ops (ret, mre); }
}