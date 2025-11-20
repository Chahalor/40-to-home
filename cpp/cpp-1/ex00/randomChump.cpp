#include "Zombie.hpp"

void	randomChump(
	std::string _name
)
{
	Zombie	zombie(_name);

	zombie.announce();
}
