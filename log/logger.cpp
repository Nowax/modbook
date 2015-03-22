#include "log/logger.h"
#include <iostream>
#include "log_consts.h"
#include <fstream>
#include <mutex>

basic_logger::basic_logger(std::string name) :
	my_name(name),
	time_controller_handler(time_controller_h(new time_controller()))
{
}

void basic_logger::log_info(std::string msg)
{
#ifdef DEBUG_1
	print(msg, consts::info_detail);
#else
	msg.clear();
#endif
}

void basic_logger::log_debug(std::string msg)
{
#ifdef DEBUG_2
	print(msg, consts::debug_detail);
#else
	msg.clear();
#endif
}

void basic_logger::log_warning(std::string msg)
{
	print(msg, consts::warning_detail);
}

void basic_logger::log_error(std::string msg)
{
	print(msg, consts::error_detail);
}

void basic_logger::print(std::string msg, std::string log_type)
{
	std::string log_msg = time_controller_handler->get_current_time()
			+ log_type + std::string("\t")
			+ my_name + std::string(": ")
			+ msg + std::string("\n");

	std::cout << log_msg;
	save_log(log_msg);
}

void basic_logger::save_log(std::string log_msg)
{
	std::mutex mtx;

	mtx.lock();
	std::ofstream log_file(	consts::log_name, std::ios_base::out | std::ios_base::app);
	log_file << log_msg;
}

