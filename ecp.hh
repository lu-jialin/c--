#ifndef __ECP_INCLUDE_UNIQ__
#define __ECP_INCLUDE_UNIQ__

#include <exception>
#include <iostream>
#include <string>
#include <vector>
//TODO:use for log:
//#include <fstream>
//#include <mutex>

#include "_.hh"
#include "uniq.hh"

#include "ecp.hh"

#define cstr(out) str(out).c_str()
#define vstr(out) vvstr(str(#out "/").append(str(out)))

inline std::string vvstr(std::string out, std::string del = " ")
{
	return out.append(del);
}

template<typename type_t> inline std::string
_str(const type_t raw)
{
	return std::to_string(raw);
}

template<> inline std::string
str(const char_t *const raw)
{
	return std::string{raw};
}

template<> inline std::string
str(const std::string raw)
{
	return raw;
}

//TODO:
//class log_c
//{
//	friend log_c &uniq_t<log_c>();
//	std::mutex mutex;
//	enumdef
//		(
//			never_e,
//			err_e,
//			ntf_e,
//			inf_e,
//			suc_e
//		)
//	(level_e);
//	std::string msg;
//	class level_c
//	{
//		public:
//			int_t level;
//			level_c() {}
//			level_c(int_t level) : level{level} {}
//			int_t operator * () {return level;}
//	};
//	struct { level_c level; } cur;
//	log_c() {}
//	public:
//		struct
//		{
//			const level_c never = never_e;
//			const level_c err = err_e;
//			const level_c ntf = ntf_e;
//			const level_c inf = inf_e;
//			const level_c suc = suc_e;
//		} level;
//		struct { level_c level = ntf_e; } output;
//		struct { level_c level = err_e; } fail;
//		std::ofstream clog;
//		std::ofstream &cerr = clog;
//		static std::string
//		err(std::string msg, std::string end = "\n")
//			__attribute__((deprecated("未实现")))
//		{
//			(ignore_t)msg; (ignore_t)end;
//			std::clog.flush();
//			return "";
//		}
//		static std::string
//		suc(std::string msg, std::string end = "\n")
//			__attribute__((deprecated("未实现")))
//		{
//			(ignore_t)msg; (ignore_t)end;
//			std::clog.flush();
//			return "";
//		}
//		static std::string
//		inf(std::string msg, std::string end = "\n")
//			__attribute__((deprecated("未实现")))
//		{
//			(ignore_t)msg; (ignore_t)end;
//			std::clog.flush();
//			return "";
//		}
//		template<typename type_t> log_c
//		&operator << (type_t msg)
//		{
//			this->msg += str(msg);
//			return *this;
//		}
//};

//template<> inline log_c
//&log_c::operator << (log_c::level_c level)
//{
//	//std::unique_lock<std::mutex> lock{this->mutex};
//	this->cur.level = level;
//	if(*this->cur.level <= *this->output.level)
//	{
//		fflush(stdout);
//		fflush(stderr);
//		std::clog << this->msg << std::endl;
//		fflush(stderr);
//	}
//	this->msg.clear();
//	if(*this->cur.level <= *this->fail.level)
//	{
//		__abort__;
//	}
//	return *this;
//}

class base_exception_c : std::bad_exception
{
	public:
		std::string msg;
		const char_t *what() const throw()
		{
			return msg.c_str();
		}
		base_exception_c
			(
				const char_t *file,
				const int_t line,
				const char_t *func
			) noexcept
		{
			msg = msg + file + ":" + str(line) + ":" + func + ":" + "[ERR]" + ":" ;
		}
};

template<typename ecp_t>
class ecp_c : public base_exception_c
{
	public:
		std::vector<const char_t*> msg_v = std::move(ecp_t{}.msg_v);
		ecp_c
			(
				const char_t *file,
				const int_t line,
				const char_t *func,
				...
			) noexcept : base_exception_c{file, line, func}
		{
			va_list_t valist;
			va_start(valist, func);
			for(auto_t &msg_r:msg_v) if(!msg_r)
			{
				msg_r = va_arg(valist, char_t*);
			}
			va_end(valist);
			for(auto_t const &msg_r:msg_v)
			{
				base_exception_c::msg += msg_r;
			}
		}
};

namespace ecp
{
	class permission_t
	{
		friend ecp_c<permission_t>;
		std::vector<const char_t*> msg_v =
		{
			"Please run this program as root"
		};
	};
}

#endif
