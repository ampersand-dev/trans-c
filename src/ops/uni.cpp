#include <ap/trans/c/ops/uni.hpp>

namespace ap::trans::c {
    void
        uni::arg
            (meta::type_id idx, std::string_view name, std::string_view self) {
                if (!op1.empty()) return;
                op1 += self;
                op1 +=  ".";
                op1 += name;
    }

    void
        uni::arg
            (std::string_view idx, std::string_view name, std::string_view self) {
                if (!op1.empty()) return;
                op1 += self;
                op1 +=  ".";
                op1 += name;
    }

    void
        uni::arg
            (meta::type_id idx, std::string_view name) {
                if (!op1.empty()) return;
                op1 = name;
    }

    void
        uni::arg
            (std::string_view idx, std::string_view name) {
                if (!op1.empty()) return;
                op1 = name;
    }

    void
        uni::arg
            (std::uint64_t arg)          {
                if (!op1.empty())  return;
                op1 = std::to_string(arg);
    }

    void
        uni::arg
            (std::uint32_t arg)          {
                if (!op1.empty())  return;
                op1 = std::to_string(arg);
    }

    void
        uni::arg
            (std::uint16_t arg)          {
                if (!op1.empty())  return;
                op1 = std::to_string(arg);
    }

    void
        uni::arg
            (std::uint8_t arg)           {
                if (!op1.empty())  return;
                op1 = std::to_string(arg);
    }

    void
        uni::arg
            (std::int64_t arg)           {
                if (!op1.empty())  return;
                op1 = std::to_string(arg);
    }

    void
        uni::arg
            (std::int32_t arg)           {
                if (!op1.empty())  return;
                op1 = std::to_string(arg);
    }

    void
        uni::arg
            (std::int16_t arg)           {
                if (!op1.empty())  return;
                op1 = std::to_string(arg);
    }

    void
        uni::arg
            (std::int8_t arg)            {
                if (!op1.empty())  return;
                op1 = std::to_string(arg);
    }

    void
        uni::arg
            (double arg)                 {
                if (!op1.empty())  return;
                op1 = std::to_string(arg);
    }

    void
        uni::arg
            (float arg)                  {
                if (!op1.empty())  return;
                op1 = std::to_string(arg);
    }

    void
        uni::arg
            (ops& arg)                  {
                if (!op1.empty()) return;

                op += "("; op += arg.as_str();
                op += ")";
    }

    void
        uni::src(ops&) {
    }
}

namespace ap::trans::c {
    std::string
        uni::as_str()                 {
            if (op1.empty()) return {};
            if (op .empty()) return {};

            std::string ret;
            ret += op;
            ret += op1;
            return ret;
    }

    uni::uni(str_t op)
        : op(op)
            {}
}