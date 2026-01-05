#pragma once

#include <stddef.h>

template<typename T>
void	iter(
	T *const _array,
	const size_t _size,
	void (*const _func)(T *const)
)
{
	size_t	_i = 0;

	while (_i < _size)
		_func(&_array[_i++]);
}