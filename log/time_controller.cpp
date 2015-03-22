#include "time_controller.h"

time_controller::time_controller()
{
}

std::string time_controller::get_current_time()
{
	struct timespec spec;
	std::stringstream miliseconds;

	clock_gettime(CLOCK_REALTIME, &spec);
	miliseconds << round(spec.tv_nsec / 1.0e3);

	return convert_time_to_string(miliseconds.str(), asctime(localtime(&spec.tv_sec)));
}

std::string time_controller::convert_time_to_string(std::string miliseconds, std::string string_time)
{
	std::string ms_str = ":" + miliseconds;
	size_t position_before_year = 5;
	string_time.pop_back();
	string_time.insert(string_time.size()-position_before_year, ms_str);
	string_time.push_back('\t');
	return string_time;
}
