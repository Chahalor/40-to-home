#include <iostream>

#define cout(x) std::cout << x << std::endl;
#define BOLD "\033[1m"
#define RESET "\033[0m"

int	main(
	int argc,
	char **argv
)
{
	int	i;
	int	j;

	if (argc < 2)
	{
		cout(BOLD "* LOUD AND UNBEARABLE FEEDBACK NOISE *" RESET);
		return (0);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			j = 0;
			while (argv[i][j])
			{
				std::cout << (char)std::toupper(argv[i][j]);
				j++;
			}
			if (__glibc_likely(i + 1 < argc))
				std::cout << " ";
			i++;
		}
	}
	return (0);
}
