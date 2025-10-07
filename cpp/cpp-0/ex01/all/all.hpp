#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>


#define unlikely(_expr)	__builtin_expect(!!(_expr), 0)
#define likely(_expr)	__builtin_expect(!!(_expr), 1)

#define outl(_expr) {std::cout << _expr << std::endl;}
#define out(_expr) {std::cout << _expr;}

namespace all
{
	size_t		len(const std::string &s);
	std::string	trunc(const std::string &s, size_t max_chars);
	std::string	pad(const std::string &s, size_t width);
	bool		readline(const std::string prompt, std::string *const input);
	bool		readAscii(const std::string prompt, std::string *const input);
}
