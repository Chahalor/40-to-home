#include <iostream>

#define out(_expr) {std::cout << _expr << std::endl;}

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	out("string address: " << &str);
	out("stringPTR address: " << stringPTR);
	out("stringREF address: " << &stringREF);

	out("==================================");

	out("string variable value: " << str);
	out("ptr pointed value: " << *stringPTR);
	out("ref pointed value: " << str);

	return (0);
}