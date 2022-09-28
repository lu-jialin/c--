#ifndef ___CC_INCLUDE_UNIQ__
#define ___CC_INCLUDE_UNIQ__

#include <string.h>
//TODO:
//#include <chrono>

#include "_.h"

#define __abort__ ;fprintf(stderr, "[ABORT]\n");fflush(stdout);abort();

class virtual_t
{
	virtual_t() = delete;
	virtual ~virtual_t() = delete;
};

class prechk_t
{
	virtual ignore_t prechk() = 0;
};

//TODO:
//extern std::chrono::time_point<std::chrono::system_clock> t0, t1;
//t1 = std::chrono::high_resolution_clock::now();
//std::cerr << std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0).count() << "ms" << std::endl;
//t0 = std::chrono::high_resolution_clock::now();
//#define TIME(unit)\
//if(strcmp(#unit, "ms") == 0)\
//{\
//	t1 = std::chrono::high_resolution_clock::now();\
//	std::cerr << std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0).count() << #unit << std::endl;\
//	t0 = std::chrono::high_resolution_clock::now();\
//}\
//else\
//{\
//	t1 = std::chrono::high_resolution_clock::now();\
//	std::cerr << std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count() << #unit << std::endl;\
//	t0 = std::chrono::high_resolution_clock::now();\
//}

#endif
