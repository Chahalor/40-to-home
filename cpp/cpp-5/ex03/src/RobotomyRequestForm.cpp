#include <cstdlib>

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(
	const std::string &_target
)
	:	AForm("RobotomyRequestForm", RobotomyRequestForm::_signGrade, RobotomyRequestForm::_execGrade),
		_target(_target)
{
	all::logs("RobotomyRequestForm constructor called");
}

RobotomyRequestForm::RobotomyRequestForm(
	const RobotomyRequestForm &_other
)
	:	AForm(_other),
		_target(_other._target)
{
	all::logs("RobotomyRequestForm copy constructor called");
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	all::logs("RobotomyRequestForm destructor called");
}

void	RobotomyRequestForm::execute(
	const Bureaucrat &_executor
) const
{
	if (unlikely(_executor.getGrade() > this->_execGrade))
		throw RobotomyRequestForm::GradeTooLowException();
	else if (unlikely(!this->isSigned()))
		throw AForm::NotSigned();
	else
	{
		const int	value = std::rand();

		if (value % 2)
			outl(GREEN << this->_target << " has been succesfully robotomize." RESET)
		else
			outl(RED << this->_target << " failed the robotomization" RESET)
	}
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(
	const RobotomyRequestForm &_other
)
{
	this->_target = _other._target;
	return (*this);
}
