#pragma once
#include "config_common.h"
#define VENDOR_ID       0x4B42 // KB
#define PRODUCT_ID      0x1225
#define DEVICE_VER      0x0002
#define MANUFACTURER    KBDfans
#define PRODUCT         kbd67mkiirgb v2

#define MATRIX_ROWS 5
#define MATRIX_COLS 15
#define MATRIX_ROW_PINS {F0, F1, F4, E6, C6 }
#define MATRIX_COL_PINS {F7, F6, F5, C7, B0, B1, B2, B3, B4, D7, D6, D4, D5, D3, D2}
#define DIODE_DIRECTION COL2ROW

/* #define COMBO_COUNT 4 */
/* #define COMBO_TERM 10 */
