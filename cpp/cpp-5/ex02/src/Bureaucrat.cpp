#include "Bureaucrat.hpp"

#pragma region Constructors

Bureaucrat::Bureaucrat(const std::string &_name, const int _grade)
	:	_name(_name),
		_grade(_grade)
{
	all::logs("Bureaucrrat constructor called for '" + _name + "' with grade " + all::itoa(_grade));
}

Bureaucrat::Bureaucrat(
	const Bureaucrat &_other
)
	:	_name(_other._name),
		_grade(_other._grade)
		
{
	all::logs("Bureaucrrat constructor called for '" + _other._name + "' with grade " + all::itoa(_other._grade));
}

#pragma region Destructor

Bureaucrat::~Bureaucrat()
{
	all::logs("Bureaucrrat destroctor called for '" + this->_name + "' with grade " + all::itoa(this->_grade));
}
#pragma region Getter

const std::string	&Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

#pragma region Setter

void	Bureaucrat::incrementGrade(
	const int _value
)
{
	if (unlikely(this->_grade - _value < 1))
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade -= _value;
}

void	Bureaucrat::decrementGrade(
	const int _value
)
{
	if (unlikely(this->_grade + _value > 150))
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade += _value;
}

#pragma region Operators

Bureaucrat &Bureaucrat::operator=(
	const Bureaucrat &_other
)
{
	this->_grade = _other._grade;
	return (*this);
}

void	Bureaucrat::signForm(
	Form &_target
)
{
	return (_target.beSigned(*this));
}

#pragma region Exeptions

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat garde to high, max 1");
};

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat garde to low, min 150");
};

std::ostream	&operator<<(
	std::ostream &os,
	const Bureaucrat &_target
)
{
	os << _target.getName() << ", bureaucrat grade " << _target.getGrade();
	return (os);
}
