#include <cstdlib>
#include <time.h>
#include <vector>
#include <list>
#include <set>

#include "all.hpp"
#include "easyfind.hpp"

#define PART(title) do {outl(YELLOW BOLD UNDERLINE << title << RESET)} while (0);

static inline t_container_type	_get_type(
	const std::string _type_str
)
{
	std::string	_allowed[4] = {
		"vector", "deque", "list"
	};
	int	_i ;

	_i = 0;
	while (_i < 4)
	{
		if (_type_str == _allowed[_i])
			return ((t_container_type)_i);
		_i++;
	}
	return ((t_container_type)-1);
}

template<typename Container>
static inline void	_fill_container(
	Container &_container,
	const int _size
)
{
	int	_i;

	_i = 0;
	while (_i < _size)
	{
		_container.push_back(_i);
		_i++;
	}
}

template<typename Container>
static int	_test(
	const int _size,
	const int _target
)
{
	Container	_container(_size);

	_fill_container(_container, _size);

	try
	{
		easyfind(_container, _target);
		outl("found " << _target << " inside the container")
		return (0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
}

int	main(const int argc, const char *argv[])
{
	const int			_dummy = 0;
	int					_container_size = 100;
	int					_target = 1;
	t_container_type	_type = CONTAINER_TYPE_VECTOR;

	if (argc > 4)
	{
		std::cerr << "usage: " << argv[0] << " <target> <size> <algo>" << std::endl;
		return (EXIT_FAILURE);
	}
	else if (argc > 1)
	{
		_target = std::atoi(argv[1]);
		if (argc > 2)
			_container_size = std::atoi(argv[2]);
		if (argc > 3)
			_type = _get_type(argv[3]);
		
		if (_container_size <= 0)
		{
			std::cerr << "<container size> must be a valid unsigned int" << std::endl;
			return (EXIT_FAILURE);
		}
		else if (_type < 0)
		{
			std::cerr << "invalid container: " << argv[3] << "\nAllowed container: vector, deque, list" << std::endl;
			return (EXIT_FAILURE);
		}
	}

	SRAND(_dummy);

	switch (_type)
	{
		case (CONTAINER_TYPE_VECTOR):
			return (_test<std::vector<int> >(_container_size, _target));
		case (CONTAINER_TYPE_DEQUE):
			return (_test<std::deque<int> >(_container_size, _target));
		case (CONTAINER_TYPE_LIST):
			return (_test<std::list<int> >(_container_size, _target));
		default:
			return (EXIT_FAILURE);
	}
}

