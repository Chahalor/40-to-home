#include "RPN.hpp"

static inline void	addNumber(
	std::string::const_iterator	&_it,
	std::string::const_iterator	&_end,
	std::stack<int> &_stack
)
{
	if (unlikely(std::isdigit(*_it) && std::isdigit(*(_it + 1))))
		throw RPN::InvalidNumberExeption(std::string(_it, _end));
	else if (unlikely(!std::isdigit(*_it) || *(_it + 1) != ' '))
		throw RPN::InvalidCharExeption(*_it);

	_stack.push(std::atoi(_it.base()));
	do {_it++;} while (std::isspace(*_it));
}

static inline void	doOperation(
	std::string::const_iterator	&_it,
	std::stack<int> &_stack
)
{
	int	_op1;
	int	_op2;
	int	_result;

	if (_stack.size() < 2)
		throw RPN::InvalidNumberExeption();

	switch (*_it)
	{
		case ('/'):
			_op1 = _stack.top();
			_stack.pop();
			_op2 = _stack.top();
			_result = _op2 / _op1;
			_stack.pop();
			break ;

		case ('*'):
			_op1 = _stack.top();
			_stack.pop();
			_op2 = _stack.top();
			_result = _op2 * _op1;
			_stack.pop();
			break ;

		case ('+'):
			_op1 = _stack.top();
			_stack.pop();
			_op2 = _stack.top();
			_result = _op2 + _op1;
			_stack.pop();
			break ;

		case ('-'):
			_op1 = _stack.top();
			_stack.pop();
			_op2 = _stack.top();
			_result = _op2 - _op1;
			_stack.pop();
			break ;

		default:
			throw RPN::InvalidOperatorExeption(*_it);
	}
	_stack.push(_result);
	do {_it++;} while (std::isspace(*_it));
}

int	RPN::evaluate(
	const std::string &_expr
)
{
	std::stack<int>				_stack;
	std::string::const_iterator	_it;
	std::string::const_iterator	_end;

	_end = _expr.end();
	_it = _expr.begin();
	addNumber(_it, _end, _stack);
	while (_it != _end && *_it)
	{
		if (std::isdigit(*_it))
			addNumber(_it, _end, _stack);
		else
			doOperation(_it, _stack);
	}
	return (_stack.top());
}

#pragma region Exeptions

RPN::InvalidCharExeption::InvalidCharExeption(void)
	:	_msg("invalid char found")
{}

RPN::InvalidCharExeption::InvalidCharExeption(const char _c)
	:	_msg("invalid char found (")
{
	this->_msg += _c;
	this->_msg += ")";
}

const char	*RPN::InvalidCharExeption::what(void) const throw()
{
	return (this->_msg.c_str());
}

RPN::InvalidOperatorExeption::InvalidOperatorExeption(void)
	:	_msg("Invalid operator found")
{}

RPN::InvalidOperatorExeption::InvalidOperatorExeption(
	const char _c
)
	:	_msg("Invalid operator found (")
{
	_msg += _c;
	_msg += ")";
}

const char	*RPN::InvalidOperatorExeption::what(void) const throw()
{
	return (this->_msg.c_str());
}

RPN::InvalidNumberExeption::InvalidNumberExeption(void)
	: _msg("invalid number recorded")
{}

RPN::InvalidNumberExeption::InvalidNumberExeption(
	const std::string &_s
)
	: _msg("invalid number recorded: '")
{
	std::string::size_type pos = _s.find(' ');

	if (pos == std::string::npos)
		_msg += _s;
	else
		_msg += _s.substr(0, pos);

	_msg += "'";
}

const char	*RPN::InvalidNumberExeption::what(void) const throw()
{
	return (this->_msg.c_str());
}


#pragma endregion