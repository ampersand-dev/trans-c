#include <ap/trans/c/ops/control.hpp>
#include <ap/trans/c/ops.hpp>

namespace ap::trans::c {
    control::control(std::pmr::memory_resource* mre)
        : mre (mre),
          mem (mre)
            {}

    control::control()
        : mre (std::pmr::get_default_resource()),
          mem (std::pmr::get_default_resource())
            {}

    ops control::loop_while() { class loop_while *ret = mem.new_object<class loop_while>(); return ops (ret, mre); }
    ops control::loop_for  () { class loop_for   *ret = mem.new_object<class loop_for>  (); return ops (ret, mre); }
    ops control::cond      () { class cond       *ret = mem.new_object<class cond>      (); return ops (ret, mre); }
}

namespace ap::trans::c                                                 {
    void 
        control::loop_while::arg
            (ops& arg)                  {
                if (!op1.empty()) return;
                op1 = arg.as_str();
    }

    void 
        control::loop_while::src
            (ops& arg)              {
                loop += arg.as_str();
                loop += ";\n";
    }

    std::string 
        control::loop_while::as_str() {
            std::string ret ("while");

            ret += "("; ret += op1;
            ret += ")";

            ret += "{\n"; ret += loop;
            ret += "\n}";

            return ret;
    }
}

namespace ap::trans::c                                               {
    void 
        control::loop_for::arg
            (ops& arg)                   {
                if (op1.empty()) goto op1;
                if (op2.empty()) goto op2;
                if (op3.empty()) goto op3;
                return;
    op1:        op1 = arg.as_str();
                return;
    op2:        op2 = arg.as_str();
                return;
    op3:        op3 = arg.as_str();
                return;
    }

    void 
        control::loop_for::src
            (ops& arg)              {
                loop += arg.as_str();
                loop += ";\n";
    }

    std::string 
        control::loop_for::as_str() {
            std::string ret ("for");

            ret += "(";
            ret += op1; ret += "; ";
            ret += op2; ret += "; ";
            ret += op3;
            ret += ")";

            ret += "{\n"; ret += loop;
            ret += "\n}";

            return ret;
    }
}

namespace ap::trans::c                                                 {
    void 
        control::cond::arg
            (ops& arg)                   {
                if (op1.empty()) goto op1;
                this->next = arg.as_str();
                return;

        op1:    this->op1 = arg.as_str();
                return;
    }

    void 
        control::cond::src
            (ops& arg)              {
                cond += arg.as_str();
                cond += ";\n";
    }
    
    std::string 
        control::cond::as_str() {
            std::string ret;

            if (!op1.empty())          {
                ret += "if";
                ret += "(" ; ret += op1;
                ret += ")" ;
            }

            ret += "{\n"; ret += cond;
            ret += "\n}";


            if (next.empty()) return ret;
            ret += "else ";
            ret += next;
            ret += "\n";
            return ret;
    }
}