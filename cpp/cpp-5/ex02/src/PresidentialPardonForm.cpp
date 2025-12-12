#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(
	const std::string &_target
)
	:	AForm("PresidentialPardonForm", this->_signGrade, this->_execGrade),
		_target(_target)
{
	all::logs("PresidentialPardonForm constructor called");
}

PresidentialPardonForm::PresidentialPardonForm(
	const PresidentialPardonForm &_other
)
	:	AForm(_other),
		_target(_other._target)
{
	all::logs("PresidentialPardonForm copy constructor called");
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	all::logs("PresidentialPardonForm destructor called");
}

void	PresidentialPardonForm::execute(
	const Bureaucrat &executor
) const
{
	if (unlikely(executor.getGrade() > this->_execGrade))
		throw AForm::GradeTooLowException();
	else if (unlikely(!this->isSigned()))
		throw AForm::NotSigned();
	else
		outl(this->_target << " has been pardoned by Zaphod Beeblebrox.")
}
