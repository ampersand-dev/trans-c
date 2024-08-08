#include <ap/trans/c/fn.hpp>
#include <ap/trans/c/ops.hpp>

namespace ap::trans::c {
    std::string
        fn::as_str()       {
            std::string ret;

            if (!this->ret.empty()) ret += this->ret;
            else                    ret += "void";
            ret += "\n\t";

            ret += this->name;
            ret += "\n\t\t(";
            
            for(auto& arg : this->arg) ret += (arg + ", ");
            if (ret.ends_with(", "))                      {
                ret.pop_back();
                ret.pop_back();
            }

            ret += "){\n";
            
            ret += this->src;
            ret += "\n}";
            return ret;
    }
    
    fn::fn(std::string_view name)
        : name(name) 
    {}
}

namespace ap::trans::c {
    fn 
        fn::trait::make
            (str_t name)       {
                return fn (name);
    }

    void 
        fn::trait::arg
            (fn& fn, str_t type, str_t name) {
                if (fn.name.empty()) return;
                std::string str;

                str = "struct ";
                str += type;
                str += " ";
                str += name;

                fn.arg.emplace_back(std::move(str));
    }

    void
        fn::trait::arg
            (fn& fn, meta::type_id type, str_t name) {
                if (fn.name.empty()) return;
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
                fn.arg.emplace_back(std::move (str));
    }


    void 
        fn::trait::ret
            (fn& fn, str_t name)           {
                if (fn.name.empty()) return;
                std::string str;

                str += "struct ";
                str += name;

                fn.ret = std::move(str);
    }

    void
        fn::trait::ret
            (fn& fn, meta::type_id type)   {
                if (fn.name.empty()) return;
                std::string str;

                switch (type)                                       {
                    case meta::type_id::f64: str = "double"; break;
                    case meta::type_id::f32: str = "float" ; break;

                    case meta::type_id::u64: str = "unsigned long long"; break;
                    case meta::type_id::i64: str = "long long" ;         break;

                    case meta::type_id::u32: str = "unsigned int"; break;
                    case meta::type_id::i32: str = "int" ;         break;

                    case meta::type_id::u16: str = "unsigned short"; break;
                    case meta::type_id::i16: str = "short";          break;

                    case meta::type_id::u8 : str = "unsigned char"; break;
                    case meta::type_id::i8 : str = "char";          break;
                }

                fn.ret = std::move (str);
    }

 
    
    void 
        fn::trait::src
            (fn& fn, ops ops)              {
                fn.src += "\t\t\t";
                fn.src += ops.as_str();
                fn.src += ";\n";
    }
}