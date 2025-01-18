/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 01:05:13 by oel-hadr          #+#    #+#             */
/*   Updated: 2025/01/08 21:37:06 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_place(t_stack **stack, int index)
{
	t_stack	*curr;
	int		i;

	curr = *stack;
	i = 0;
	while (curr && curr->index != index)
	{
		curr = curr->next;
		i++;
	}
	return (i);
}

void	pivot_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	lastp1;
	int	pivot1;
	int	pivot2;

	lastp1 = -1;
	pivot1 = stack_size(*stack_a) / 3;
	pivot2 = stack_size(*stack_a) / 6;
	while (stack_size(*stack_a) > 3)
	{
		if ((*stack_a)->index < pivot1)
			pb(stack_a, stack_b, 1);
		else
			ra(stack_a, 1);
		if (stack_size(*stack_b) > 1
			&& ((*stack_b)->index >= lastp1 && (*stack_b)->index <= pivot2))
			rb(stack_b, 1);
		if (stack_size(*stack_b) == pivot1)
		{
			lastp1 = pivot1;
			pivot1 += stack_size(*stack_a) / 3;
			pivot2 = stack_size(*stack_a) / 6 + lastp1;
		}
	}
	sort_three(stack_a);
	push_back_correct_in_order(stack_a, stack_b);
}

void	getbottom(t_stack **stack_a, t_stack **bottom)
{
	*bottom = *stack_a;
	while ((*bottom)->next)
		*bottom = (*bottom)->next;
}

void	place_and_rotate_stack_b(t_stack **stack_a,
		t_stack **stack_b, int value, t_stack **bottom)
{
	if (find_place(stack_b, (*stack_a)->index - 1) > stack_size(*stack_b) / 2)
	{
		if (((*bottom)->index < (*stack_b)->index || (*bottom)->index == value))
		{
			pa(stack_a, stack_b, 1);
			ra(stack_a, 1);
			getbottom(stack_a, bottom);
		}
		else if (stack_b)
		{
			rrb(stack_b, 1);
		}
	}
	else
	{
		if ((*bottom)->index < (*stack_b)->index || (*bottom)->index == value)
		{
			pa(stack_a, stack_b, 1);
			ra(stack_a, 1);
			getbottom(stack_a, bottom);
		}
		else if (stack_b)
			rb(stack_b, 1);
	}
}

void	push_back_correct_in_order(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*bottom;
	int		value;

	getbottom(stack_a, &bottom);
	value = bottom->index;
	while (stack_b)
	{
		while ((*stack_b) && (*stack_b)->index + 1 != (*stack_a)->index)
			place_and_rotate_stack_b(stack_a, stack_b, value, &bottom);
		while (*stack_b && (*stack_b)->index == (*stack_a)->index - 1)
			pa(stack_a, stack_b, 1);
		if ((*stack_a)->index - 1 == bottom->index)
		{
			while (bottom->index == (*stack_a)->index - 1)
			{
				rra(stack_a, 1);
				getbottom(stack_a, &bottom);
			}
		}
		if (checksorted(stack_a) == 1 && *stack_b == NULL)
			break ;
	}
}
