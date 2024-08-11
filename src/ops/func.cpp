#include <ap/trans/c/ops/func.hpp>
#include <ap/trans/c/ops.hpp>

namespace ap::trans::c {
    func::func(std::pmr::memory_resource* mre)
        : mre(mre),
          mem(mre)
            {}

    func::func()
        : mre(std::pmr::get_default_resource()),
          mem(std::pmr::get_default_resource())
            {}

    ops func::call() { class call* ret = mem.new_object<class call>(); return ops (ret, mre); }
    ops func::ret () { class ret * ret = mem.new_object<class ret> (); return ops (ret, mre); }
}

namespace ap::trans::c                                                        {
    void
        func::call::arg
            (meta::type_id idx, std::string_view name, std::string_view self) {
                if (func.empty()) goto do_func;
                if (str .empty()) str = std::string(self) 
                                      + "." 
                                      + std::string(name);
                else                                     {
                    str += ", ";
                    str += self;
                    str +=  ".";
                    str += name;
                }

                return;
    do_func:    if (idx != meta::type_id::func) return;
                func += self;
                func +=  ".";
                func += name;
                return;
    }

    void 
        func::call::arg
            (std::string_view type, std::string_view name, std::string_view self) {
                if (func.empty()) return;

                if (str.empty()) str = std::string(self) 
                                     + "."
                                     + std::string(name);
                else                                    {
                    str += ", ";
                    str += self;
                    str += ".";
                    str += name;
                }
    }

    void
        func::call::arg
            (meta::type_id idx, std::string_view name) {
                if (func.empty()) goto do_func;
                if (str .empty()) str = name;
                else           {
                    str += ", ";
                    str += name;
                }

                return;
    do_func:    if (idx != meta::type_id::func) return;
                func = name;
                return;
    }

    void 
        func::call::arg
            (std::string_view type, std::string_view name) {
                if (func.empty()) return;

                if (str.empty()) str = name;
                else           {
                    str += ", ";
                    str += name;
                }
    }

    void 
        func::call::arg
            (std::uint64_t arg)         {
                if (func.empty()) return;

                if (str.empty()) str = std::to_string (arg);
                else                          {
                    str += ", ";
                    str += std::to_string(arg);
                }
    }

    void 
        func::call::arg
            (std::uint32_t arg)         {
                if (func.empty()) return;

                if (str.empty()) str = std::to_string (arg);
                else                          {
                    str += ", ";
                    str += std::to_string(arg);
                }
    }

    void 
        func::call::arg
            (std::uint16_t arg)         {
                if (func.empty()) return;

                if (str.empty()) str = std::to_string (arg);
                else                          {
                    str += ", ";
                    str += std::to_string(arg);
                }
    }

    void 
        func::call::arg
            (std::uint8_t arg)          {
                if (func.empty()) return;

                if (str.empty()) str = std::to_string (arg);
                else                          {
                    str += ", ";
                    str += std::to_string(arg);
                }
    }

    void 
        func::call::arg
            (std::int64_t arg)          {
                if (func.empty()) return;

                if (str.empty()) str = std::to_string (arg);
                else                          {
                    str += ", ";
                    str += std::to_string(arg);
                }
    }

    void 
        func::call::arg
            (std::int32_t arg)          {
                if (func.empty()) return;

                if (str.empty()) str = std::to_string (arg);
                else                          {
                    str += ", ";
                    str += std::to_string(arg);
                }
    }

    void 
        func::call::arg
            (std::int16_t arg)          {
                if (func.empty()) return;

                if (str.empty()) str = std::to_string (arg);
                else                          {
                    str += ", ";
                    str += std::to_string(arg);
                }
    }

    void 
        func::call::arg
            (std::int8_t arg)           {
                if (func.empty()) return;

                if (str.empty()) str = std::to_string (arg);
                else                          {
                    str += ", ";
                    str += std::to_string(arg);
                }
    }

    void 
        func::call::arg
            (double arg)                {
                if (func.empty()) return;

                if (str.empty()) str = std::to_string (arg);
                else                          {
                    str += ", ";
                    str += std::to_string(arg);
                }
    }

    void 
        func::call::arg
            (float arg)                 {
                if (func.empty()) return;

                if (str.empty()) str = std::to_string (arg);
                else                          {
                    str += ", ";
                    str += std::to_string(arg);
                }
    }

    void
        func::call::arg
            (ops& arg)                  {
                if (func.empty()) return;
                std::string ret;

                ret += "("; ret += arg.as_str();
                ret += ")";

                if (str.empty()) str = ret;
                else           {
                    str += ", ";
                    str += ret;
                }
    }
}

namespace ap::trans::c {
    void 
        func::ret::arg
            (meta::type_id idx, std::string_view name, std::string_view self) {
                if (!str.empty()) return;
                str += self;
                str +=  ".";
                str += name;
    }

    void 
        func::ret::arg
            (std::string_view type, std::string_view name, std::string_view self) {
                if (!str.empty()) return;
                str += self;
                str +=  ".";
                str += name;
    }

    void 
        func::ret::arg
            (meta::type_id idx, std::string_view name) {
                if (!str.empty()) return;
                str = name;
    }

    void 
        func::ret::arg
            (std::string_view type, std::string_view name) {
                if (!str.empty()) return;
                str = name;
    }

    void
        func::ret::arg
            (std::uint64_t arg)          {
                if (!str.empty())  return;
                str = std::to_string(arg);
    }

    void
        func::ret::arg
            (std::uint32_t arg)          {
                if (!str.empty())  return;
                str = std::to_string(arg);
    }

    void
        func::ret::arg
            (std::uint16_t arg)          {
                if (!str.empty())  return;
                str = std::to_string(arg);
    }

    void
        func::ret::arg
            (std::uint8_t arg)           {
                if (!str.empty())  return;
                str = std::to_string(arg);
    }

    void
        func::ret::arg
            (std::int64_t arg)           {
                if (!str.empty())  return;
                str = std::to_string(arg);
    }

    void
        func::ret::arg
            (std::int32_t arg)           {
                if (!str.empty())  return;
                str = std::to_string(arg);
    }

    void
        func::ret::arg
            (std::int16_t arg)           {
                if (!str.empty())  return;
                str = std::to_string(arg);
    }

    void
        func::ret::arg
            (std::int8_t arg)            {
                if (!str.empty())  return;
                str = std::to_string(arg);
    }

    void
        func::ret::arg
            (double arg)                 {
                if (!str.empty())  return;
                str = std::to_string(arg);
    }

    void
        func::ret::arg
            (float arg)                  {
                if (!str.empty())  return;
                str = std::to_string(arg);
    }

    void
        func::ret::arg
            (ops& arg)                  {
                if (!str.empty()) return;

                str += "("; str += arg.as_str();
                str += ")";
    }

    void
        func::ret::src
            (ops&) {
    }
}

namespace ap::trans::c {
    std::string
        func::ret::as_str() {
            std::string ret;

            ret += "return ";
            ret += str;
            return ret;
    }

    std::string
        func::call::as_str()           {
            if (func.empty()) return {};
            std::string ret (func);

            ret += "("; ret += str;
            ret += ")";
            return ret;
    }
}

namespace ap::trans::c  {
    func::call::call() {}
    func::ret ::ret () {}
}