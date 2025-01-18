/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:11:00 by oel-hadr          #+#    #+#             */
/*   Updated: 2024/12/25 11:34:37 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_op(t_stack **root)
{
	t_stack	*next;
	int		temp;
	int		tmp_index;

	if (!root || !(*root) || !(*root)->next)
		return ;
	next = (*root)->next;
	temp = (*root)->data;
	tmp_index = (*root)->index;
	(*root)->data = next->data;
	(*root)->index = next->index;
	next->data = temp;
	next->index = tmp_index;
}

void	push_op(t_stack **stack1, t_stack **stack2)
{
	int	index;

	if (isempty(*stack1))
		return ;
	index = (*stack1)->index;
	push(stack2, pop(stack1));
	(*stack2)->index = index;
}

void	rotate_op(t_stack **root)
{
	t_stack	*first;
	t_stack	*curr;

	if (!root || !(*root) || !(*root)->next)
		return ;
	first = *root;
	*root = first->next;
	curr = *root;
	while (curr->next)
		curr = curr->next;
	curr->next = first;
	first->next = NULL;
}

void	rotate_reverse_op(t_stack **root)
{
	t_stack	*last;
	t_stack	*prev;

	if (!root || !(*root) || !(*root)->next)
		return ;
	prev = NULL;
	last = *root;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *root;
	*root = last;
}
