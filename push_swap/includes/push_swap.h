/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:43:38 by oel-hadr          #+#    #+#             */
/*   Updated: 2025/01/08 23:58:18 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_stack
{
	int				data;
	int				index;
	struct s_stack	*next;
}	t_stack;

//helpers
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
t_stack	*create_node(int data);
int		stack_size(t_stack *root);
void	move_min_to_top(t_stack **stack);
void	stack_add_back(t_stack **stack, t_stack *new_node);
void	free_stack(t_stack *stack);
void	print_error(t_stack *stack);
void	set_indexs(t_stack *stack_a);
void	push_back_correct_in_order(t_stack **stack_a, t_stack **stack_b);
int		checksorted(t_stack **stack_a);
int		ft_strcmp(const char *s1, const char *s2);

// stack functions
void	push(t_stack **root, int data);
int		pop(t_stack **root);
int		isempty(t_stack *root);

// parsing and validation
t_stack	*parse_arguments(int argc, char **argv);
long	ft_atol(const char *str);
int		is_duplicate(t_stack *stack, int num);
int		is_valid_number(char *str);

// push swap genirique operations
void	swap_op(t_stack **root);
void	push_op(t_stack **stack1, t_stack **stack2);
void	rotate_op(t_stack **root);
void	rotate_reverse_op(t_stack **root);

// push swap op
void	sa(t_stack **stack_a, int sorting);
void	sb(t_stack **stack_b, int sorting);
void	ss(t_stack **stack_a, t_stack **stack_b, int sorting);
void	pa(t_stack **stack_a, t_stack **stack_b, int sorting);
void	pb(t_stack **stack_a, t_stack **stack_b, int sorting);
void	ra(t_stack **stack_a, int sorting);
void	rb(t_stack **stack_b, int sorting);
void	rr(t_stack **stack_a, t_stack **stack_b, int sorting);
void	rra(t_stack **stack_a, int sorting);
void	rrb(t_stack **stack_b, int sorting);

// sorting functions
void	sort_two(t_stack **stack);
void	sort_three(t_stack **stack);
void	sort_four(t_stack **stack_a, t_stack **stack_b);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
void	pivot_sort(t_stack **sa, t_stack **sb);

#endif
