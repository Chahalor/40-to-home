#include "libft.h"

int main(void)
{
	char *str = "Hello, World!";
	char *result = ft_strchr(str, 'W');
	
	if (result != NULL)
	{
		ft_printf("Found: %s\n", result);
	}
	else
	{
		ft_printf("Character not found.\n");
	}

	ft_printf("%s", get_next_line(0));
	
	return 0;
}