/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:18:50 by oel-hadr          #+#    #+#             */
/*   Updated: 2024/10/25 13:38:24 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*map(t_list *newlst, t_list *current,
void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	char	*content;

	while (current != NULL)
	{
		content = (*f)(current->content);
		if (!content)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		new_node = ft_lstnew(content);
		if (!new_node)
		{
			del(content);
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, new_node);
		current = current->next;
	}
	return (newlst);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*current;

	if (!lst || !f || !del)
		return (NULL);
	newlst = NULL;
	current = lst;
	return (map(newlst, current, f, del));
}
