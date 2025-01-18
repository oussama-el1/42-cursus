/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:46:17 by oel-hadr          #+#    #+#             */
/*   Updated: 2025/01/17 06:42:27 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*freed;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current != NULL)
	{
		freed = current;
		current = current->next;
		ft_lstdelone(freed, del);
	}
	*lst = NULL;
}
