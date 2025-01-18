/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calls_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:37:27 by oel-hadr          #+#    #+#             */
/*   Updated: 2025/01/08 22:33:12 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stack **stack_a, int sorting)
{
	if (sorting)
		write(1, "sa\n", 3);
	swap_op(stack_a);
}

void	sb(t_stack **stack_b, int sorting)
{
	if (sorting)
		write(1, "sb\n", 3);
	swap_op(stack_b);
}

void	ss(t_stack **stack_a, t_stack **stack_b, int sorting)
{
	if (sorting)
		write(1, "ss\n", 3);
	swap_op(stack_a);
	swap_op(stack_b);
}

void	pa(t_stack **stack_a, t_stack **stack_b, int sorting)
{
	if (sorting)
		write(1, "pa\n", 3);
	push_op(stack_b, stack_a);
}

void	pb(t_stack **stack_a, t_stack **stack_b, int sorting)
{
	if (sorting)
		write(1, "pb\n", 3);
	push_op(stack_a, stack_b);
}
