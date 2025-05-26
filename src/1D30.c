#include "common.h"

void func_80099F70(s32, s32);
extern OSMesgQueue D_800D3CE8;

INCLUDE_ASM("asm/nonmatchings/1D30", func_80026930);

INCLUDE_ASM("asm/nonmatchings/1D30", func_80026A30);

INCLUDE_ASM("asm/nonmatchings/1D30", func_80026B9C);

INCLUDE_ASM("asm/nonmatchings/1D30", func_80026BD0);

INCLUDE_ASM("asm/nonmatchings/1D30", func_80026C80);

INCLUDE_ASM("asm/nonmatchings/1D30", func_800270F8);

INCLUDE_ASM("asm/nonmatchings/1D30", func_8002724C);

INCLUDE_ASM("asm/nonmatchings/1D30", func_80027334);

void func_80027388(u32 romStart, u32 romEnd, u32* segmentVramStart, u32 textStart, u32 textEnd, u32 dataStart, u32 dataEnd, u32 bssStart, u32 bssEnd) {
    OSIoMesg sp20;
    void* sp38;
    u32 mesgSize;
    u32 dmaTotalSize;
    u32 devAddr;
    void* buf_ptr;

    if (bssEnd != bssStart) {
        bzero((void*)bssStart, bssEnd - bssStart);
    }
    osInvalICache((void*)textStart, textEnd - textStart);
    osInvalDCache((void*)dataStart, dataEnd - dataStart);
    dmaTotalSize = ALIGN(romEnd - romStart, 2); //2 byte aligned
    devAddr = romStart;
    buf_ptr = segmentVramStart;
    
    while (dmaTotalSize != 0) {
        mesgSize = dmaTotalSize;

        if (dmaTotalSize > 0x1000) {
            mesgSize = 0x1000;
        }

        osPiStartDma(&sp20, 0, 0, devAddr, buf_ptr, mesgSize, &D_800D3CE8);
        osRecvMesg(&D_800D3CE8, &sp38, 1);

        devAddr += mesgSize;
        dmaTotalSize -= mesgSize;
        buf_ptr += mesgSize;
    }
}

INCLUDE_ASM("asm/nonmatchings/1D30", func_80027490);

INCLUDE_ASM("asm/nonmatchings/1D30", func_8002753C);
