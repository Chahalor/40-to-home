#include <cstdlib>

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	all::logs("ScalarConverter constructor called");
}

ScalarConverter::ScalarConverter(
	const ScalarConverter &_other
)
{
	(void)_other;
	all::logs("ScalarConverter copy constructor called");
}

ScalarConverter::~ScalarConverter(void)
{
	all::logs("ScalarConverter destructor called");
}

ScalarConverter &ScalarConverter::operator=(
	const ScalarConverter &_other
)
{
	(void)_other;
	return (*this);
}

void	ScalarConverter::convert(
	const std::string &_input
)
{
	out(std::fixed);

	try
	{
		char			*_end;
		double			d = std::strtod(_input.c_str(), &_end);

		if (_input.length() == 1)
			d = _input.c_str()[0];
		else if (*_end != '\0' && (*_end != 'f' || (*(_end + 1)) != 0))
			throw std::exception();

		const char		c = static_cast<char>(d);
		const int		i = static_cast<int>(d);
		const float		f = static_cast<float>(d);

		if (std::isprint(c))
		{
			if (std::isalnum(c))
				outl("char:	" << c)
			else
				outl("char:	Non displayable")
		}
		else
			outl("char:	Impossible")
		outl("int:	" << i);
		outl("float:	" << f << "f");
		outl("double:	" << d << "f");
	}
	catch(const std::exception& e)
	{
		outl("char:	" RED "Impossible" RESET)
		outl("int:	" RED "Impossible" RESET)
		outl("float:	" RED "Impossible" RESET)
		outl("double:	" RED "Impossible" RESET)
	}
}
