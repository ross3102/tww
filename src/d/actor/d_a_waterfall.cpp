//
// Generated by dtk
// Translation Unit: d_a_waterfall.cpp
//

#include "d/actor/d_a_waterfall.h"
#include "d/d_procname.h"

/* 00000078-000000F0       .text _delete__9daWfall_cFv */
bool daWfall_c::_delete() {
    /* Nonmatching */
}

/* 000000F0-00000110       .text CheckCreateHeap__FP10fopAc_ac_c */
static BOOL CheckCreateHeap(fopAc_ac_c*) {
    /* Nonmatching */
}

/* 00000110-0000048C       .text CreateHeap__9daWfall_cFv */
void daWfall_c::CreateHeap() {
    /* Nonmatching */
}

/* 0000048C-00000708       .text CreateInit__9daWfall_cFv */
void daWfall_c::CreateInit() {
    /* Nonmatching */
}

/* 00000708-00000838       .text _create__9daWfall_cFv */
cPhs_State daWfall_c::_create() {
    /* Nonmatching */
}

/* 00000938-000009B8       .text set_mtx__9daWfall_cFv */
void daWfall_c::set_mtx() {
    /* Nonmatching */
}

/* 000009B8-00000A1C       .text set_gate_mtx__9daWfall_cFv */
void daWfall_c::set_gate_mtx() {
    /* Nonmatching */
}

/* 00000A1C-00000AD0       .text set_minamo_mtx__9daWfall_cFv */
void daWfall_c::set_minamo_mtx() {
    /* Nonmatching */
}

/* 00000AD0-00000C94       .text _execute__9daWfall_cFv */
bool daWfall_c::_execute() {
    /* Nonmatching */
}

/* 00000C94-00000D20       .text mode_proc_call__9daWfall_cFv */
void daWfall_c::mode_proc_call() {
    /* Nonmatching */
}

/* 00000D20-00000D48       .text mode_wtr_on_init__9daWfall_cFv */
void daWfall_c::mode_wtr_on_init() {
    /* Nonmatching */
}

/* 00000D48-00000DEC       .text mode_wtr_on__9daWfall_cFv */
void daWfall_c::mode_wtr_on() {
    /* Nonmatching */
}

/* 00000DEC-00000E14       .text mode_wtr_off_init__9daWfall_cFv */
void daWfall_c::mode_wtr_off_init() {
    /* Nonmatching */
}

/* 00000E14-00000EE8       .text mode_wtr_off__9daWfall_cFv */
void daWfall_c::mode_wtr_off() {
    /* Nonmatching */
}

/* 00000EE8-00000FF0       .text setEmitter00Pos__9daWfall_cFv */
void daWfall_c::setEmitter00Pos() {
    /* Nonmatching */
}

/* 00000FF0-00001098       .text setEmitter01Pos__9daWfall_cFv */
void daWfall_c::setEmitter01Pos() {
    /* Nonmatching */
}

/* 00001098-000010D8       .text getWaterScaleFromGatePos__9daWfall_cFv */
void daWfall_c::getWaterScaleFromGatePos() {
    /* Nonmatching */
}

/* 000010D8-0000124C       .text getWaterHeight__9daWfall_cFv */
void daWfall_c::getWaterHeight() {
    /* Nonmatching */
}

/* 00001370-000013E0       .text set_se__9daWfall_cFv */
void daWfall_c::set_se() {
    /* Nonmatching */
}

/* 000013E0-00001400       .text daWfall_Create__FPv */
static cPhs_State daWfall_Create(void*) {
    /* Nonmatching */
}

/* 00001400-00001424       .text daWfall_Delete__FPv */
static BOOL daWfall_Delete(void*) {
    /* Nonmatching */
}

/* 00001424-00001550       .text daWfall_Draw__FPv */
static BOOL daWfall_Draw(void*) {
    /* Nonmatching */
}

/* 00001550-00001574       .text daWfall_Execute__FPv */
static BOOL daWfall_Execute(void*) {
    /* Nonmatching */
}

/* 00001574-0000157C       .text daWfall_IsDelete__FPv */
static BOOL daWfall_IsDelete(void*) {
    /* Nonmatching */
}

static actor_method_class daWfallMethodTable = {
    (process_method_func)daWfall_Create,
    (process_method_func)daWfall_Delete,
    (process_method_func)daWfall_Execute,
    (process_method_func)daWfall_IsDelete,
    (process_method_func)daWfall_Draw,
};

actor_process_profile_definition g_profile_WATERFALL = {
    /* LayerID      */ fpcLy_CURRENT_e,
    /* ListID       */ 0x0007,
    /* ListPrio     */ fpcPi_CURRENT_e,
    /* ProcName     */ PROC_WATERFALL,
    /* Proc SubMtd  */ &g_fpcLf_Method.base,
    /* Size         */ sizeof(daWfall_c),
    /* SizeOther    */ 0,
    /* Parameters   */ 0,
    /* Leaf SubMtd  */ &g_fopAc_Method.base,
    /* Priority     */ 0x0195,
    /* Actor SubMtd */ &daWfallMethodTable,
    /* Status       */ fopAcStts_CULL_e | fopAcStts_UNK4000_e | fopAcStts_UNK40000_e,
    /* Group        */ fopAc_ACTOR_e,
    /* CullType     */ fopAc_CULLBOX_CUSTOM_e,
};
