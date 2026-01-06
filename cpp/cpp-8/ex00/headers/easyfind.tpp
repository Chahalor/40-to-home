#include "easyfind.hpp"

template<typename T>
int	easyfind(
	const T &_container,
	const int _target
)
{
	if (std::find(_container.begin(), _container.end(), _target) == _container.end())
		throw NotFoundExeption();
	else
		return (_target);
}
