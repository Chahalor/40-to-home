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
	try
	{
		const double	d = std::stod(_input);
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
		outl("char:	Impossible")
		outl("int:	Impossible")
		outl("float:	Impossible")
		outl("double:	Impossible")
	}
}
