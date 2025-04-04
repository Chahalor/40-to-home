/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 08:40:42 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/02 08:53:13 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# pragma once

# pragma region "Includes"
/* Systeme */
# include <stdlib.h>

/* Global */
	//...

/* Modules */
	//...

# pragma endregion	/* Includes */
# pragma region "Macros"
//...

# pragma endregion	/* Macros */
# pragma region "Typedefs"

typedef struct s_list	t_list;

# pragma endregion	/* Typedefs */
# pragma region "Enums"
//...

# pragma endregion	/* Enums */
# pragma region "Structs"

struct s_list
{
	void	*content;
	t_list	*next;
};

# pragma endregion	/* Structs */
# pragma region "Prototypes"
/* Extern */
	//...

/* Global */
	// list_info.c

t_list	*ft_lstlast(const t_list *const lst);
int		ft_lstsize(const t_list *const lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));

	// list_manage.c

t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new_node);
void	ft_lstadd_front(t_list **lst, t_list *new_node);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));

/* Static */
	//...

# pragma endregion	/* Prototypes */

#endif	/* LIST_H */