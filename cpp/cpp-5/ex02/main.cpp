#include "Bureaucrat.hpp"
#include "AForm.hpp"

int	main(void)
{
	Bureaucrat	bob("bob", 1);
	Bureaucrat	michel("michel", 75);
	Bureaucrat	random_one("i have no idea was is this guy", 150);

	outl(bob);
	outl(michel);
	outl(random_one);

	outl("\n=======\n")

	try
	{
		bob.incrementGrade(1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		random_one.decrementGrade(1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		michel.incrementGrade(12);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	outl("\n=======\n")

	outl(bob);
	outl(michel);
	outl(random_one);

	outl("\n=======\n")

	AForm	_form("some form", 150, 1);
	AForm	_form2("some other form", 1, 1);

	try
	{
		bob.signForm(_form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		random_one.signForm(_form2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	return (EXIT_SUCCESS);
}
