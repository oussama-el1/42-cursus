/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:41:23 by oel-hadr          #+#    #+#             */
/*   Updated: 2025/01/09 02:11:16 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_error(t_stack *stack)
{
	write(2, "Error\n", 6);
	free_stack(stack);
	exit(EXIT_FAILURE);
}

void	stack_add_back(t_stack **stack, t_stack *new_node)
{
	t_stack	*current;

	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	current = *stack;
	while (current->next)
		current = current->next;
	current->next = new_node;
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_duplicate(t_stack *stack, int num)
{
	while (stack)
	{
		if (stack->data == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if ((sign == 1 && result > 2147483647)
			|| (sign == -1 && result > 2147483648))
			return (2147483648);
		str++;
	}
	return (result * sign);
}
