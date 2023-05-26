#ifndef __ECP_CC_INCLUDE_UNIQ__
#define __ECP_CC_INCLUDE_UNIQ__

#include "ecp.hh"

#include <exception>
#include <iostream>
#include <string>
#include <vector>

#define __abort__ ;fprintf(stderr, "[ABORT]\n");fflush(stdout);abort();

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
