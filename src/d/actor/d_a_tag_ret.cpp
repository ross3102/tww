//
// Generated by dtk
// Translation Unit: d_a_tag_ret.cpp
//

#include "d/d_a_obj.h"
#include "d/d_item.h"
#include "d/d_item_data.h"
#include "d/d_cc_d.h"
#include "d/d_procname.h"
#include "d/d_com_inf_game.h"
#include "d/actor/daPy_lk.h"
#include "JSystem/JKernel/JKRHeap.h"
#include "dolphin/types.h"

static dCcD_SrcCyl cyl_check_src = {
    0,
    0,
    0,
    0,
    0,
    0,
    0x119,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    
    // Cylinder
    0.0, // X
    0.0, // Y
    0.0, // Z
    1000.0, // Radius
    100.0, // Height
};

namespace daTagRet {
    struct Act_c : public fopAc_ac_c {
    public:
        enum Prm_e {
            PRM_PLAYER_ID_W = 8,
            PRM_PLAYER_ID_S = 0,
        };
    
        s32 _create();
        s32 _delete();
        void set_mtx();
        s32 _execute();
        s32 _draw();
    
    public:
        u8 unknown_padding[0xC];
        /* 0x29C */ dCcD_Stts mStts;
        /* 0x2D8 */ dCcD_Cyl mCyl;
    };
    
    /* 00000078-000001D4       .text _create__Q28daTagRet5Act_cFv */
    s32 Act_c::_create() {
        fopAcM_SetupActor(this, daTagRet::Act_c);
        
        if (checkItemGet(PEARL3, TRUE)) {
            return cPhs_UNK3_e;
        }
        
        mStts.Init(0xFF, 0xFF, this);
        mCyl.Set(cyl_check_src);
        mCyl.SetR(1000.0f*mScale.x);
        mCyl.SetH(100.0f*mScale.y);
        mCyl.SetStts(&mStts);
        
        return cPhs_COMPLEATE_e;
    }
    
    /* 0000038C-00000394       .text _delete__Q28daTagRet5Act_cFv */
    s32 Act_c::_delete() {
        return TRUE;
    }
    
    /* 00000394-00000398       .text set_mtx__Q28daTagRet5Act_cFv */
    void Act_c::set_mtx() {
        return;
    }
    
    /* 00000398-00000460       .text _execute__Q28daTagRet5Act_cFv */
    s32 Act_c::_execute() {
        mCyl.SetC(current.pos);
        mCyl.SetR(1000.0f*mScale.x);
        mCyl.SetH(100.0f*mScale.y);
        g_dComIfG_gameInfo.play.mCcS.Set(&mCyl);
        
        if (mCyl.ChkCoHit()) {
            u32 playerId = daObj::PrmAbstract(this, PRM_PLAYER_ID_W, PRM_PLAYER_ID_S);
            daPy_getPlayerLinkActorClass()->onDekuSpReturnFlg(playerId);
        }
        
        set_mtx();
        
        return TRUE;
    }
    
    /* 00000460-00000468       .text _draw__Q28daTagRet5Act_cFv */
    s32 Act_c::_draw() {
        return TRUE;
    }
    
    namespace {
        /* 00000468-00000488       .text Mthd_Create__Q28daTagRet25@unnamed@d_a_tag_ret_cpp@FPv */
        s32 Mthd_Create(void* i_this) {
            return ((Act_c*)i_this)->_create();
        }
    
        /* 00000488-000004AC       .text Mthd_Delete__Q28daTagRet25@unnamed@d_a_tag_ret_cpp@FPv */
        u8 Mthd_Delete(void* i_this) {
            return ((Act_c*)i_this)->_delete();
        }
    
        /* 000004AC-000004D0       .text Mthd_Execute__Q28daTagRet25@unnamed@d_a_tag_ret_cpp@FPv */
        u8 Mthd_Execute(void* i_this) {
            return ((Act_c*)i_this)->_execute();
        }
    
        /* 000004D0-000004F4       .text Mthd_Draw__Q28daTagRet25@unnamed@d_a_tag_ret_cpp@FPv */
        u8 Mthd_Draw(void* i_this) {
            return ((Act_c*)i_this)->_draw();
        }
    
        /* 000004F4-000004FC       .text Mthd_IsDelete__Q28daTagRet25@unnamed@d_a_tag_ret_cpp@FPv */
        u8 Mthd_IsDelete(void* i_this) {
            return TRUE;
        }
        
        static actor_method_class Mthd_Table = {
            (process_method_func)Mthd_Create,
            (process_method_func)Mthd_Delete,
            (process_method_func)Mthd_Execute,
            (process_method_func)Mthd_IsDelete,
            (process_method_func)Mthd_Draw,
        };
    };
};

extern actor_process_profile_definition g_profile_Tag_Ret = {
    fpcLy_CURRENT_e,
    3,
    fpcLy_CURRENT_e,
    PROC_Tag_Ret,
    &g_fpcLf_Method.mBase,
    sizeof(daTagRet::Act_c),
    0,
    0,
    &g_fopAc_Method.base,
    0x005F,
    &daTagRet::Mthd_Table,
    0x00040000,
    fopAc_ACTOR_e,
    fopAc_CULLBOX_0_e,
};
