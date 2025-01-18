/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calls_op2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 09:28:08 by oel-hadr          #+#    #+#             */
/*   Updated: 2025/01/06 21:09:46 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack **stack_a, int sorting)
{
	if (sorting)
		write(1, "ra\n", 3);
	rotate_op(stack_a);
}

void	rb(t_stack **stack_b, int sorting)
{
	if (sorting)
		write(1, "rb\n", 3);
	rotate_op(stack_b);
}

void	rr(t_stack **stack_a, t_stack **stack_b, int sorting)
{
	if (sorting)
		write(1, "rr\n", 3);
	rotate_op(stack_a);
	rotate_op(stack_b);
}

void	rra(t_stack **stack_a, int sorting)
{
	if (sorting)
		write(1, "rra\n", 4);
	rotate_reverse_op(stack_a);
}

void	rrb(t_stack **stack_b, int sorting)
{
	if (sorting)
		write(1, "rrb\n", 4);
	rotate_reverse_op(stack_b);
}
