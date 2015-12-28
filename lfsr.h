#ifndef LFSR
#define LFSR

#include "matrix.h"

#define MASK1 0x3FFFFFFFFFFL
#define MASK2 0xFFFFFFFFFFFL
#define MASK3 0xFFFFFFFFFFFFL
#define POLY1 0x2D
#define POLY2 0x332B
#define POLY3 0x69

/* Create 131 equations for SCEX_T2 */
Matrix create_equations(int* xored);

#endif
