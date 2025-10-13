#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	bob("bob");
	ClapTrap	michel("michel");

	bob.setDamage(10);

	bob.attack("michel");
	michel.takeDamage(10);
	bob.attack("michel");
	michel.takeDamage(10);

	ScavTrap	guard("guard");

	while (guard.canGuard())
	{
		bob.attack("guard");
		guard.takeDamage(10);
	}

	return (0);
}
