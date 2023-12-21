#ifndef __RAII_INCLUDE_UNIQ__
#define __RAII_INCLUDE_UNIQ__

#include "raii.hh"

#include <utility>

template<typename rsc_t> struct _raii_t {
	rsc_t rsc; //此处使用右值引用会导致指针丢失
	bool (*pred)(const rsc_t&);
	void (*dstr)(rsc_t&);
	public:
		_raii_t(rsc_t & rsc , void (*dstr)(rsc_t&) , bool (*pred)(const rsc_t&) = [](const rsc_t&)->bool{return true;}) :
			rsc{std::move(rsc)} , pred{pred} , dstr{dstr}
		{}
		_raii_t(rsc_t &&rsc , void (*dstr)(rsc_t&) , bool (*pred)(const rsc_t&) = [](const rsc_t&)->bool{return true;}) :
			rsc{std::move(rsc)} , pred{pred} , dstr{dstr}
		{}
		//_raii_t(_raii_t &_raii) : rsc{std::move(_raii.rsc)} , pred{_raii.pred} , dstr{_raii.dstr} {}
		_raii_t(_raii_t & _raii) = delete; //XXX:which better?
		_raii_t(_raii_t && _raii) :
			rsc{std::move(_raii.rsc)},
			pred{std::move(_raii.pred)},
			dstr{std::move(_raii.dstr)}
		{}
		~_raii_t() { if(pred(rsc)) dstr(rsc); }

		const rsc_t operator*() const {return rsc;}

		bool chk() {return pred(rsc);}
};

template<typename rsc_t>
struct raii_t : public _raii_t<rsc_t> {
	public:
		raii_t(rsc_t &rsc , void (*dstr)(rsc_t&) , bool (*pred)(const rsc_t&) = [](const rsc_t&)->bool{return true;}) :
			_raii_t<rsc_t>(rsc , dstr , pred)
		{}
		raii_t(rsc_t &&rsc , void (*dstr)(rsc_t&) , bool (*pred)(const rsc_t&) = [](const rsc_t&)->bool{return true;}) :
		_raii_t<rsc_t>(rsc , dstr , pred)
		{}
};

#endif

/* Use case for `raii_t<std::thread>` */
/*
#include <iostream>
#include <string>
#include <memory>
#include <thread>

template<>
struct raii_t<std::thread> : _raii_t<std::thread> {
	//can not move `_raii_t` here
	public:
		template<typename... types_t>
		raii_t(types_t... args) :
			_raii_t<std::thread>
				(
					std::thread{args...},
					[](std::thread &thread){thread.join();},
					[](const std::thread &thread)->bool{return true;}
				)
		{}
};

void
rtn(char c)
{
	//std::cout << ((std::string{"rtn:"} + c) + '\n');
	//std::cout << std::string{"rtn:"}.append(1, c).append("\n");
	std::cout << "rtn:" << c << std::endl;
}

class example_c {
	const std::string name = "example_c";
	//public: void rtn() {std::cout << (name + '\n');}
	//public: void rtn() {std::cout << name.append("\n");}
	public: void rtn() {std::cout << name << std::endl;}
};

int
main()
{
	raii_t<std::thread> thread[] =
		{
			raii_t<std::thread>{&example_c::rtn, example_c{}},
			raii_t<std::thread>{&rtn, 'R'},
			raii_t<std::thread>{&rtn, 'T'}
		}
	;
	//std::shared_ptr<raii_t<std::thread>> thread[] =
	//{
	//	std::make_shared<raii_t<std::thread>>(&example_c::rtn, example_c{}),
	//	std::make_shared<raii_t<std::thread>>(&rtn, 'r')
	//};
	std::cerr << "";
	return 0;
}
*/
