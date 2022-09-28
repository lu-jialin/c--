#ifndef __UNIQ_INCLUDE_UNIQ__
#define __UNIQ_INCLUDE_UNIQ__

#include "_.hh"

template<typename type_t> type_t
&uniq_t()
{
	static type_t uniq;
	return uniq;
}
//此处不使用类是因为operator()()无法作为静态成员

#endif
