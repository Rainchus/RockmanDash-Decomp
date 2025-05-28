#include "common.h"

void func_80092560(void);
void func_800927A4(void);
void func_8009292C(Gfx*, s32, s32, s32);
void func_80092B10(void*);
void func_80092B70(void);
void func_80092C10(void*, s32);
extern s32 D_800A6970; //unk type
extern u16* gFrameBufferPtrs[2];
extern u8* gDepthBufferPtr;
extern s32* D_801E0EF0; //unk type
extern s32 D_801E6CB0;
extern Gfx D_800A6980[];
extern void func_80092B50(void);
extern u16* gFrameBufferPtrs[2];
extern void func_80092D60(void*, s32);

void func_80025C60(void) {
    Gfx sp10[257];

    func_80092B70();
    func_80092C10(gFrameBufferPtrs, 2);
    gDepthBufferPtr = (u8* )0x80000400;
    func_80092B10(func_80092B50);
    func_80092D60(&D_801E6CB0, 0x20000);
    D_801E0EF0 = &D_800A6970;
    func_800927A4();
    
    //jump an link to DL at D_800A6980
    sp10[0].words.w0 = 0xDE000000;
    sp10[0].words.w1 = OS_K0_TO_PHYSICAL(D_800A6980);

    //full sync
    sp10[1].words.w0 = 0xE9000000;
    sp10[1].words.w1 = 0;

    //end DL
    sp10[2].words.w0 = 0xDF000000;
    sp10[2].words.w1 = 0;
    
    func_8009292C(sp10, 0x18, 0, 0x40000);
    func_80092B70();
}

void func_80025D14(void) {
    Gfx sp10[256];

    func_80092560();
    func_80092B70();
    func_80092C10(gFrameBufferPtrs, 2);
    gDepthBufferPtr = (void*)0x80000400; //this cant be a symbol, is hardcoded to this address
    func_80092B10(&func_80092B50);
    func_80092D60(&D_801E6CB0, 0x20000);
    D_801E0EF0 = &D_800A6970;
    func_800927A4();

    //jump an link to DL at D_800A6980
    sp10[0].words.w0 = 0xDE000000;
    sp10[0].words.w1 = OS_K0_TO_PHYSICAL(D_800A6980);

    //full sync
    sp10[1].words.w0 = 0xE9000000;
    sp10[1].words.w1 = 0;

    //end DL
    sp10[2].words.w0 = 0xDF000000;
    sp10[2].words.w1 = 0;
    
    func_8009292C(sp10, 0x18, 0, 0x40000);
    func_80092B70();
}

INCLUDE_ASM("asm/nonmatchings/1060", func_80025DD0);

INCLUDE_ASM("asm/nonmatchings/1060", func_80025E1C);

INCLUDE_ASM("asm/nonmatchings/1060", func_80025E3C);

INCLUDE_ASM("asm/nonmatchings/1060", func_80025FF8);

void func_8002609C(void) {
}

INCLUDE_ASM("asm/nonmatchings/1060", func_800260A4);

INCLUDE_ASM("asm/nonmatchings/1060", func_800260B0);

INCLUDE_ASM("asm/nonmatchings/1060", func_800260E4);

INCLUDE_ASM("asm/nonmatchings/1060", func_800260EC);

INCLUDE_ASM("asm/nonmatchings/1060", func_800260F4);
