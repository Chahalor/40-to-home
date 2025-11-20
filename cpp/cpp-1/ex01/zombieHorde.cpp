#include "Zombie.hpp"
#include "all.hpp"

Zombie	*zombieHorde(
	int N,
	std::string _name
)
{
	register int	_i = 0;

	if (unlikely(N < 1))
		return (NULL);

	Zombie	*horde = new Zombie[N];

	while (_i < N)
		horde[_i++].setName(_name);
	return (horde);
}
