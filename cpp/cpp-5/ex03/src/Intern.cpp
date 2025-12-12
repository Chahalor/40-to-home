#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void)
{
	all::logs("Intern default constructor called");
}

Intern::Intern(
	const Intern &_other
)
{
	(void)_other;
	all::logs("Intern copy constructor called");
}

Intern::~Intern(void)
{
	all::logs("Intern default destructor called");
}

Intern	&Intern::operator=(
	const Intern &_other
)
{
	(void)_other;
	return (*this);
}

static AForm	*newTree(
	const std::string &_target
)
{
	return (new ShrubberyCreationForm(_target));
}

static AForm	*newRobot(
	const std::string &_target
)
{
	return (new RobotomyRequestForm(_target));
}

static AForm	*newPardon(
	const std::string &_target
)
{
	return (new PresidentialPardonForm(_target));
}

AForm	*Intern::makeForm(
	const std::string &_name,
	const std::string &_target
)
{

	static const t_form	_avalableForm[3] = {
		{"ShrubberyCreationForm", newTree},
		{"RobotomyRequestForm", newRobot},
		{"PresidentialPardonForm", newPardon}
	};
	int							_i = 0;

	while (_i < 3)
	{
		if (_name == _avalableForm[_i].name)
		{
			outl("Intern create form " << _name);
			return (_avalableForm[_i].func(_target));
		}
		_i++;
	}
	throw Intern::FormNotFound();
}

const char	*Intern::FormNotFound::what() const throw()
{
	return ("This form is unknow to the battailon");
};

std::ostream	&operator<<(
	std::ostream &os,
	const Intern &_target
)
{
	(void)_target;
	os << "a intern\n";
	return (os);
}
