//
// Generated by dtk
// Translation Unit: fvb.cpp
//

#include "JSystem/JStudio/JStudio/fvb.h"
#include "JSystem/JStudio/JStudio/fvb-data.h"
#include "JSystem/JUtility/JUTException.h"
#include "dolphin/types.h"
#include "algorithm.h"
#include "string.h"

namespace JStudio {
namespace fvb {

/* 80273964-802739AC       .text __dt__Q37JStudio3fvb7TObjectFv */
TObject::~TObject() {}

/* 802739AC-80273BD0       .text prepare__Q37JStudio3fvb7TObjectFRCQ47JStudio3fvb4data13TParse_TBlockPQ37JStudio3fvb8TControl */
void TObject::prepare(const data::TParse_TBlock& rBlock, TControl* pControl) {
    /* Nonmatching - regalloc */
    TFunctionValueAttributeSet_const set = pfv_->getAttributeSet();
    const void* pNext;
    const void* pData;
    pNext = rBlock.getNext();
    pData = rBlock.getContent();
    while (pData < pNext) {
        data::TParse_TParagraph para(pData);
        data::TParse_TParagraph::TData dat;
        para.getData(&dat);
        u32 u32Type = dat.u32Type;
        u32 u32Size = dat.u32Size;
        const void* pContent = dat.pContent;
        TFunctionValueAttribute_range* pfvaRange = set.range_get();
        TFunctionValueAttribute_refer* referGet;
        TFunctionValueAttribute_interpolate* pfvaInterpolate = set.interpolate_get();

        switch (u32Type) {
        case 0:
            goto prepare_end;
        case 1: {
            prepare_data_(dat, pControl);
        } break;
        case 0x10: {
            referGet = set.refer_get();

            if (!referGet) {
                break;
            }

            JGadget::TVector_pointer<TFunctionValue*>& rCnt = referGet->refer_referContainer();

            typedef struct {
                u32 length;
                const u8 data[0];
            } unkDataHeader;

            typedef struct {
                u32 count;
                unkDataHeader dataArray[0];
            } unkDataArray;

            const unkDataArray* i = static_cast<const unkDataArray*>(pContent);
            u32 dataCount = i->count;
            const unkDataHeader* d = i->dataArray;

            for (; dataCount != 0; dataCount--) {
                u32 length = d->length;

                TObject* pObject = pControl->getObject(&d->data, length);

                if (pObject) {
                    TFunctionValue* rfv = pObject->referFunctionValue();
                    rCnt.push_back(rfv);
                }

#ifdef __MWERKS__ // clang-format off
                (const u8*)d += align_roundUp(length, sizeof(u32)) + sizeof(u32);
#else
                d = (const unkDataHeader*)(((const u8*)d) + align_roundUp(length, sizeof(u32)) + sizeof(u32));
#endif // clang-format on
            }
        } break;
        case 0x11: {
            TFunctionValueAttribute_refer* pfvaRefer = set.refer_get();

            if (!pfvaRefer) {
                break;
            }

            JGadget::TVector_pointer<TFunctionValue*>& rCnt = pfvaRefer->refer_referContainer();

            const u32* i = static_cast<const u32*>(pContent);
            u32 ii = *i;

            for (; i++, ii != 0; ii--) {
                u32 length = *i;
                TObject* pObject = pControl->getObject_index(length);
                if (pObject) {
                    TFunctionValue* rfv = pObject->referFunctionValue();
                    rCnt.push_back(rfv);
                }
            }
        } break;
        case 0x12: {
            if (!pfvaRange) {
                break;
            }
            const f32* arr = static_cast<const f32*>(pContent);

            pfvaRange->range_set(arr[0], arr[1]);
        } break;
        case 0x13: {
            if (!pfvaRange) {
                break;
            }

            TFunctionValue::TEProgress prog = *static_cast<const TFunctionValue::TEProgress*>(pContent);
            pfvaRange->range_setProgress(prog);

        } break;
        case 0x14: {
            if (!pfvaRange) {
                break;
            }

            TFunctionValue::TEAdjust adjust = *static_cast<const TFunctionValue::TEAdjust*>(pContent);
            pfvaRange->range_setAdjust(adjust);

        } break;
        case 0x15: {
            if (!pfvaRange) {
                break;
            }

            TFunctionValue::TEOutside a = (TFunctionValue::TEOutside)(static_cast<const u16*>(pContent))[0];
            TFunctionValue::TEOutside b = (TFunctionValue::TEOutside)(static_cast<const u16*>(pContent))[1];

            pfvaRange->range_setOutside(a, b);

        } break;
        case 0x16: {
            if (!pfvaInterpolate) {
                break;
            }

            TFunctionValue::TEInterpolate interp = *static_cast<const TFunctionValue::TEInterpolate*>(pContent);
            pfvaInterpolate->interpolate_set(interp);

        } break;
        }
        pData = dat.next;
    }

prepare_end:
    pfv_->prepare();
}

namespace {

/* 80273BD0-80273BDC       .text getCompositeData_raw___Q37JStudio3fvb17@unnamed@fvb_cpp@FPCv */
TFunctionValue_composite::TData getCompositeData_raw_(const void* arg1) {
    return TFunctionValue_composite::TData(*(const void**)arg1);
}

/* 80273BDC-80273BE8       .text getCompositeData_index___Q37JStudio3fvb17@unnamed@fvb_cpp@FPCv */
TFunctionValue_composite::TData getCompositeData_index_(const void* arg1) {
    return TFunctionValue_composite::TData(*(u32*)arg1);
}

/* 80273BE8-80273BF4       .text getCompositeData_parameter___Q37JStudio3fvb17@unnamed@fvb_cpp@FPCv */
TFunctionValue_composite::TData getCompositeData_parameter_(const void* arg1) {
    return TFunctionValue_composite::TData(*(f32*)arg1);
}

/* 80273BF4-80273C00       .text getCompositeData_add___Q37JStudio3fvb17@unnamed@fvb_cpp@FPCv */
TFunctionValue_composite::TData getCompositeData_add_(const void* arg1) {
    return TFunctionValue_composite::TData(*(f32*)arg1);
}

/* 80273C00-80273C0C       .text getCompositeData_subtract___Q37JStudio3fvb17@unnamed@fvb_cpp@FPCv */
TFunctionValue_composite::TData getCompositeData_subtract_(const void* arg1) {
    return TFunctionValue_composite::TData(*(f32*)arg1);
}

/* 80273C0C-80273C18       .text getCompositeData_multiply___Q37JStudio3fvb17@unnamed@fvb_cpp@FPCv */
TFunctionValue_composite::TData getCompositeData_multiply_(const void* arg1) {
    return TFunctionValue_composite::TData(*(f32*)arg1);
}

/* 80273C18-80273C24       .text getCompositeData_divide___Q37JStudio3fvb17@unnamed@fvb_cpp@FPCv */
TFunctionValue_composite::TData getCompositeData_divide_(const void* arg1) {
    return TFunctionValue_composite::TData(*(f32*)arg1);
}

static const data::CompositeOperation saCompositeOperation_[data::COMPOSITE_ENUM_SIZE] = {
    { NULL, NULL },                                                                   // COMPOSITE_NONE
    { &TFunctionValue_composite::composite_raw, &getCompositeData_raw_ },             // COMPOSITE_RAW
    { &TFunctionValue_composite::composite_index, &getCompositeData_index_ },         // COMPOSITE_IDX
    { &TFunctionValue_composite::composite_parameter, &getCompositeData_parameter_ }, // COMPOSITE_PARAM
    { &TFunctionValue_composite::composite_add, &getCompositeData_add_ },             // COMPOSITE_ADD
    { &TFunctionValue_composite::composite_subtract, &getCompositeData_subtract_ },   // COMPOSITE_SUB
    { &TFunctionValue_composite::composite_multiply, &getCompositeData_multiply_ },   // COMPOSITE_MUL
    { &TFunctionValue_composite::composite_divide, &getCompositeData_divide_ },       // COMPOSITE_DIV
};

/* 80273C24-80273C38       .text getCompositeOperation___Q37JStudio3fvb17@unnamed@fvb_cpp@FQ47JStudio3fvb4data11TEComposite */
const data::CompositeOperation* getCompositeOperation_(data::TEComposite r3) {
    return &saCompositeOperation_[r3];
}

}  // namespace

/* 80273C38-80273CB8       .text __ct__Q37JStudio3fvb17TObject_compositeFRCQ47JStudio3fvb4data13TParse_TBlock */
TObject_composite::TObject_composite(const data::TParse_TBlock& block) : TObject(block, &fnValue) {
    /* Nonmatching */
}

/* 80273CB8-80273D1C       .text prepare_data___Q37JStudio3fvb17TObject_compositeFRCQ57JStudio3fvb4data17TParse_TParagraph5TDataPQ37JStudio3fvb8TControl */
void TObject_composite::prepare_data_(const data::TParse_TParagraph::TData& rData, TControl* control) {
    typedef struct {
        JStudio::fvb::data::TEComposite _00;
        const void* _04;
    } unkOperation;

    u32 u32Size = rData.u32Size;

    const void* pControl_ = rData.pContent;
    const unkOperation* content = (const unkOperation*)(pControl_);
    JStudio::fvb::data::TEComposite v = content->_00;
    const data::CompositeOperation* res = getCompositeOperation_(v);
    TFunctionValue_composite::GetCompositeFunc pfvaRange = res->mGetFunc;

    fnValue.data_set(res->mSetFunc, pfvaRange(&content->_04));
}

/* 80273D1C-80273D9C       .text __ct__Q37JStudio3fvb16TObject_constantFRCQ47JStudio3fvb4data13TParse_TBlock */
TObject_constant::TObject_constant(const data::TParse_TBlock& block) : TObject(block, &fnValue) {
    /* Nonmatching */
}

/* 80273D9C-80273DAC       .text prepare_data___Q37JStudio3fvb16TObject_constantFRCQ57JStudio3fvb4data17TParse_TParagraph5TDataPQ37JStudio3fvb8TControl */
void TObject_constant::prepare_data_(const data::TParse_TParagraph::TData& rData, TControl* control) {
    ASSERT(rData.u32Type == data::PARAGRAPH_DATA);

    u32 u32Size = rData.u32Size;
    JUT_EXPECT(u32Size == 4);

    const f32* pContent = static_cast<const f32*>(rData.pContent);
    ASSERT(pContent != NULL);

    fnValue.data_set(pContent[0]);
}

/* 80273DAC-80273E2C       .text __ct__Q37JStudio3fvb18TObject_transitionFRCQ47JStudio3fvb4data13TParse_TBlock */
TObject_transition::TObject_transition(const data::TParse_TBlock& block) : TObject(block, &fnValue) {
    /* Nonmatching */
}

/* 80273E2C-80273E44       .text prepare_data___Q37JStudio3fvb18TObject_transitionFRCQ57JStudio3fvb4data17TParse_TParagraph5TDataPQ37JStudio3fvb8TControl */
void TObject_transition::prepare_data_(const data::TParse_TParagraph::TData& rData, TControl* control) {
    ASSERT(rData.u32Type == data::PARAGRAPH_DATA);

    u32 u32Size = rData.u32Size;
    JUT_EXPECT(u32size == 8);

    const f32* pContent = static_cast<const f32*>(rData.pContent);
    ASSERT(pContent != NULL);

    fnValue.data_set(pContent[0], pContent[1]);
}

/* 80273E44-80273EC4       .text __ct__Q37JStudio3fvb12TObject_listFRCQ47JStudio3fvb4data13TParse_TBlock */
TObject_list::TObject_list(const data::TParse_TBlock& block) : TObject(block, &fnValue) {
    /* Nonmatching */
}

/* 80273EC4-80273EE4       .text prepare_data___Q37JStudio3fvb12TObject_listFRCQ57JStudio3fvb4data17TParse_TParagraph5TDataPQ37JStudio3fvb8TControl */
void TObject_list::prepare_data_(const data::TParse_TParagraph::TData& rData, TControl* control) {
    ASSERT(rData.u32Type == data::PARAGRAPH_DATA);

    u32 u32Size = rData.u32Size;
    JUT_EXPECT(u32size >= 8);

    const ListData* pContent = static_cast<const ListData*>(rData.pContent);
    ASSERT(pContent != NULL);

    fnValue.data_setInterval(pContent->_0);
    fnValue.data_set(pContent->_8, pContent->_4);
}

/* 80273EE4-80273F64       .text __ct__Q37JStudio3fvb22TObject_list_parameterFRCQ47JStudio3fvb4data13TParse_TBlock */
TObject_list_parameter::TObject_list_parameter(const data::TParse_TBlock& block) : TObject(block, &fnValue) {
    /* Nonmatching */
}

/* 80273F64-80273F94       .text prepare_data___Q37JStudio3fvb22TObject_list_parameterFRCQ57JStudio3fvb4data17TParse_TParagraph5TDataPQ37JStudio3fvb8TControl */
void TObject_list_parameter::prepare_data_(const data::TParse_TParagraph::TData& rData, TControl* control) {
    ASSERT(rData.u32Type == data::PARAGRAPH_DATA);

    u32 u32Size = rData.u32Size;
    JUT_EXPECT(u32size >= 8);

    const ListData* pContent = static_cast<const ListData*>(rData.pContent);
    ASSERT(pContent != NULL);

    fnValue.data_set(pContent->_4, pContent->_0);
}

/* 80273F94-80274014       .text __ct__Q37JStudio3fvb15TObject_hermiteFRCQ47JStudio3fvb4data13TParse_TBlock */
TObject_hermite::TObject_hermite(const data::TParse_TBlock& block) : TObject(block, &fnValue) {
    /* Nonmatching */
}

/* 80274014-8027404C       .text prepare_data___Q37JStudio3fvb15TObject_hermiteFRCQ57JStudio3fvb4data17TParse_TParagraph5TDataPQ37JStudio3fvb8TControl */
void TObject_hermite::prepare_data_(const data::TParse_TParagraph::TData& rData, TControl* control) {
    ASSERT(rData.u32Type == data::PARAGRAPH_DATA);

    u32 u32Size = rData.u32Size;
    JUT_EXPECT(u32size >= 8);

    const ListData* pContent = static_cast<const ListData*>(rData.pContent);
    ASSERT(pContent != NULL);

    fnValue.data_set(pContent->_4, pContent->_0 & 0xFFFFFFF, pContent->_0 >> 0x1C);
}

/* 8027404C-8027407C       .text __ct__Q37JStudio3fvb8TControlFv */
TControl::TControl() : pFactory(NULL) {}

/* 8027407C-802740E8       .text __dt__Q37JStudio3fvb8TControlFv */
TControl::~TControl() {}

/* 802740E8-80274134       .text appendObject__Q37JStudio3fvb8TControlFPQ37JStudio3fvb7TObject */
void TControl::appendObject(TObject* pObject) {
    ocObject_.Push_back(pObject);
}

/* 80274134-80274164       .text removeObject__Q37JStudio3fvb8TControlFPQ37JStudio3fvb7TObject */
void TControl::removeObject(TObject* pObject) {
    ocObject_.Erase(pObject);
}

/* 80274164-802741B4       .text destroyObject__Q37JStudio3fvb8TControlFPQ37JStudio3fvb7TObject */
void TControl::destroyObject(TObject* pObject) {
    removeObject(pObject);
    getFactory()->destroy(pObject);
}

/* 802741B4-80274218       .text destroyObject_all__Q37JStudio3fvb8TControlFv */
void TControl::destroyObject_all() {
    while (!ocObject_.empty()) {
        destroyObject(&ocObject_.back());
    }
}

/* 80274218-802742B8       .text getObject__Q37JStudio3fvb8TControlFPCvUl */
TObject* TControl::getObject(const void* param_0, u32 param_1) {
    /* Nonmatching - TPRObject_ID_equal copy issue */
    JGadget::TLinkList<TObject, -12>::iterator begin = ocObject_.begin();
    JGadget::TLinkList<TObject, -12>::iterator end = ocObject_.end();
    JGadget::TLinkList<TObject, -12>::iterator local_50 = std::find_if(begin, end, object::TPRObject_ID_equal(param_0, param_1));
    if ((local_50 != end) != false) {
        return &*local_50;
    }
    return NULL;
}

/* 802742B8-802742FC       .text getObject_index__Q37JStudio3fvb8TControlFUl */
TObject* TControl::getObject_index(u32 idx) {
    if (idx >= ocObject_.size()) {
        return NULL;
    }

    JGadget::TLinkList<TObject, -12>::iterator begin(ocObject_.begin());
    while (idx != 0) {
        begin++;
        idx--;
    }
    return &*begin;
}

/* 802742FC-80274344       .text __dt__Q37JStudio3fvb8TFactoryFv */
TFactory::~TFactory() {}

/* 80274344-80274484       .text create__Q37JStudio3fvb8TFactoryFRCQ47JStudio3fvb4data13TParse_TBlock */
TObject* TFactory::create(const data::TParse_TBlock& rBlock) {
    switch (rBlock.get_type()) {
    case 1:
        return new TObject_composite(rBlock);
    case 2:
        return new TObject_constant(rBlock);
    case 3:
        return new TObject_transition(rBlock);
    case 4:
        return new TObject_list(rBlock);
    case 5:
        return new TObject_list_parameter(rBlock);
    case 6:
        return new TObject_hermite(rBlock);
    default:
        JUTWarn w;
        w << "unknown type : ";
        return NULL;
    }
}

/* 80274484-802744C0       .text destroy__Q37JStudio3fvb8TFactoryFPQ37JStudio3fvb7TObject */
void TFactory::destroy(TObject* pObject) {
    delete pObject;
}

/* 802744C0-802744E0       .text __ct__Q37JStudio3fvb6TParseFPQ37JStudio3fvb8TControl */
TParse::TParse(TControl* pControl) : pControl_(pControl) {}

/* 802744E0-80274540       .text __dt__Q37JStudio3fvb6TParseFv */
TParse::~TParse() {}

/* 80274540-802745D4       .text parseHeader_next__Q37JStudio3fvb6TParseFPPCvPUlUl */
bool TParse::parseHeader_next(const void** ppData_inout, u32* puBlock_out, u32 flags) {
    ASSERT(ppData_inout != 0);
    ASSERT(puBlock_out != 0);

    const void* pData = *ppData_inout;
    ASSERT(pData != 0);

    const data::TParse_THeader header(pData);
    *ppData_inout = header.getContent();
    *puBlock_out = header.get_blockNumber();

    if (memcmp(header.get_signature(), &data::ga4cSignature, 4) != 0) {
        JUTWarn w;
        w << "unknown signature";
        return false;
    }

    if (header.get_byteOrder() != 0xFEFF) {
        JUTWarn w;
        w << "illegal byte-order";
        return false;
    }
    u16 version = header.get_version();
    if (version < 2) {
        JUTWarn w;
        w << "obselete version : " << (long)0;
        return false;
    } else if (version > 0x100) {
        JUTWarn w;
        w << "unknown version : " << version;
        return false;
    }
    return true;
}

/* 802745D4-802746C8       .text parseBlock_next__Q37JStudio3fvb6TParseFPPCvPUlUl */
bool TParse::parseBlock_next(const void** ppData_inout, u32* puData_out, u32 flags) {
    ASSERT(ppData_inout != 0);
    ASSERT(puData_out != 0);

    const void* pData = *ppData_inout;
    ASSERT(pData != 0);
    data::TParse_TBlock blk(pData);
    *ppData_inout = blk.getNext();
    *puData_out = blk.get_size();

    TControl* pControl = getControl();
    ASSERT(pControl != 0);

    if (flags & 0x10) {
        if (pControl->getObject(blk.get_ID(), blk.get_IDSize()) != NULL)
            return true;
    }
    if (flags & 0x20) {
        return true;
    }

    TFactory* pFactory = pControl->getFactory();
    if (pFactory == NULL) {
        JUTWarn w;
        w << "factory not specified";
        return false;
    }

    TObject* pObject = pFactory->create(blk);
    if (pObject == NULL) {
        JUTWarn w;
        w << "can't create function-value";
        if (flags & 0x40) {
            return true;
        }
        return false;
    }
    pObject->prepare(blk, pControl);
    pControl->appendObject(pObject);
    return true;
}

}  // namespace fvb
}  // namespace JStudio
