#include "all.hpp"

int all::atoi(const char *input)
{
	if (unlikely(!input || !*input))
		return (0);

	int	result = 0;
	int	sign = 1;
	int	i = 0;

	if (input[0] == '-')
	{
		sign = -1;
		i++;
	}

	while (input[i])
	{
		if (input[i] >= '0' && input[i] <= '9')
			result = result * 10 + (input[i] - '0');
		else
			break ;
		i++;
	}

	return (result * sign);
}

int all::atoi(const std::string input)
{
	if (unlikely(input.empty()))
		return (0);

	int		result = 0;
	int		sign = 1;
	size_t	i = 0;

	if (input[0] == '-')
	{
		sign = -1;
		i++;
	}

	while (i < input.length())
	{
		if (input[i] >= '0' && input[i] <= '9')
			result = result * 10 + (input[i] - '0');
		else
			break;
		i++;
	}

	return (result * sign);
}
