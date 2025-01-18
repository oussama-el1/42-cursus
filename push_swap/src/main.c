/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 09:47:43 by oel-hadr          #+#    #+#             */
/*   Updated: 2025/01/06 23:07:44 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_stack(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
	else
		pivot_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	stack_a = parse_arguments(argc, argv);
	size = stack_size(stack_a);
	if (size == 0)
		return (0);
	else if (size == 1)
	{
		free_stack(stack_a);
		return (0);
	}
	set_indexs(stack_a);
	if (!checksorted(&stack_a))
		sort_stack(&stack_a, &stack_b, size);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
