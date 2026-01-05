#pragma once

template<typename T>
void	swap(
	T *_val1,
	T *_val2
)
{
	T	_dummy;

	_dummy = *_val1;
	*_val1 = *_val2;
	*_val2 = _dummy;
}

template<typename T>
T	min(
	const T _val1,
	const T _val2
)
{
	return (
		_val1 >= _val2 ?
			_val2 :
			_val1
	);
}

template<typename T>
T	max(
	const T _val1,
	const T _val2
)
{
	return (
		_val1 <= _val2 ?
			_val2 :
			_val1
	);
}