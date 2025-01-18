/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:41:16 by oel-hadr          #+#    #+#             */
/*   Updated: 2025/01/06 21:12:38 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_indexs(t_stack *stack_a)
{
	t_stack	*curr;
	t_stack	*ptr;

	curr = stack_a;
	while (curr)
	{
		ptr = stack_a;
		while (ptr)
		{
			if (curr->data > ptr->data)
				curr->index++;
			ptr = ptr->next;
		}
		curr = curr->next;
	}
}

void	move_min_to_top(t_stack **stack)
{
	t_stack	*curr;
	int		min;
	int		pos;
	int		size;

	curr = *stack;
	min = curr->data;
	pos = 0;
	size = 0;
	while (curr)
	{
		if (curr->data < min)
		{
			min = curr->data;
			pos = size;
		}
		curr = curr->next;
		size++;
	}
	if (pos <= size / 2)
		while (pos--)
			ra(stack, 1);
	else
		while (pos++ < size)
			rra(stack, 1);
}

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

int	stack_size(t_stack *root)
{
	int	size;

	size = 0;
	while (root)
	{
		root = root->next;
		size++;
	}
	return (size);
}

int	checksorted(t_stack **stack_a)
{
	t_stack	*current;

	current = *stack_a;
	while (current && current->next)
	{
		if (current->index > current->next->index)
			return (0);
		current = current->next;
	}
	return (1);
}
