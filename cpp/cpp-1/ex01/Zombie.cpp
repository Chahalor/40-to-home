#include "Zombie.hpp"

Zombie::Zombie(
	std::string name
)
{
	this->name = name;
}

Zombie::Zombie(void)
{
	this->name = "A random reanimated corpse";
}

Zombie::~Zombie()
{
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}