#include "Harl.hpp"
#include "all.hpp"

int	main(int argc, const char *argv[])
{
	std::string	level;
	Harl		client = Harl();

	if (argc > 1)
	{
		level = std::string(argv[1]);
		client.complain(level);
	}

	while (!all::readline("complaine level >> ", &level))
	{
		if (unlikely(!level.compare("LEAVING")))
		{
			outl("your just leaving harl in hes rage. Alone. Has always")
			break ;
		}
		client.complain(level);
	}
	return (0);
}
