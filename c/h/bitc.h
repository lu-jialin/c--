#ifndef __BITC_INCLUDE_UNIQ__
#define __BITC_INCLUDE_UNIQ__

#include "bitc.h"

#include <limits.h>

#if 1
#define sign(n) (((n) >> ((sizeof(n)*CHAR_BIT) - 1))|1)
#define abs(n) ((n)*sign(n))
/* duplicated calculate will exist when (n) is a procedure */
#else
inline __attribute__((always_inline)) int _sign(void *_p, size_t size) { return (((*_p) >> ((size*CHAR_BIT) - 1))|1); }
#define sign(n) _sign(&n, sizeof(n))
#endif

#endif
