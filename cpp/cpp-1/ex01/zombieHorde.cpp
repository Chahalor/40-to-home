#include "Zombie.hpp"
#include "all.hpp"

Zombie	*zombieHorde(
	int N,
	std::string name
)
{
	register int	_i = 0;

	if (unlikely(N < 1))
		return (NULL);

	Zombie	*horde = new Zombie [N];

	while (_i < N)
		horde[_i++] = Zombie(name);
	return (horde);
}
