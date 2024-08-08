#include <ap/trans/c/pack.hpp>

namespace ap::trans::c                               {
    std::fstream
        pack::as_file
            (std::filesystem::path path)     {
                if (name.empty())   return {};
                if (str .empty())   return {};
                std::fstream ret { path };

                if (ret.good() == false) return ret;
                if (ret.fail())          return ret;

                ret << str;
                return ret;
    }

    std::string
        pack::as_str()                     {
                if (name.empty()) return {};
                if (str .empty()) return {};

                std::string ret = str;
                ret += "};";
                return ret;
    }
}

namespace ap::trans::c                                       {
    pack
        pack::trait::make
            (str_t name)                                     {
                if (name.find('\t') != str_t::npos) return {};
                if (name.find(' ')  != str_t::npos) return {};
                pack ret {};

                ret.name = name;

                ret.str += "struct ";
                ret.str += name;
                ret.str += " { \n";
                return ret;
    }

    void 
        pack::trait::var
            (pack& pack, str_t type, str_t name) {
                if (pack.name.empty()) return;
                if (type.empty())      return;
                if (name.empty())      return;

                pack.str += "struct ";
                pack.str += type;
                pack.str += name;
                pack.str += ";\n";
    }

    void 
        pack::trait::f64
            (pack& pack, str_t name)         {
                if (pack.name.empty()) return;
                if (name.empty())      return;

                pack.str += "double ";
                pack.str += name;
                pack.str += ";\n";
    }

    void 
        pack::trait::f32
            (pack& pack, str_t name)         {
                if (pack.name.empty()) return;
                if (name.empty())      return;

                pack.str += "float ";
                pack.str += name;
                pack.str += ";\n";
    }

    void 
        pack::trait::i64
            (pack& pack, str_t name)         {
                if (pack.name.empty()) return;
                if (name.empty())      return;

                pack.str += "long long ";
                pack.str += name;
                pack.str += ";\n";
    }

    void 
        pack::trait::u64
            (pack& pack, str_t name)         {
                if (pack.name.empty()) return;
                if (name.empty())      return;

                pack.str += "unsigned long long ";
                pack.str += name;
                pack.str += ";\n";
    }

    void 
        pack::trait::i32
            (pack& pack, str_t name)         {
                if (pack.name.empty()) return;
                if (name.empty())      return;

                pack.str += "int ";
                pack.str += name;
                pack.str += ";\n";
    }

    void 
        pack::trait::u32
            (pack& pack, str_t name)         {
                if (pack.name.empty()) return;
                if (name.empty())      return;

                pack.str += "unsigned int ";
                pack.str += name;
                pack.str += ";\n";
    }

    void 
        pack::trait::i16
            (pack& pack, str_t name)         {
                if (pack.name.empty()) return;
                if (name.empty())      return;

                pack.str += "short ";
                pack.str += name;
                pack.str += ";\n";
    }

    void 
        pack::trait::u16
            (pack& pack, str_t name)         {
                if (pack.name.empty()) return;
                if (name.empty())      return;

                pack.str += "unsigned short ";
                pack.str += name;
                pack.str += ";\n";
    }

    void 
        pack::trait::i8
            (pack& pack, str_t name)         {
                if (pack.name.empty()) return;
                if (name.empty())      return;

                pack.str += "char ";
                pack.str += name;
                pack.str += ";\n";
    }

    void 
        pack::trait::u8
            (pack& pack, str_t name)         {
                if (pack.name.empty()) return;
                if (name.empty())      return;

                pack.str += "unsigned char ";
                pack.str += name;
                pack.str += ";\n";
    }
}