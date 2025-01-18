/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:09:37 by oel-hadr          #+#    #+#             */
/*   Updated: 2025/01/09 02:27:32 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../utils/get_next_line.h"

static void	execute_instruction2(char *line,
			t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strcmp(line, "rr"))
	{
		ra(stack_a, 0);
		rb(stack_b, 0);
	}
	else if (!ft_strcmp(line, "rra"))
		rra(stack_a, 0);
	else if (!ft_strcmp(line, "rrb"))
		rrb(stack_b, 0);
	else if (!ft_strcmp(line, "rrr"))
	{
		rra(stack_a, 0);
		rrb(stack_b, 0);
	}
	else
	{
		write(1, "Error\n", 6);
		free_stack(*stack_a);
		free_stack(*stack_b);
		exit(1);
	}
}

static void	execute_instruction(char *line,
			t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strcmp(line, "sa"))
		sa(stack_a, 0);
	else if (!ft_strcmp(line, "sb"))
		sb(stack_b, 0);
	else if (!ft_strcmp(line, "ss"))
		ss(stack_a, stack_b, 0);
	else if (!ft_strcmp(line, "pa"))
		pa(stack_a, stack_b, 0);
	else if (!ft_strcmp(line, "pb"))
		pb(stack_a, stack_b, 0);
	else if (!ft_strcmp(line, "ra"))
		ra(stack_a, 0);
	else if (!ft_strcmp(line, "rb"))
		rb(stack_b, 0);
	else
		execute_instruction2(line, stack_a, stack_b);
}

void	sort_with_instruction(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		line[ft_strlen(line) - 1] = '\0';
		execute_instruction(line, stack_a, stack_b);
		free(line);
		line = get_next_line(0);
	}
	set_indexs(*stack_a);
	if (checksorted(stack_a) && stack_size(*stack_b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
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
	sort_with_instruction(&stack_a, &stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
