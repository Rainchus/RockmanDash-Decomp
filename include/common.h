#ifndef _COMMON_H_
#define _COMMON_H_

#define IS_DEBUG_PANIC(statement, file, line) do {} while(1)
#define ASSERT(condition) \
    if (!(condition)) { \
        IS_DEBUG_PANIC("Assertion failed: " #condition, __FILE__, __LINE__); \
    }

#define FALSE 0
#define TRUE 1

#include "ultra64.h"
#include "types.h"
#include "include_asm.h"
#include "ld_addrs.h"
#include "macros.h"

#endif
