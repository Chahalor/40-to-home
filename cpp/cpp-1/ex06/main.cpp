#include "Harl.hpp"
#include "all.hpp"

static inline int	strToLevel(
	std::string input
)
{
	static const	char	*levels[4] = {
		"DEBUG", "INFO", "WARNING", "ERROR"
	};
	register int			i = 0;

	while (i < 4)
		if (!input.compare(levels[i++]))
			return (i - 1);
	return (-1);
}

int	main(int argc, const char *argv[])
{
	std::string	filter;
	int			level;
	Harl		client = Harl();

	if (argc > 1)
		filter = std::string(argv[1]);
	else
	{
		std::cerr << "pls only specify one and only one filter level\n";
		return (1);
	}
	level = strToLevel(filter);
	if (level > 0)
		outl("[ " << filter << " ]");
	client.complain(level);
	return (0);
}
