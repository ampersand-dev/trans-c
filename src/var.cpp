#include <ap/trans/c/var.hpp>

namespace ap::trans::c {
    std::string
        var::as_str()                  {
            if (type.empty()) return {};
            if (name.empty()) return {};
            if (str .empty()) return {};

            return str;
    }
}

namespace ap::trans::c {
    var
        var::trait::pack
            (var& var, str_t type, str_t name)   {
                if (!var.type.empty()) return var;
                if (!var.name.empty()) return var;
                if (!var.str .empty()) return var;

                if (type.empty()) return {};
                if (name.empty()) return {};

                using namespace std::string_literals;
                var.type = "struct "s += type;
                var.name = type;

                var.str = var.type
                        + ' '
                        + var.name;
                return var;
    }

    var
        var::trait::f64
            (var& var, str_t name)               {
                if (!var.type.empty()) return var;
                if (!var.name.empty()) return var;
                if (!var.str .empty()) return var;

                if (name.empty()) return {};
                var.type = "double";
                var.name = name;

                var.str = var.type
                        + ' '
                        + var.name;
                return var;
    }

    var
        var::trait::f32
            (var& var, str_t name)               {
                if (!var.type.empty()) return var;
                if (!var.name.empty()) return var;
                if (!var.str .empty()) return var;

                if (name.empty()) return {};
                var.type = "float";
                var.name = name;

                var.str = var.type
                        + ' '
                        + var.name;
                return var;
    }

    var
        var::trait::u64
            (var& var, str_t name)               {
                if (!var.type.empty()) return var;
                if (!var.name.empty()) return var;
                if (!var.str .empty()) return var;

                if (name.empty()) return {};
                var.type = "unsigned long long";
                var.name = name;

                var.str = var.type
                        + ' '
                        + var.name;
                return var;
    }

    var
        var::trait::i64
            (var& var, str_t name)               {
                if (!var.type.empty()) return var;
                if (!var.name.empty()) return var;
                if (!var.str .empty()) return var;

                if (name.empty()) return {};
                var.type = "long long";
                var.name = name;

                var.str = var.type
                        + ' '
                        + var.name;
                return var;
    }

    var
        var::trait::u32
            (var& var, str_t name)               {
                if (!var.type.empty()) return var;
                if (!var.name.empty()) return var;
                if (!var.str .empty()) return var;

                if (name.empty()) return {};
                var.type = "unsigned int";
                var.name = name;

                var.str = var.type
                        + ' '
                        + var.name;
                return var;
    }

    var
        var::trait::i32
            (var& var, str_t name)               {
                if (!var.type.empty()) return var;
                if (!var.name.empty()) return var;
                if (!var.str .empty()) return var;

                if (name.empty()) return {};
                var.type = "int";
                var.name = name;

                var.str = var.type
                        + ' '
                        + var.name;
                return var;
    }

    var
        var::trait::u16
            (var& var, str_t name)               {
                if (!var.type.empty()) return var;
                if (!var.name.empty()) return var;
                if (!var.str .empty()) return var;

                if (name.empty()) return {};
                var.type = "unsigned short";
                var.name = name;

                var.str = var.type
                        + ' '
                        + var.name;
                return var;
    }

    var
        var::trait::i16
            (var& var, str_t name)               {
                if (!var.type.empty()) return var;
                if (!var.name.empty()) return var;
                if (!var.str .empty()) return var;

                if (name.empty()) return {};
                var.type = "short";
                var.name = name;

                var.str = var.type
                        + ' '
                        + var.name;
                return var;
    }

    var
        var::trait::u8
            (var& var, str_t name)               {
                if (!var.type.empty()) return var;
                if (!var.name.empty()) return var;
                if (!var.str .empty()) return var;

                if (name.empty()) return {};
                var.type = "unsigned char";
                var.name = name;

                var.str = var.type
                        + ' '
                        + var.name;
                return var;
    }

    var
        var::trait::i8
            (var& var, str_t name)               {
                if (!var.type.empty()) return var;
                if (!var.name.empty()) return var;
                if (!var.str .empty()) return var;

                if (name.empty()) return {};
                var.type = "char";
                var.name = name;

                var.str = var.type
                        + ' '
                        + var.name;
                return var;
    }
}