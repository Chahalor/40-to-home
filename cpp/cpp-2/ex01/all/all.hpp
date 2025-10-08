#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

#define unlikely(_expr)	__builtin_expect(!!(_expr), 0)
#define likely(_expr)	__builtin_expect(!!(_expr), 1)

#define outl(_expr) {std::cout << _expr << std::endl;}
#define out(_expr) {std::cout << _expr;}

// colors

# define BLACK			"\033[30m"
# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define BLUE			"\033[34m"
# define MAGENTA		"\033[35m"
# define CYAN			"\033[36m"
# define WHITE			"\033[37m"

// formatting

# define RESET			"\033[0m"
# define BOLD			"\033[1m"
# define FAINT			"\033[2m"
# define ITALIC			"\033[3m"
# define UNDERLINE		"\033[4m"
# define BLINK			"\033[5m"
# define REVERSE		"\033[6m"
# define REVERSED		"\033[7m"
# define HIDDEN			"\033[8m"
# define STRIKETHROUGH	"\033[9m"

// background colors
//...

// cmd management

# define FULL_CLEAN		"\033[H\033[2J\033[3J"
# define CLEAR_SCREEN	"\033[2J\033[1;1H"
# define CURSOR_UP		"\033[1A"
# define CURSOR_DOWN	"\033[1B"
# define CURSOR_LEFT	"\033[1D"
# define CURSOR_RIGHT	"\033[1C"
# define CURSOR_HOME	"\033[H"

namespace all
{
	size_t		len(const std::string &s);
	std::string	trunc(const std::string &s, size_t max_chars);
	std::string	pad(const std::string &s, size_t width);
	bool		readline(const std::string prompt, std::string *const input);
	bool		readAscii(const std::string prompt, std::string *const input);
	int			atoi(const char *);
	int			atoi(const std::string);
}
