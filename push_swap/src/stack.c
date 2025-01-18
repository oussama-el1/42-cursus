/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:50:03 by oel-hadr          #+#    #+#             */
/*   Updated: 2024/12/25 10:59:53 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*create_node(int data)
{
	t_stack	*node;

	node = (t_stack *) malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->data = data;
	node->index = 0;
	node->next = NULL;
	return (node);
}

int	isempty(t_stack *root)
{
	return (!root);
}

void	push(t_stack **root, int data)
{
	t_stack	*newnode;

	newnode = create_node(data);
	if (!newnode)
		return ;
	newnode->next = *root;
	*root = newnode;
}

int	pop(t_stack **root)
{
	t_stack	*to_free;
	int		data;

	if (isempty(*root))
		return (INT_MIN);
	to_free = *root;
	data = (*root)->data;
	*root = (*root)->next;
	free(to_free);
	return (data);
}
