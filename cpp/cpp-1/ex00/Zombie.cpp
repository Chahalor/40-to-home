#include "Zombie.hpp"

Zombie::Zombie(
	std::string _name
)
{
	this->_name = _name;
}

Zombie::Zombie(void)
{
	this->_name = "A random reanimated corpse";
	outl(BLUE << "Zombie constructor called" << RESET);
}

Zombie::~Zombie()
{
	outl(RED << "Zombie " << this->_name << " hazbin destroyed" << RESET);
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}