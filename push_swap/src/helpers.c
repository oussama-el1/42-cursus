/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:20:54 by oel-hadr          #+#    #+#             */
/*   Updated: 2025/01/06 23:07:51 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_two(t_stack **stack)
{
	if ((*stack)->data > (*stack)->next->data)
		sa(stack, 1);
}

void	sort_three(t_stack **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->data;
	second = (*stack)->next->data;
	third = (*stack)->next->next->data;
	if (first > second && second < third && first < third)
		sa(stack, 1);
	else if (first > second && second > third)
	{
		sa(stack, 1);
		rra(stack, 1);
	}
	else if (first > second && second < third && first > third)
		ra(stack, 1);
	else if (first < second && second > third && first < third)
	{
		sa(stack, 1);
		ra(stack, 1);
	}
	else if (first < second && second > third && first > third)
		rra(stack, 1);
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	move_min_to_top(stack_a);
	pb(stack_a, stack_b, 1);
	sort_three(stack_a);
	pa(stack_a, stack_b, 1);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	move_min_to_top(stack_a);
	pb(stack_a, stack_b, 1);
	sort_four(stack_a, stack_b);
	pa(stack_a, stack_b, 1);
}
