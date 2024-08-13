#include <ap/trans/c/pack.hpp>


namespace ap::trans::c {
    pack::pack (std::string_view name)
        : name (name) {
    }

    std::string
        pack::as_str()     {
            std::string ret;

            ret += "struct "; 

            ret += name; ret += " {\n";
            ret += str;
            
            ret += "}\n";
            return   ret;
    }
}

namespace ap::trans::c                                     {
    void 
        pack::var
            (std::string_view type, std::string_view name) {
                if (type.empty()) return;
                if (name.empty()) return;

                str += "\tstruct ";
                str += type;
                str += name;
                str += ";\n";
    }

    void 
        pack::f64
            (std::string_view name)     {
                if (name.empty()) return;

                str += "\tdouble ";
                str += name;
                str += ";\n";
    }

    void 
        pack::f32
            (std::string_view name)     {
                if (name.empty()) return;

                str += "\tfloat ";
                str += name;
                str += ";\n";
    }

    void 
        pack::i64
            (std::string_view name)     {
                if (name.empty()) return;

                str += "\tlong long ";
                str += name;
                str += ";\n";
    }

    void 
        pack::u64
            (std::string_view name)     {
                if (name.empty()) return;

                str += "\tunsigned long long ";
                str += name;
                str += ";\n";
    }

    void 
        pack::i32
            (std::string_view name)     {
                if (name.empty()) return;

                str += "\tint ";
                str += name;
                str += ";\n";
    }

    void 
        pack::u32
            (std::string_view name)     {
                if (name.empty()) return;

                str += "\tunsigned int ";
                str += name;
                str += ";\n";
    }

    void 
        pack::i16
            (std::string_view name)     {
                if (name.empty()) return;

                str += "\tshort ";
                str += name;
                str += ";\n";
    }

    void 
        pack::u16
            (std::string_view name)     {
                if (name.empty()) return;

                str += "\tunsigned short ";
                str += name;
                str += ";\n";
    }

    void 
        pack::i8
            (std::string_view name)     {
                if (name.empty()) return;

                str += "\tchar ";
                str += name;
                str += ";\n";
    }

    void 
        pack::u8
            (std::string_view name)     {
                if (name.empty()) return;

                str += "\tunsigned char ";
                str += name;
                str += ";\n";
    }
}