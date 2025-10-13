#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	ClapTrap	bob("bob");
	ClapTrap	michel("michel");

	bob.setDamage(10);

	bob.attack("michel");
	michel.takeDamage(10);
	bob.attack("michel");
	michel.takeDamage(10);

	out("bob found a battery and gain 10 energie")
	bob.setMana(19);

	ScavTrap	guard("guard");

	while (guard.canGuard())
	{
		bob.attack("guard");
		guard.takeDamage(10);
	}

	FragTrap	paul("paul");

	paul.highFivesGuy();
	bob.attack("paul");
	paul.takeDamage(10);
	paul.attack("bob");
	out(" - bob is parying -\n")

	DiamondTrap	AbOmInAtIoN("BOB");

	AbOmInAtIoN.whoAmI();

	AbOmInAtIoN.attack("bob");

	return (0);
}
