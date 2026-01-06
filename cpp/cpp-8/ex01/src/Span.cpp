#include "Span.hpp"

Span::Span(
	const unsigned int &_capacity
)
	:	_storage(),
		_capacity(_capacity),
		_idx(0)
{
	this->_storage.reserve(_capacity);
}

Span::Span(
	const Span &_other
)
	:	_storage(_other._storage),
		_capacity(_other._capacity),
		_idx(_other._idx)
{

}

Span::~Span()
{

}

const std::vector<int>	&Span::getStorage(void) const
{
	return (this->_storage);
}

const unsigned int		&Span::getCapacity(void) const
{
	return (this->_capacity);
}

const unsigned int		&Span::getIdx(void) const
{
	return (this->_idx);
}

void	Span::addNumber(
	const int &_nbr
)
{
	if (unlikely(this->_idx >= this->_capacity))
		throw Span::SpanFullExeption();

	this->_storage.push_back(_nbr);
	this->_idx++;
}

void	Span::addRange(
	const int &_val1,
	const int &_val2
)
{
	const int		_min = std::min(_val1, _val2);
	const int		_max = std::max(_val1, _val2);
	int				_i;
	const long long	_needed = static_cast<long long>(_max) - _min + 1;
	const long long	_free = static_cast<long long>(this->_capacity) - this->_idx;

	if (unlikely(_needed > _free))
		throw Span::SpanFullExeption();

	_i = _min;
	while (_i <= _max)
		this->addNumber(_i++);
}

void	Span::fillRandom(
	const int &_nb_values
)
{
	int	_i;

	if (unlikely(_nb_values + this->_idx > this->_capacity))
		throw Span::SpanFullExeption();

	_i = 0;
	while (_i < _nb_values)
	{
		this->addNumber(all::randint(0, this->_capacity));
		_i++;
	}
}

Span	&Span::operator=(
	const Span &_other
)
{
	if (unlikely(this == &_other))
		return (*this);

	std::vector<int>	_new = _other._storage;

	this->_capacity = _other._capacity;
	this->_idx = _other._idx;
	this->_storage = _new;
	return (*this);
}

int	Span::shortestSpan(void) const
{
	int					result;
	size_t				_i;
	std::vector<int>	sorted;

	if (unlikely(!this->_capacity))
		throw Span::EmptySpanExeption();
	else if (unlikely(this->_idx < 2))
		throw Span::NotEnoughDataExeption();

	sorted = this->_storage;
	std::sort(sorted.begin(), sorted.end());

	result = std::abs(sorted[1] - sorted[0]);
	_i = 2;
	while (_i < sorted.size())
	{
		int	_dummy = std::abs(sorted[_i] - sorted[_i - 1]);

		if (_dummy < result)
			result = _dummy;
		_i++;
	}
	return (result);
}

int	Span::longestSpan(void) const
{
	std::vector<int>	sorted;

	if (unlikely(!this->_capacity))
		throw Span::EmptySpanExeption();
	else if (unlikely(this->_idx < 2))
		throw Span::NotEnoughDataExeption();

	sorted = this->_storage;
	std::sort(sorted.begin(), sorted.end());

	return (sorted.back() - sorted.front());
}


const char	*Span::EmptySpanExeption::what() const throw()
{
	return ("Empty span");
}

const char	*Span::NotEnoughDataExeption::what() const throw()
{
	return ("Not Enough Data to get a Span");
}

const char	*Span::NoSpanFoundExeption::what() const throw()
{
	return ("No Span here");
}

const char	*Span::SpanFullExeption::what() const throw()
{
	return ("Not more place in the Span");
}

std::ostream	&operator<<(
	std::ostream &os,
	const Span &_target
)
{
	const unsigned int	_max = _target.getIdx();
	unsigned int		_i;

	if (!_max)
	{
		os << "{}";
		return (os);
	}

	os << "{";
	_i = 0;
	while (_i < _max - 1)
	{
		os << _target.getStorage()[_i] << ", ";
		_i++;
	}
	os << _target.getStorage()[_i] << "}";
	return (os);
}
