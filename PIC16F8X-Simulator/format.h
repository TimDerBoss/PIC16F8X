#pragma once

#include <sstream>
#include <fstream>
#include <iostream>
#include <type_traits>
#include <exception>

class fmt
{
public:
	// base case of recursion, no more arguments
	static void format_impl(std::stringstream& ss, const char* format) {
		while (*format) {
			if (*format == '%' && *++format != '%') // %% == % (not a format directive)
				throw std::invalid_argument("not enough arguments !\n");
			ss << *format++;
		}
	}

	template <typename Arg, typename... Args>
	static void format_impl(std::stringstream& ss, const char* format, Arg arg, Args... args) {
		while (*format) {
			if (*format == '%' && *++format != '%') {
				auto current_format_qualifier = *format;
				switch (current_format_qualifier) {
				case 'd': if (!std::is_integral<Arg>()) throw std::invalid_argument("%d introduces integral argument");
					// etc.
				}
				// it's true you'd have to handle many more format qualifiers, but on a safer basis
				ss << arg; // arg type is deduced
				return format_impl(ss, ++format, args...); // one arg less
			}
			ss << *format++;
		} // the format string is exhausted and we still have args : throw
		throw std::invalid_argument("Too many arguments\n");
	}

	template <typename... Args>
	static std::string format(const char* fmt, Args... args) {
		std::stringstream ss;
		format_impl(ss, fmt, args...);
		return ss.str();
	}

};