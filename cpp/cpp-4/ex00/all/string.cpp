#include <stddef.h>
#include "all.hpp"

size_t	all::len(
	const std::string &s
)
{
	register int	i = 0;
	size_t			len = 0;

	while (i < (int)s.size())
	{
		if ((s[i] & 0xC0) != 0x80) 
			len++;
		i++;
	}
	return (len);
}

std::string	all::trunc(
	const std::string &s,
	size_t max_chars
)
{
	if (s.length() <= max_chars)
		return (s + std::string(max_chars - all::len(s), ' '));
	else
		return (s.substr(0, max_chars - 1) + ".");
}

std::string	all::pad(
	const std::string &s,
	size_t width
)
{
	size_t	visible = all::len(s);

	if (visible >= width)
		return (all::trunc(s, width));
	return (s + std::string(width - visible, ' '));
}

bool	all::readline(
	const std::string prompt,
	std::string *const input
)
{
	out(prompt);
	std::getline(std::cin, *input);

	if (std::cin.eof())
		return (true);
	else
		return (false);
}

bool	all::readAscii(
	const std::string prompt,
	std::string *const input
)
{
	if (all::readline(prompt, input))
		return (true);
	for (size_t i = 0; i < input->length(); i++)
	{
		if (unlikely((*input)[i] < 32 || (*input)[i] > 126))
		{
			outl("invalid character detected");
			return (all::readAscii(prompt, input));
		}
	}
	return (false);
}
