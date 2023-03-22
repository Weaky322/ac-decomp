#ifndef M_NMIBUF_H
#define M_NMIBUF_H

#include "types.h"
#include "libultra/libultra.h"

#ifdef __cplusplus
extern "C" {
#endif

#define APPNMI_FLAGS_IDX 15

#define APPNMI_SET(v) (osAppNMIBuffer[APPNMI_FLAGS_IDX] |= v)
#define APPNMI_CLR(v) (osAppNMIBuffer[APPNMI_FLAGS_IDX] &= ~v)
#define APPNMI_GET(v) (osAppNMIBuffer[APPNMI_FLAGS_IDX] & v)
#define APPNMI_FLP(v) (osAppNMIBuffer[APPNMI_FLAGS_IDX] ^= v)

/* ZURUMODE (Cheat mode) related values */
#define APPNMI_ZURUMODE_SET() APPNMI_SET(1)
#define APPNMI_ZURUMODE_CLR() APPNMI_CLR(1)
#define APPNMI_ZURUMODE_GET() APPNMI_GET(1)
#define APPNMI_ZURUMODE_FLP() APPNMI_FLP(1)
#define APPNMI_ZURUMODE2_SET() APPNMI_SET(8)
#define APPNMI_ZURUMODE2_CLR() APPNMI_CLR(8)
#define APPNMI_ZURUMODE2_GET() APPNMI_GET(8)
#define APPNMI_ZURUMODE2_FLP() APPNMI_FLP(8)
#define APPNMI_ZURUMODE3_SET() APPNMI_SET(16)
#define APPNMI_ZURUMODE3_CLR() APPNMI_CLR(16)
#define APPNMI_ZURUMODE3_GET() APPNMI_GET(16)
#define APPNMI_ZURUMODE3_FLP() APPNMI_FLP(16)

#define APPNMI_RESETEXEMPT_SET() APPNMI_SET(2)
#define APPNMI_RESETEXEMPT_CLR() APPNMI_CLR(2)
#define APPNMI_RESETEXEMPT_GET() APPNMI_GET(2)
#define APPNMI_RESETEXEMPT_FLP() APPNMI_FLP(2)
#define APPNMI_RESETEXEMPT2_SET() APPNMI_SET(4)
#define APPNMI_RESETEXEMPT2_CLR() APPNMI_CLR(4)
#define APPNMI_RESETEXEMPT2_GET() APPNMI_GET(4)
#define APPNMI_RESETEXEMPT2_FLP() APPNMI_FLP(4)

#define APPNMI_DEBUGMODE_SET() APPNMI_SET(32)
#define APPNMI_DEBUGMODE_CLR() APPNMI_CLR(32)
#define APPNMI_DEBUGMODE_GET() APPNMI_GET(32)
#define APPNMI_DEBUGMODE_FLP() APPNMI_FLP(32)

#define APPNMI_TESTMODE_SET() APPNMI_SET(64)
#define APPNMI_TESTMODE_CLR() APPNMI_CLR(64)
#define APPNMI_TESTMODE_GET() APPNMI_GET(64)
#define APPNMI_TESTMODE_FLP() APPNMI_FLP(64)

/* Not fully sure this is the right name */
#define APPNMI_HOTRESET_SET() (osAppNMIBuffer[APPNMI_FLAGS_IDX] |= 0x200)
#define APPNMI_HOTRESET_CLR() (osAppNMIBuffer[APPNMI_FLAGS_IDX] &= ~0x200)
#define APPNMI_HOTRESET_GET() (osAppNMIBuffer[APPNMI_FLAGS_IDX] & 0x200)
#define APPNMI_HOTRESET_FLP() (osAppNMIBuffer[APPNMI_FLAGS_IDX] ^= 0x200)

#define APPNMI_

#ifdef __cplusplus
}
#endif

#endif
