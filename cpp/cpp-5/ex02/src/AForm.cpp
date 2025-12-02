#include "AForm.hpp"

AForm::AForm(
	const std::string &_name,
	const int _signGrade,
	const int _execGrade
)
	:	_name(_name),
		_signGrade(_signGrade),
		_execGrade(_execGrade),
		_signed(false)
{
	if (unlikely(_signGrade > 150 || _execGrade > 150))
		throw AForm::GradeTooLowException();
	else if (unlikely(_signGrade < 1 || _execGrade < 1))
		throw AForm::GradeTooHighException();
	else
		all::logs("AForm constructor called");
}

AForm::AForm(
	const AForm &_other
)
	:	_name(_other._name),
		_signGrade(_other._signGrade),
		_execGrade(_other._execGrade),
		_signed(_other._signed)
{
	if (unlikely(_other._signGrade > 150 || _other._execGrade > 150))
		throw AForm::GradeTooLowException();
	else if (unlikely(_other._signGrade < 1 || _other._execGrade < 1))
		throw AForm::GradeTooHighException();
	else
		all::logs("AForm copy constructor called");
}

AForm::~AForm(void)
{
	all::logs("AForm destructor called");
}

const std::string	&AForm::getName(void) const
{
	return (this->_name);
}

void	AForm::beSigned(
	const Bureaucrat &_executor
)
{
	if (unlikely(_executor.getGrade() > this->_signGrade))
	{
		outl(_executor.getName() << " couldn’t sign " << this->_name << " because hes garde is to low.");
		throw AForm::GradeTooLowException();
	}
	else
	{
		this->_signed = true;
		outl(_executor.getName() << " signed " << this->_name);
	}
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Grade to high");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Grade to low");
}

std::ostream	&operator<<(
	std::ostream &os,
	const AForm &_target
)
{
	os << "form " << _target.getName() << "\n";
	return (os);
}
