#include "Zombie.hpp"

Zombie	*newZombie(
	std::string _name
)
{
	return (new Zombie(_name));
}
