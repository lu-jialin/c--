#ifndef __LOG_INCLUDE_UNIQ__
#define __LOG_INCLUDE_UNIQ__

//#include <stdio.h>
//#include <errno.h>

#include "log.h"

#define __ext_msg__(msg) ;*__msg_location() = msg;
#define __ext_chk__(chk) ;if(!(chk)) errno = -1;
#ifdef NDEBUG
#define __chk__ ;
#define __skip__(err) ;
#else
#define __chk__ ;if(errno){ fprintf(stderr , "%s:%d:%s:" , __FILE__ , __LINE__ , __func__) ; perror(*__msg_location()) ; exit(-1) ; } else{ *__msg_location() = ""; };
#define __skip__(err) ;errno = (errno == err) ? 0 : errno;
#endif

#if 0
inline __attribute__((always_inline)) char const **
__msg_location()
{
	static char const * _msg_location;
	return &_msg_location;
}
#else
extern char const ** __msg_location();
#define MAIN_POSIX_ERRNO_CHK \
char const ** \
__msg_location() \
{ \
	static char const * _msg_location; \
	return &_msg_location; \
}
#endif

#define __ignore_err__ ;errno = 0;

#define __LOCATION__ __FILE__ , __LINE__ , __func__

#define __msg__(fmt , val)  \
;do{\
	fprintf(stderr , #val " : " fmt , (val));\
}while(0)

#endif
