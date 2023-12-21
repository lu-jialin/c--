#ifndef __RANGE_INCLUDE_UNIQ__
#define __RANGE_INCLUDE_UNIQ__

#include "range.h"

#pragma GCC diagnostic ignored "-Wparentheses"

#define enum_list(...) {__VA_ARGS__,
#define enum_suffix(enum_name) enum_name}
#define enumdef(...) enum enum_list(__VA_ARGS__) enum_suffix
#define enumof(enum_name) enum_name
#define enumloop(i , enum_name) for(typeof(enum_name)(i) = 0 ; (i) < enum_name ; i++)

#define layout(   a , p , b ) (((p) >  (a)&&(p) <  (b)) ? 1 : 0)
#define layout_(  a , p , b ) (((p) >  (a)&&(p) <= (b)) ? 1 : 0)
#define _layout(  a , p , b ) (((p) >= (a)&&(p) <  (b)) ? 1 : 0)
#define _layout_( a , p , b ) (((p) >= (a)&&(p) <= (b)) ? 1 : 0)

#define repeat(   s , i , e ) for(typeof(s) i = ((s)+1) , __in_loop##i = (e) ; (i) <  __in_loop##i ; (i)++)
#define _repeat(  s , i , e ) for(typeof(s) i = (s)     , __in_loop##i = (e) ; (i) <  __in_loop##i ; (i)++)
#define repeat_(  s , i , e ) for(typeof(s) i = ((s)+1) , __in_loop##i = (e) ; (i) <= __in_loop##i ; (i)++)
#define _repeat_( s , i , e ) for(typeof(s) i = (s)     , __in_loop##i = (e) ; (i) <= __in_loop##i ; (i)++)
#define traverse( i ,  arr ) for(size_t i = (0) ; i < sizeof(arr)/sizeof(*(arr)) ; (i)++)

#define iterate(p , arr) for(typeof(*arr) *(p) = (arr) ; (size_t)((p)-(arr)) < sizeof(arr)/sizeof(*(arr)) ; (p)++)
#define __init_with__(var , val) ;do{ memset((var) , (val) , sizeof(*var)); }while(0);
#define __init__(var) ;do{ memset((var) , 0 , sizeof(*var)); }while(0);

#endif
