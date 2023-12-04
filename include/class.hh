#ifndef __CLASS_INCLUDE_UNIQ__
#define __CLASS_INCLUDE_UNIQ__

#include "class.hh"

class virtual_t
{
	virtual_t() = delete;
	virtual ~virtual_t() = delete;
};

class prechk_t
{
	virtual ignore_t prechk() = 0;
};


#endif
