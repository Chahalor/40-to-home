#include "Form.hpp"

Form::Form(
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
		throw Form::GradeTooLowException();
	else if (unlikely(_signGrade < 1 || _execGrade < 1))
		throw Form::GradeTooHighException();
	else
		all::logs("Form constructor called");
}

Form::Form(
	const Form &_other
)
	:	_name(_other._name),
		_signGrade(_other._signGrade),
		_execGrade(_other._execGrade),
		_signed(_other._signed)
{
	if (unlikely(_other._signGrade > 150 || _other._execGrade > 150))
		throw Form::GradeTooLowException();
	else if (unlikely(_other._signGrade < 1 || _other._execGrade < 1))
		throw Form::GradeTooHighException();
	else
		all::logs("Form copy constructor called");
}

Form::~Form(void)
{
	all::logs("Form destructor called");
}

const std::string	&Form::getName(void) const
{
	return (this->_name);
}

int	Form::getSignGrade(void) const
{
	return (this->_signGrade);
}

int	Form::getExecGrade(void) const
{
	return (this->_execGrade);
}

bool	Form::isSigned(void) const
{
	return (this->_signed);
}

void	Form::beSigned(
	const Bureaucrat &_executor
)
{
	if (unlikely(_executor.getGrade() > this->_signGrade))
	{
		outl(_executor.getName() << " couldn’t sign " << this->_name << " because hes garde is to low.");
		throw Form::GradeTooLowException();
	}
	else
	{
		this->_signed = true;
		outl(_executor.getName() << " signed " << this->_name);
	}
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Grade to high");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Grade to low");
}

std::ostream	&operator<<(
	std::ostream &os,
	const Form &_target
)
{
	os << "form " << _target.getName() << ": " << (_target.isSigned() ? "✅" : "🟥") << "\n";
	return (os);
}
