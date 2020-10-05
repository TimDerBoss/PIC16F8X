#pragma once

#include <string>
#include <FormatString.h>

#define fatal_exception(msg, ...) std::runtime_error(fmt::format(std::string("Error in %s, Line %d:\n\n") + msg, __FUNCTION__, __LINE__, ##__VA_ARGS__))
