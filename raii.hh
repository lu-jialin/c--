#ifndef __RAII_INCLUDE_UNIQ__
#define __RAII_INCLUDE_UNIQ__

#include <sys/syscall.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <thread>

#include "_.hh"

#include "ecp.hh"

template<typename rtn_t, typename rsc_t>
class raii_c
{
	rtn_t rtn;
	rsc_t rsc;
	public:
		raii_c();
		~raii_c();
};

//example:

//template<typename rtn_t>
//class raii_c<rtn_t, std::thread>
//{
//	rtn_t rtn;
//	std::thread thread;
//	public:
//		raii_c(rtn_t rtn) : rtn{rtn}
//		{
//			this->thread = std::thread{&rtn_t::routine, &this->rtn};
//		}
//		~raii_c()
//		{
//			if(this->thread.joinable()) {this->thread.join();}
//		}
//};

//class example_c
//{
//	friend raii_c<example_c, std::thread>;
//	const std::string name = "example_c";
//	ignore_t routine() {}
//};

//std::shared_ptr<raii_c<example_c, std::thread>> thread_v[] =
//	{
//		std::make_shared<raii_c<example_c, std::thread>>(example_c{});
//	}

#endif
