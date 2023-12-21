#ifndef __STRING_CC_INCLUDE_UNIQ__
#define __STRING_CC_INCLUDE_UNIQ__

#include "string.hh"

#include <string>

#define cstr(out) str(out).c_str()
#define vstr(out) vvstr(str(#out "/").append(str(out)))

inline std::string
vvstr(std::string out , std::string del=" ")
{
	return out.append(del);
}

template<typename type_t> inline std::string
_str(const type_t raw)
{
	return std::to_string(raw);
}

template<> inline std::string
str(const char_t * const raw)
{
	return std::string{raw};
}

template<> inline std::string
str(const std::string raw)
{
	return raw;
}

#endif
