#include <ap/trans/c/fn.hpp>

namespace ap::trans::c {
    std::string
        fn::all()          {
            std::string ret;

            ret += fret; ret += "\n\t";
            ret += name; ret += "\n\t\t";

            ret += "(";  ret += farg;
            ret += ")";

            ret += "{\n";
            ret += fsrc;
            ret += "\n}";

            return ret;
    }

    std::string
        fn::head()                    {
            std::string ret;

            ret += fret; ret += "\n\t";
            ret += name; ret += "\n\t\t";

            ret += "(";  ret += farg;
            ret += ")";
            ret += ";";

            return ret;
    }
    
    fn::fn(std::string_view name)
        : name(name) 
            {}

    fn::fn() {}
}

namespace ap::trans::c {
    void 
        fn::arg
            (std::string_view type, std::string_view name) {
                if (name.empty()) return;
                std::string str;

                using namespace std::string_literals;
                str = "struct ";
                str += type;
                str += " ";
                str += name;

                if (farg.empty()) farg = name;
                else            {
                    farg +=  ",";
                    farg += name;
                }
                
    }

    void
        fn::arg
            (meta::type_id type, std::string_view name) {
                if (name.empty()) return;
                std::string str;

                switch (type)                                       {
                    case meta::type_id::f64: str += "double "; break;
                    case meta::type_id::f32: str += "float " ; break;

                    case meta::type_id::u64: str += "unsigned long long "; break;
                    case meta::type_id::i64: str += "long long " ;         break;

                    case meta::type_id::u32: str += "unsigned int "; break;
                    case meta::type_id::i32: str += "int " ;         break;

                    case meta::type_id::u16: str += "unsigned short "; break;
                    case meta::type_id::i16: str += "short ";          break;

                    case meta::type_id::u8 : str += "unsigned char "; break;
                    case meta::type_id::i8 : str += "char ";          break;
                }

                str += name;
                if (farg.empty()) farg = name;
                else            {
                    farg +=  ",";
                    farg += name;
                }
    }


    void 
        fn::ret
            (std::string_view name)     {
                if (name.empty()) return;
                std::string str;

                fret += "struct ";
                fret += name;
    }

    void
        fn::ret
            (meta::type_id type)        {
                if (name.empty()) return;
                std::string str;

                switch (type)                                       {
                    case meta::type_id::f64: fret = "double"; break;
                    case meta::type_id::f32: fret = "float" ; break;

                    case meta::type_id::u64: fret = "unsigned long long"; break;
                    case meta::type_id::i64: fret = "long long" ;         break;

                    case meta::type_id::u32: fret = "unsigned int"; break;
                    case meta::type_id::i32: fret = "int" ;         break;

                    case meta::type_id::u16: fret = "unsigned short"; break;
                    case meta::type_id::i16: fret = "short";          break;

                    case meta::type_id::u8 : fret = "unsigned char"; break;
                    case meta::type_id::i8 : fret = "char";          break;
                }
    }

 
    
    void 
        fn::src
            (ops ops)               {
                fsrc += "\t\t\t";
                fsrc += ops.as_str();
                fsrc += ";\n";
    }
}