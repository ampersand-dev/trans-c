#include <ap/trans/c/ops/bin.hpp>

namespace ap::trans::c {
    void
        bin::arg
            (meta::type_id id, std::string_view name, std::string_view self) {
                if (op1.empty()) goto op1;
                if (op2.empty()) goto op2;
                return;
        op1:    op1 += self;
                op1 +=  ".";
                op1 += name;
                return;
        op2:    op2 += self;
                op2 +=  ".";
                op2 += name;
                return;
    }

    void
        bin::arg
            (std::string_view type, std::string_view name, std::string_view self) {
                if (op1.empty()) goto op1;
                if (op2.empty()) goto op2;
                return;

        op1:    op1 += self;
                op1 +=  ".";
                op1 += name;
                return;
        op2:    op2 += self;
                op2 +=  ".";
                op2 += name;
                return;
    }

    void
        bin::arg
            (meta::type_id id, std::string_view name) {
                if (op1.empty()) goto op1;
                if (op2.empty()) goto op2;
                return;
        op1:    op1 = name;
                return;
        op2:    op2 = name;
                return;
    }

    void
        bin::arg
            (std::string_view type, std::string_view name) {
                if (op1.empty()) goto op1;
                if (op2.empty()) goto op2;
                return;
        op1:    op1 = name;
                return;
        op2:    op2 = name;
                return;
    }

    void
        bin::arg
            (std::uint64_t arg)          {
                if (op1.empty()) goto op1;
                if (op2.empty()) goto op2;
                return;
        op1:    op1 = std::to_string(arg);
                return;
        op2:    op2 = std::to_string(arg);
                return;
    }

    void
        bin::arg
            (std::uint32_t arg)          {
                if (op1.empty()) goto op1;
                if (op2.empty()) goto op2;
                return;
        op1:    op1 = std::to_string(arg);
                return;
        op2:    op2 = std::to_string(arg);
                return;
    }

    void
        bin::arg
            (std::uint16_t arg)          {
                if (op1.empty()) goto op1;
                if (op2.empty()) goto op2;
                return;
        op1:    op1 = std::to_string(arg);
                return;
        op2:    op2 = std::to_string(arg);
                return;
    }

    void
        bin::arg
            (std::uint8_t arg)           {
                if (op1.empty()) goto op1;
                if (op2.empty()) goto op2;
                return;
        op1:    op1 = std::to_string(arg);
                return;
        op2:    op2 = std::to_string(arg);
                return;
    }

    void
        bin::arg
            (std::int64_t arg)           {
                if (op1.empty()) goto op1;
                if (op2.empty()) goto op2;
                return;
        op1:    op1 = std::to_string(arg);
                return;
        op2:    op2 = std::to_string(arg);
                return;
    }

    void
        bin::arg
            (std::int32_t arg)           {
                if (op1.empty()) goto op1;
                if (op2.empty()) goto op2;
                return;
        op1:    op1 = std::to_string(arg);
                return;
        op2:    op2 = std::to_string(arg);
                return;
    }

    void
        bin::arg
            (std::int16_t arg)           {
                if (op1.empty()) goto op1;
                if (op2.empty()) goto op2;
                return;
        op1:    op1 = std::to_string(arg);
                return;
        op2:    op2 = std::to_string(arg);
                return;
    }

    void
        bin::arg
            (std::int8_t arg)            {
                if (op1.empty()) goto op1;
                if (op2.empty()) goto op2;
                return;
        op1:    op1 = std::to_string(arg);
                return;
        op2:    op2 = std::to_string(arg);
                return;
    }

    void
        bin::arg
            (double arg)                 {
                if (op1.empty()) goto op1;
                if (op2.empty()) goto op2;
                return;
        op1:    op1 = std::to_string(arg);
                return;
        op2:    op2 = std::to_string(arg);
                return;
    }

    void
        bin::arg
            (float arg)                  {
                if (op1.empty()) goto op1;
                if (op2.empty()) goto op2;
                return;
        op1:    op1 = std::to_string(arg);
                return;
        op2:    op2 = std::to_string(arg);
                return;
    }

