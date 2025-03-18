//
// Generated by dtk
// Translation Unit: f_op_msg.cpp
//

#include "f_op/f_op_msg.h"
#include "f_op/f_op_draw_tag.h"
#include "f_pc/f_pc_manager.h"
#include "f_op/f_op_msg_mng.h"
#include "d/d_s_play.h"

/* 8002A688-8002A6B0       .text fopMsg_Draw__FPv */
int fopMsg_Draw(void* i_this) {
    msg_class* _this = static_cast<msg_class*>(i_this);
    return fpcLf_DrawMethod((leafdraw_method_class*)_this->sub_method, i_this);
}

/* 8002A6B0-8002A6E8       .text fopMsg_Execute__FPv */
int fopMsg_Execute(void* i_this) {
    msg_class* _this = static_cast<msg_class*>(i_this);

    int stat = 1;
    if (!dScnPly_ply_c::isPause()) {
        stat = fpcMtd_Execute((process_method_class*)_this->sub_method, i_this);
    }

    return stat;
}

/* 8002A6E8-8002A73C       .text fopMsg_IsDelete__FPv */
int fopMsg_IsDelete(void* i_this) {
    msg_class* _this = static_cast<msg_class*>(i_this);

    int stat = fpcMtd_IsDelete((process_method_class*)_this->sub_method, i_this);
    if (stat == 1) {
        fopDwTg_DrawQTo(&_this->draw_tag);
    }

    return stat;
}

/* 8002A73C-8002A788       .text fopMsg_Delete__FPv */
int fopMsg_Delete(void* i_this) {
    msg_class* _this = static_cast<msg_class*>(i_this);

    int stat = fpcMtd_Delete((process_method_class*)_this->sub_method, i_this);
    fopDwTg_DrawQTo(&_this->draw_tag);

    return stat;
}

static int fopMsg_MSG_TYPE;

/* 8002A788-8002A860       .text fopMsg_Create__FPv */
int fopMsg_Create(void* i_this) {
    msg_class* _this = (msg_class*)i_this;

    if (fpcM_IsFirstCreating(_this)) {
        msg_process_profile_definition* profile = (msg_process_profile_definition*)fpcM_GetProfile(i_this);
        _this->mMsgType = fpcBs_MakeOfType(&fopMsg_MSG_TYPE);
        _this->sub_method = profile->sub_method;
        fopDwTg_Init(&_this->draw_tag, _this);
        fopMsg_prm_class* prm = fopMsgM_GetAppend(_this);
        if (prm != NULL) {
            _this->mpActor = prm->mpActor;
            _this->mPos = prm->mPos;
            _this->mMsgNo = prm->mMsgNo;
            _this->field_0xf0 = prm->field_0x14;
            _this->field_0xf4 = prm->field_0x18;
        }
    }

    cPhs_State status = fpcMtd_Create((process_method_class*)_this->sub_method, _this);
    if (status == cPhs_COMPLEATE_e) {
        s32 priority = fpcLf_GetPriority(_this);
        fopDwTg_ToDrawQ(&_this->draw_tag, priority);
    }

    return status;
}

leafdraw_method_class g_fopMsg_Method = {
    (process_method_func)fopMsg_Create,
    (process_method_func)fopMsg_Delete,
    (process_method_func)fopMsg_Execute,
    (process_method_func)fopMsg_IsDelete,
    (process_method_func)fopMsg_Draw,
};
