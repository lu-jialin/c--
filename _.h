#ifndef ___INCLUDE_UNIQ__
#define ___INCLUDE_UNIQ__

#pragma GCC diagnostic ignored "-Wparentheses"

#include <stddef.h>
#include <sys/types.h>
#include <sched.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdarg.h>
#include <errno.h>
#include <error.h>
#include <unistd.h>
#include <limits.h>

//typedef unsigned char     byte_t ;
#define uint_t   unsigned int
#define char_t   char
#define int_t    int
#define float_t  float
#define double_t double
#define auto_t   auto
#define byte_t char_t
typedef unsigned char     bit_t  ;
typedef int      main_t   ;
typedef void     ignore_t ;
typedef void     any_t    ;
typedef FILE     FILE_t   ;
typedef bool     bool_t   ;
typedef va_list va_list_t ;

#define __LOCATION__ __FILE__, __LINE__, __func__

#define elecntof(arr) sizeof(arr)/sizeof(*(arr))

#define layout(a, p, b) (((p)>(a)&&(p)<(b)) ? 1 : 0)
#define layout_(a, p, b) (((p)>(a)&&(p)<=(b)) ? 1 : 0)
#define _layout(a, p, b) (((p)>=(a)&&(p)<(b)) ? 1 : 0)
#define _layout_(a, p, b) (((p)>=(a)&&(p)<=(b)) ? 1 : 0)
#define _repeat_(s, i, e) for(typeof(s) i = (s), __in_loop##e = (e); (i) <= __in_loop##e ; (i)++)
#define _repeat(s, i,  e) for(typeof(s) i = (s), __in_loop##e = (e); (i) <  __in_loop##e ; (i)++)
#define repeat(i,  arr) for(size_t i = (0); i < elecntof(arr); (i)++)
#define iterate(p, arr) for(typeof(*arr) *(p) = (arr); (size_t)((p)-(arr)) < elecntof(arr); (p)++)
#define __init__(var) ;do { memset((var), 0, sizeof(*var)); }while(0);
//#define __msg__(fmt, val)  \
//;do\
//{\
//	if(!fmt) { errno = -1; } __ext_msg__("[ERR]format string is NULL") __chk__;\
//	fprintf(stderr, #val " : " fmt, (val));\
//}while(0)
#define __msg__(fmt, val)  \
;do\
{\
	fprintf(stderr, #val " : " fmt, (val));\
}while(0)

#define enum_list(...) {__VA_ARGS__,
#define enum_suffix(enum_name) enum_name}
#define enumdef(...) enum enum_list(__VA_ARGS__) enum_suffix
#define enumof(enum_name) enum_name
#define enumloop(i, enum_name) for(typeof(enum_name) (i) = 0; (i) < enum_name; i++)

#define __ext_msg__(msg) ;*__msg_location() = msg;
#define __ext_chk__(chk) ;if(!(chk)) errno = -1;
#ifdef NDEBUG
#define __chk__ ;
#define __skip__(err) ;
#else
#define __chk__ ;if(errno){ fprintf(stderr, "%s:%d:%s:", __FILE__, __LINE__, __func__); perror(*__msg_location()); exit(-1); } else{ *__msg_location() = ""; };
#define __skip__(err) ;errno = (errno == err) ? 0 : errno;
#endif

#define __ignore_err__ ;errno = 0;

#define byteof sizeof
#define bitof(type_t) (sizeof(type_t)*CHAR_BIT)

#ifdef BIT_CALC
#if 1
#define sign(n) (((n) >> (bitof(n) - 1))|1)
#define abs(n) ((n)*sign(n))
/* duplicated calculate will exist when (n) is a procedure */
#else
inline __attribute__((always_inline)) int _sign(void *_p, size_t size) { return (((*_p) >> ((size*CHAR_BIT) - 1))|1); }
#define sign(n) _sign(&n, sizeof(n))
#endif
#endif

#if 0
inline __attribute__((always_inline)) char
const **__msg_location()
{
	static char const *_msg_location;
	return &_msg_location;
}
#else
char const **__msg_location();
#define MAIN_POSIX_ERRNO_CHK \
char \
const **__msg_location() \
{ \
	static char const *_msg_location; \
	return &_msg_location; \
}
#endif

#endif
