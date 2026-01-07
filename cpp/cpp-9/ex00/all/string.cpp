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

void	all::trim(
	std::string &_target
)
{
	std::size_t	_write = 0;

	for (std::size_t _read = 0; _read < _target.size(); ++_read)
	{
		if (!std::isspace(static_cast<unsigned char>(_target[_read])))
			_target[_write++] = _target[_read];
	}
	_target.resize(_write);
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

void		all::logs(
	const std::string &_str
)
{
	#ifdef DEBUG // DEBUG == 1
	outl(_str);
	#else
	(void)_str;
	#endif
}

std::string	all::gnl(
	std::ifstream& _file
)
{
	std::string line;

	if (unlikely(!_file.is_open()))
		return (std::string());
	else if (unlikely(!std::getline(_file, line)))
		return (std::string());

	return (line);
}

std::string	all::gnl(
	std::ifstream &_file,
	const char _delim
)
{
	std::string line;

	if (unlikely(!_file.is_open()))
		return (std::string());
	else if (unlikely(!std::getline(_file, line, _delim)))
		return (std::string());

	return (line);
}
