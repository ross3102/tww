#ifndef D_A_OBJ_AYGR_H
#define D_A_OBJ_AYGR_H

#include "f_op/f_op_actor.h"

namespace daObjAygr {
    class Act_c : public fopAc_ac_c {
    public:
        void prm_get_mdl() const {}
    
        void CreateHeap();
        s32 Create();
        cPhs_State Mthd_Create();
        BOOL Delete();
        BOOL Mthd_Delete();
        void set_mtx();
        void init_mtx();
        void Execute(float(**)[3][4]);
        BOOL Draw();
    
    public:
        /* Place member variables here */
    };
};

#endif /* D_A_OBJ_AYGR_H */
