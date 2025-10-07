#include "all.hpp"
#include "Zombie.hpp"

int	main(int argc, char **argv)
{
	int				horde_size = 0;
	register int	i = 0;

	if (argc == 2)
		horde_size = all::atoi(argv[1]);
	else if (argc > 2)
	{
		std::cerr << "just passe one numbre has args" << std::endl;
		return (1);
	}
	else
	{
		std::string	_input;

		out("horde size $> ");
		std::cin >> _input;
		horde_size = all::atoi(_input);
	}

	if (unlikely(horde_size <= 0))
	{
		std::cerr << "pls choose an horde size > 0" << std::endl;
		return (1);
	}

	Zombie	*horde = zombieHorde(horde_size, "bob");

	while (i < horde_size)
	{
		horde[i].announce();
		i++;
	}
	delete[] horde;
	return (0);
}
