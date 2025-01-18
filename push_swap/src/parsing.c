/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:41:09 by oel-hadr          #+#    #+#             */
/*   Updated: 2025/01/13 14:32:56 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_array(char **numbers)
{
	int	size;

	if (!numbers)
		return ;
	size = 0;
	while (numbers[size])
		size++;
	while (--size >= 0)
		free(numbers[size]);
	free(numbers);
}

void	print_error_and_free(t_stack *stack, char **numbers)
{
	if (numbers)
		free_array(numbers);
	print_error(stack);
}

void	parsing_helper(int argc, char **argv, t_stack **stack, int *i)
{
	int		j;
	char	**numbers;
	long	num;

	while (*i < argc)
	{
		numbers = ft_split(argv[*i], ' ');
		if (!numbers || !numbers[0])
			print_error_and_free(*stack, NULL);
		j = 0;
		while (numbers[j])
		{
			if (!is_valid_number(numbers[j]))
				print_error_and_free(*stack, numbers);
			num = ft_atol(numbers[j]);
			if (num > 2147483647 || is_duplicate(*stack, (int)num))
				print_error_and_free(*stack, numbers);
			stack_add_back(stack, create_node((int)num));
			j++;
		}
		free_array(numbers);
		(*i)++;
	}
}

t_stack	*parse_arguments(int argc, char **argv)
{
	t_stack	*stack;
	int		i;

	stack = NULL;
	i = 1;
	parsing_helper(argc, argv, &stack, &i);
	return (stack);
}
