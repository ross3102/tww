//
// Generated by dtk
// Translation Unit: f_pc_creator.cpp
//

#include "f_pc/f_pc_creator.h"
#include "f_pc/f_pc_base.h"
#include "f_pc/f_pc_create_req.h"

/* 8003D0E8-8003D108       .text fpcCt_IsCreatingByID__FUi */
BOOL fpcCt_IsCreatingByID(fpc_ProcID i_id) {
    return fpcCtRq_IsCreatingByID(i_id);
}

/* 8003D108-8003D12C       .text fpcCt_IsDoing__FP18base_process_class */
BOOL fpcCt_IsDoing(base_process_class* i_proc) {
    return fpcCtRq_IsDoing(i_proc->mpCtRq);
}

/* 8003D12C-8003D150       .text fpcCt_Abort__FP18base_process_class */
BOOL fpcCt_Abort(base_process_class* i_proc) {
    return fpcCtRq_Cancel(i_proc->mpCtRq);
}

/* 8003D150-8003D170       .text fpcCt_Handler__Fv */
BOOL fpcCt_Handler() {
    return fpcCtRq_Handler();
}
