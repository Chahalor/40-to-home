#ifndef TEST_H
# define TEST_H

#pragma once

#pragma pack(push, 1)

typedef struct s_str
{
	char	*str;
	int		len;
	int		is_alloc	: 1;
	t_str	(*strdup)(const char *str);
	
}	t_str;

#pragma pack(pop)

#endif