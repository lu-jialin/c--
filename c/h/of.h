#ifndef __OF_INCLUDE_UNIQ__
#define __OF_INCLUDE_UNIQ__

#include "of.h"

#pragma GCC diagnostic ignored "-Wparentheses"

#define byteof sizeof
#define bitof(type_t) (sizeof(type_t)*CHAR_BIT)
#define elecntof(arr) (sizeof(arr)/sizeof(*(arr)))

#endif
