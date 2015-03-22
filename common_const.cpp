#include "common_consts.h"
#include <boost/assign.hpp>

namespace constants
{
    std::map<EOperation, std::string> oper_to_string_map = boost::assign::map_list_of
            (EOperation_big_letter_link, "BIG LETTER LINK")
            (EOperation_small_letter_link, "SMALL LETTER LINK");
}
