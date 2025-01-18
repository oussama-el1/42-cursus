/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 21:41:22 by oel-hadr          #+#    #+#             */
/*   Updated: 2025/01/17 08:30:32 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_queue	*init_queue(void)
{
	t_queue	*queue;

	queue = malloc(sizeof(t_queue));
	if (!queue)
	{
		write(2, "Error\n Can't allocate memory\n", 29);
		exit(EXIT_FAILURE);
	}
	queue->front = NULL;
	queue->rear = NULL;
	return (queue);
}

void	enqueue(t_queue *queue, t_point point)
{
	t_list	*new;
	t_point	*new_point;

	new_point = malloc(sizeof(t_point));
	if (!new_point)
		exit(EXIT_FAILURE);
	*new_point = point;
	new = ft_lstnew(new_point);
	if (!new)
	{
		write(2, "Error\n Can't allocate memory\n", 29);
		exit(EXIT_FAILURE);
	}
	if (!queue->front)
	{
		queue->front = new;
		queue->rear = new;
	}
	else
	{
		queue->rear->next = new;
		queue->rear = new;
	}
}

int	is_empty(t_queue *queue)
{
	return (!queue->front);
}

t_point	dequeue(t_queue *queue)
{
	t_point	*point_ptr;
	t_point	point;
	t_list	*tmp;

	if (is_empty(queue))
	{
		write(2, "Error\nQueue is empty\n", 22);
		exit(EXIT_FAILURE);
	}
	point_ptr = (t_point *)queue->front->content;
	point = *point_ptr;
	free(point_ptr);
	tmp = queue->front;
	queue->front = queue->front->next;
	free(tmp);
	return (point);
}

void	free_queue(t_queue *queue)
{
	t_list	*current;
	t_list	*next;

	current = queue->front;
	while (current)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
	queue->front = NULL;
	queue->rear = NULL;
}
