#ifndef LOGGER_H
#define LOGGER_H

#include "time_controller.h"
#include <string>
#include <fstream>
#include <ctime>
#include <QtCore/QDebug>
#include <string>
#include <memory>
#include <iomanip>

typedef std::shared_ptr<class time_controller> time_controller_h;

class basic_logger
{
public:
    basic_logger(std::string name);

	void log_info(std::string msg);
	void log_debug(std::string msg);
	void log_warning(std::string msg);
	void log_error(std::string msg);

private:
	std::string my_name;
	time_controller_h time_controller_handler;

	void print(std::string msg, std::string log_type);
	std::string create_file_name();
	void save_log(std::string log_msg);

};

#endif // LOGGER_H
