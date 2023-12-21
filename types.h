#ifndef __TYPES_INCLUDE_UNIQ__
#define __TYPES_INCLUDE_UNIQ__

#include "types.h"

#define uint_t   unsigned int
#define char_t   char
#define int_t    int
#define float_t  float
#define double_t double
#define byte_t   char_t
/*
NOTE :
`#define` but not `typedef` is to use `signed`/`unsigned` as qualifier :
`unsigned int_t` `signed char_t`
*/

typedef unsigned char bit_t ;
typedef int      main_t   ;
typedef void     ignore_t ;
typedef void     any_t    ;

#if 0 /* Types below need to include other headers */
typedef FILE    FILE_t    ;
typedef bool    bool_t    ;
typedef va_list va_list_t ;
#endif

#endif