    void
        bin::arg
            (ops& arg)                      {
                if (op1.empty()) goto do_op1;
                if (op2.empty()) goto do_op2;
                return;
    do_op1:     op1 += "("; op1 += arg.as_str();
                op1 += ")";
                return;
    do_op2:     op2 += "("; op2 += arg.as_str();
                op2 += ")";
                return;
    }

    void
        bin::src(ops&) {
    }
}

namespace ap::trans::c {
    void
        bin_eq::arg
            (meta::type_id id, std::string_view name) {
                if (op1.empty()) goto op1;
                if (op2.empty()) goto op2;
                return;
        op1:    op1 = name;
                return;
        op2:    op2 = name;
                return;
    }

    void
        bin_eq::arg
            (std::string_view type, std::string_view name) {
                if (op1.empty()) goto op1;
                if (op2.empty()) goto op2;
                return;
        op1:    op1 = name;
                return;
        op2:    op2 = name;
                return;
    }

    void
        bin_eq::arg
            (std::uint64_t arg)        {
                if (op1.empty()) return;
                if (op2.empty())             {
                    op2 = std::to_string(arg);
                    return;
                }
    }

    void
        bin_eq::arg
            (std::uint32_t arg)        {
                if (op1.empty()) return;
                if (op2.empty())             {
                    op2 = std::to_string(arg);
                    return;
                }
    }

    void
        bin_eq::arg
            (std::uint16_t arg)        {
                if (op1.empty()) return;
                if (op2.empty())             {
                    op2 = std::to_string(arg);
                    return;
                }
    }

    void
        bin_eq::arg
            (std::uint8_t arg)         {
                if (op1.empty()) return;
                if (op2.empty())             {
                    op2 = std::to_string(arg);
                    return;
                }
    }

    void
        bin_eq::arg
            (std::int64_t arg)         {
                if (op1.empty()) return;
                if (op2.empty())             {
                    op2 = std::to_string(arg);
                    return;
                }
    }

    void
        bin_eq::arg
            (std::int32_t arg)         {
                if (op1.empty()) return;
                if (op2.empty())             {
                    op2 = std::to_string(arg);
                    return;
                }
    }

    void
        bin_eq::arg
            (std::int16_t arg)         {
                if (op1.empty()) return;
                if (op2.empty())             {
                    op2 = std::to_string(arg);
                    return;
                }
    }

    void
        bin_eq::arg
            (std::int8_t arg)          {
                if (op1.empty()) return;
                if (op2.empty())             {
                    op2 = std::to_string(arg);
                    return;
                }
    }

    void
        bin_eq::arg
            (double arg)               {
                if (op1.empty()) return;
                if (op2.empty())             {
                    op2 = std::to_string(arg);
                    return;
                }
    }

    void
        bin_eq::arg
            (float arg)                {
                if (op1.empty()) return;
                if (op2.empty())             {
                    op2 = std::to_string(arg);
                    return;
                }
    }

    void
        bin_eq::arg
            (ops& arg)                      {
                if (op1.empty()) goto do_op1;
                if (op2.empty()) goto do_op2;
                return;
    do_op1:     op1 += "("; op1 += arg.as_str();
                op1 += ")";
                return;
    do_op2:     op2 += "("; op2 += arg.as_str();
                op2 += ")";
                return;
    }

    void
        bin_eq::src(ops& arg) {
            
    }
}

namespace ap::trans::c {
    std::string
        bin::as_str()                 {
            if (op1.empty()) return {};
            if (op2.empty()) return {};
            std::string ret;

            ret += op1; ret += op;
            ret += op2;
            return ret;
    }

    std::string
        bin_eq::as_str()              {
            if (op1.empty()) return {};
            if (op2.empty()) return {};
            std::string ret;

            ret += op1; ret += op;
            ret += op2;
            return ret;
    }
}

namespace ap::trans::c {
    bin::bin (str_t op)
        : op(op)
            {}

    bin_eq::bin_eq (str_t op)
        : op(op)
            {}
}