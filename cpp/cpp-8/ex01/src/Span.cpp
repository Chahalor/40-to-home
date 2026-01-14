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
	if (unlikely(_nb_values + this->_idx > this->_capacity))
		throw Span::SpanFullExeption();

	const int			_range_size = this->_capacity + (this->_capacity / 5);
	std::vector<int>	_pool;

	if (unlikely(_nb_values > _range_size))
		throw Span::SpanFullExeption();

	_pool.reserve(_range_size);

	for (int i = 0; i < _range_size; ++i)
		_pool.push_back(i);

	std::random_shuffle(_pool.begin(), _pool.end());

	for (int i = 0; i < _nb_values; ++i)
		this->addNumber(_pool[i]);
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
	int					_short_a = 0;
	int					_short_b = 0;
	int					_long_min = 0;
	int					_long_max = 0;
	bool				_has_spans = false;

	if (!_max)
	{
		os << "{}";
		return (os);
	}

	if (_max >= 2)
	{
		std::vector<int> sorted = _target.getStorage();
		std::sort(sorted.begin(), sorted.end());

		_long_min = sorted.front();
		_long_max = sorted.back();

		int	best = std::abs(sorted[1] - sorted[0]);
		_short_a = sorted[0];
		_short_b = sorted[1];

		for (size_t i = 2; i < sorted.size(); ++i)
		{
			int diff = std::abs(sorted[i] - sorted[i - 1]);
			if (diff < best)
			{
				best = diff;
				_short_a = sorted[i - 1];
				_short_b = sorted[i];
			}
		}
		_has_spans = true;
	}

	os << "{";
	for (unsigned int i = 0; i < _max; ++i)
	{
		int val = _target.getStorage()[i];

		bool is_short =
			_has_spans && (val == _short_a || val == _short_b);
		bool is_long =
			_has_spans && (val == _long_min || val == _long_max);

		if (is_short && is_long)
			os << ORANGE;
		else if (is_short)
			os << GREEN;
		else if (is_long)
			os << RED;

		os << val << RESET;

		if (i + 1 < _max)
			os << ", ";
	}
	os << "}";

	return (os);
}
