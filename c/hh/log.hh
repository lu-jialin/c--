#ifndef __LOG_CC_INCLUDE_UNIQ__
#define __LOG_CC_INCLUDE_UNIQ__

#include "log.hh"

//TODO:

//#include <fstream>
//#include <mutex>

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

#endif
