#ifndef TIME_CONTROLLER_H
#define TIME_CONTROLLER_H

#define _POSIX_C_SOURCE 200809L
#include <QDebug>
#include <inttypes.h>
#include <math.h>
#include <sstream>
#include <string>

class time_controller
{
public:
	time_controller();
	std::string get_current_time();
private:
	std::string convert_time_to_string(std::string miliseconds, std::string string_time);
};

#endif // TIME_CONTROLLER_H
