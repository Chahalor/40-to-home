#include <cstdlib>
#include <cstring>
#include <limits>

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

static bool is_nan(double d)
{
	return d != d;
}

static bool is_inf(double d)
{
	return d == std::numeric_limits<double>::infinity()
		|| d == -std::numeric_limits<double>::infinity();
}


static bool is_special_literal(const std::string& s)
{
	return s == "nan" || s == "nanf"
		|| s == "+inf" || s == "-inf"
		|| s == "inf"  || s == "inff"
		|| s == "+inff" || s == "-inff";
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
		{
			if (_input.c_str()[0] >= '0' && _input.c_str()[0] <= '9')
				d = _input.c_str()[0] - '0';
			else
				d = _input.c_str()[0];
		}
		else if (*_end != '\0' && (*_end != 'f' || (*(_end + 1)) != 0))
			throw std::exception();


		if (is_nan(d))
		{
			outl("char: impossible");
			outl("int: impossible");
			outl("float: nanf");
			outl("double: nan");
			return;
		}

		if (is_inf(d))
		{
			outl("char: impossible");
			outl("int: impossible");

			if (d > 0)
			{
				outl("float: +inff");
				outl("double: +inf");
			}
			else
			{
				outl("float: -inff");
				outl("double: -inf");
			}
			return;
		}

		const char		c = static_cast<char>(d);
		const int		i = static_cast<int>(d);
		const float		f = static_cast<float>(d);

		if (std::isprint(c))
				outl("char:	" << c)
		else
			outl("char:" YELLOW "	Non displayable" RESET)
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
