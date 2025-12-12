#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

#define PART(text) {outl(YELLOW << text << RESET)}

int	main(void)
{
	Bureaucrat	bob("bob", 1);
	Bureaucrat	michel("michel", 75);
	Intern		random_one;



	std::srand(std::time(NULL));

	outl(bob);
	outl(michel);
	outl(random_one);

	AForm	*pardon = random_one.makeForm("PresidentialPardonForm", "bob");
	AForm	*tree = random_one.makeForm("ShrubberyCreationForm", "tree");
	AForm	*robot = random_one.makeForm("RobotomyRequestForm", "michel");

	try
	{
		AForm	*error = random_one.makeForm("InvalidForm", "invalid");
		(void)error;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
	


	PART("Signing form")
	try
	{
		bob.signForm(*pardon);
		michel.signForm(*robot);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}

	PART("bob executing")
	try
	{
		bob.executeForm(*pardon);
		bob.executeForm(*tree);
		bob.executeForm(*robot);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}

	PART("Other executing")
	try
	{
		michel.executeForm(*tree);
		michel.executeForm(*robot);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}

	bob.signForm(*robot);
	int	i = 0;
	while (i++ < 100)
		bob.executeForm(*robot);

	delete robot;
	delete pardon;
	delete tree;

	return (EXIT_SUCCESS);
}
