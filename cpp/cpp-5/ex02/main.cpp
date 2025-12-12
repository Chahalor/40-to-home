#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define PART(text) {outl(YELLOW << text << RESET)}

int	main(void)
{
	Bureaucrat	bob("bob", 1);
	Bureaucrat	michel("michel", 75);
	Bureaucrat	random_one("i have no idea was is this guy", 150);

	std::srand(std::time(NULL));

	outl(bob);
	outl(michel);
	outl(random_one);

	PresidentialPardonForm	pardon("bob");
	ShrubberyCreationForm	tree("some tree");
	RobotomyRequestForm		robot("the president");

	PART("Signing form")
	try
	{
		bob.signForm(pardon);
		michel.signForm(robot);
		random_one.signForm(tree);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}

	PART("bob executing")
	try
	{
		bob.executeForm(pardon);
		bob.executeForm(tree);
		bob.executeForm(robot);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}

	PART("Other executing")
	try
	{
		michel.executeForm(tree);
		michel.executeForm(robot);
		random_one.executeForm(pardon);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}

	bob.signForm(robot);
	int	i = 0;
	while (i++ < 100)
		bob.executeForm(robot);

	return (EXIT_SUCCESS);
}
