#include <ap/trans/c/ops.hpp>

namespace ap::trans::c                                                     {
    ops::ops(opc_t opc, std::pmr::memory_resource* mem)
        : mem (mem),
          opc (opc)
            {}

    void ops::arg(meta::type_id type, len_t len, str_t name, str_t self) { if (opc) opc->arg (type, len, name, self); }
    void ops::arg(str_t         type, len_t len, str_t name, str_t self) { if (opc) opc->arg (type, len, name, self); }

    void ops::arg(meta::type_id type, str_t name, str_t self) { if (opc) opc->arg (type, name, self); }
    void ops::arg(str_t         type, str_t name, str_t self) { if (opc) opc->arg (type, name, self); }

    void ops::arg(meta::type_id type, len_t len, str_t name) { if (opc) opc->arg (type, len, name); }
    void ops::arg(str_t         type, len_t len, str_t name) { if (opc) opc->arg (type, len, name); }

    void ops::arg(meta::type_id type, str_t name) { if (opc) opc->arg (type, name); }
    void ops::arg(str_t         type, str_t name) { if (opc) opc->arg (type, name); }
    
    void ops::arg(ops arg)                        { if (opc) opc->arg (arg); }
    void ops::src(ops arg)                        { if (opc) opc->src(arg); }

    std::string 
        ops::as_str()           {
            return opc->as_str();
    }

    ops::~ops()                       {
        if(opc) mem.delete_object(opc);
    }

    ops::ops(const ops& copy)
        : mem (copy.mem),
          opc (copy.opc)                        {
            ops& ops = const_cast<c::ops&>(copy);
            ops .opc = nullptr;
    }

    ops::ops(ops&& move)
        : mem (move.mem),
          opc (move.opc)      {
            move.opc = nullptr;
    }

}