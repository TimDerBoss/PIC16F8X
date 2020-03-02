#pragma once

#include <sstream>
#include <fstream>
#include <iostream>
#include <type_traits>
#include <exception>

class fmt
{
public:
	template<typename T>
	struct StringConverter {
		static T convert(T value) {
			return value;
		}
	};

	template<>
	struct StringConverter<std::string> {
		static const char* convert(const std::string& value) {
			return value.c_str();
		}
	};

	template<typename ... Args>
	static std::string fmtImpl(const std::string& format, Args ... args) {
		// Calculate buffer size
		int size = snprintf(nullptr, 0, format.c_str(), args...) + 1;

		// Error checking
		if (size == 0) {
			throw std::runtime_error(std::string("Invalid format string: ") + "\"" + format + "\"");
		}

		// Allocate buffer
		std::unique_ptr<char[]> buf(new char[size]);
		// Create formatted string
		snprintf(buf.get(), size, format.c_str(), args...);

		return std::string(buf.get(), buf.get() + size - 1); // We don't want the '\0' inside
	}

	template<typename ... Args>
	static std::string format(const std::string& format, Args ... args)
	{
		return fmtImpl(format, StringConverter<Args>::convert(args)...);
	}

};