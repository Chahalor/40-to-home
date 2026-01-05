#include "Array.hpp"

template<typename T>
Array<T>::Array()
	:	_array(NULL),
		_size(0)
{

}

template<typename T>
Array<T>::Array(
	const unsigned int _size
)
	:	_array(new T[_size]()),
		_size(_size)
{

}

template<typename T>
Array<T>::Array(
	const Array &_other
)
	:	_array(new T[_other._size]()),
		_size(_other._size)
{
	unsigned int	_i;

	_i = 0;
	while (_i < _other._size)
	{
		this->_array[_i] = _other._array[_i];
		_i++;
	}
}

template<typename T>
Array<T>::~Array()
{
	if (likely(this->_array))
		delete[] this->_array;
}

template<typename T>
unsigned int	Array<T>::size(void) const
{
	return (this->_size);
}

template<typename T>
Array<T>	&Array<T>::operator=(
	const Array &_other
)
{
	if (unlikely(this == &_other))
		return (*this);

	T				*_new = new T[_other._size]();
	unsigned int	_i;

	_i = 0;
	while (_i < _other._size)
	{
		_new[_i] = _other._array[_i];
		_i++;
	}

	delete[] this->_array;
	this->_array = _new;
	this->_size = _other._size;
	return (*this);
}

template<typename T>
const char	*Array<T>::OutOfBoundExeption::what() const throw()
{
	return (RED "Index Out Of Bound" RESET);
}

template<typename T>
std::ostream	&operator<<(
	std::ostream &os,
	const Array<T> &_target
)
{
	const unsigned int	_size = _target.size();
	unsigned int		_i;

	os << "(" <<_target.size() << ")[";
	_i = 0;
	while (_i < _size - 1)
	{
		os << _target._array[_i] << ", ";
		_i++;
	}
	if (likely(_target->_size))
		os << _target._array[_i] << "]";
	else
		os << "]";

	return (os);
}

template<typename T>
T	&Array<T>::operator[](
	const unsigned int _index
)
{
	if (unlikely(!this->_size || _index >= this->_size))
		throw Array::OutOfBoundExeption();
	else
		return (this->_array[_index]);
}

template<typename T>
const T	&Array<T>::operator[](
	const unsigned int _index
) const
{
	if (unlikely(!this->_size || _index >= this->_size))
		throw Array::OutOfBoundExeption();
	else
		return (this->_array[_index]);
}
