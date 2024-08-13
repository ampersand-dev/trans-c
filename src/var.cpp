#include <ap/trans/c/var.hpp>

namespace ap::trans::c {
    std::string
        var::as_str()                  {
            if (type.empty()) return {};
            if (name.empty()) return {};
            if (str .empty()) return {};

            return str;
    }

    var::var() {}
}

namespace ap::trans::c {
    var::trait::ret_t
        var::trait::err()      {
            return std::nullopt;
    }

    var::trait::ret_t
        var::trait::pack
            (str_t type, str_t name)       {
                if (type.empty()) return {};
                if (name.empty()) return {};
                var ret {};

                using namespace std::string_literals;
                ret.type = "struct "s += type;
                ret.name = name;

                ret.str = ret.type
                        + ' '
                        + ret.name;
                return ret;
    }

    var::trait::ret_t
        var::trait::f64
            (str_t name)                   {
                if (name.empty()) return {};
                var ret {};

                ret.type = "double";
                ret.name = name;

                ret.str = ret.type
                        + ' '
                        + ret.name;
                return ret;
    }

    var::trait::ret_t
        var::trait::f32
            (str_t name)                   {
                if (name.empty()) return {};
                var ret {};

                ret.type = "float";
                ret.name = name;

                ret.str = ret.type
                        + ' '
                        + ret.name;
                return ret;
    }

    var::trait::ret_t
        var::trait::u64
            (str_t name)                   {
                if (name.empty()) return {};
                var ret {};

                ret.type = "unsigned long long";
                ret.name = name;

                ret.str = ret.type
                        + ' '
                        + ret.name;
                return ret;
    }

    var::trait::ret_t
        var::trait::i64
            (str_t name)                   {
                if (name.empty()) return {};
                var ret {};

                ret.type = "long long";
                ret.name = name;

                ret.str = ret.type
                        + ' '
                        + ret.name;
                return ret;
    }

    var::trait::ret_t
        var::trait::u32
            (str_t name)                   {
                if (name.empty()) return {};
                var ret {};

                ret.type = "unsigned int";
                ret.name = name;

                ret.str = ret.type
                        + ' '
                        + ret.name;
                return ret;
    }

    var::trait::ret_t
        var::trait::i32
            (str_t name)                   {
                if (name.empty()) return {};
                var ret {};

                ret.type = "int";
                ret.name = name;

                ret.str = ret.type
                        + ' '
                        + ret.name;
                return ret;
    }

    var::trait::ret_t
        var::trait::u16
            (str_t name)                   {
                if (name.empty()) return {};
                var ret {};

                ret.type = "unsigned short";
                ret.name = name;

                ret.str = ret.type
                        + ' '
                        + ret.name;
                return ret;
    }

    var::trait::ret_t
        var::trait::i16
            (str_t name)                   {
                if (name.empty()) return {};
                var ret {};

                ret.type = "short";
                ret.name = name;

                ret.str = ret.type
                        + ' '
                        + ret.name;
                return ret;
    }

    var::trait::ret_t
        var::trait::u8
            (str_t name)                   {
                if (name.empty()) return {};
                var ret {};

                ret.type = "unsigned char";
                ret.name = name;

                ret.str = ret.type
                        + ' '
                        + ret.name;
                return ret;
    }

    var::trait::ret_t
        var::trait::i8
            (str_t name)                   {
                if (name.empty()) return {};
                var ret {};

                ret.type = "char";
                ret.name = name;

                ret.str = ret.type
                        + ' '
                        + ret.name;
                return ret;
    }
}