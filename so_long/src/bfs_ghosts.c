/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_ghosts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 04:50:25 by oel-hadr          #+#    #+#             */
/*   Updated: 2025/01/17 01:51:53 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	set_enemys(t_map *game)
{
	int	i;
	int	j;
	int	g_index;

	i = 0;
	g_index = 0;
	game->ghosts = malloc(sizeof(t_node) * game->ghost_count);
	if (!game->ghosts)
		error_handler(game, "Error\n Can't allocate memory\n");
	while (i < game->height)
	{
		j = 0;
		while ((size_t)j < game->width)
		{
			if (ft_strchr("RGB", game->grid[i][j]))
			{
				game->ghosts[g_index].x = j;
				game->ghosts[g_index].y = i;
				game->ghosts[g_index].parent = '0';
				g_index++;
			}
			j++;
		}
		i++;
	}
}

int	is_valid_move(char **grid, int x, int y, t_map *game)
{
	return (check_bounds(x, y, game->width, game->height)
		&& grid[y][x] != '1' && grid[y][x] != 'E' && !isghost(game, x, y));
}

void	check_neghbor(t_node *queue, t_node current,
				int *back, t_map *game)
{
	int	new_x;
	int	new_y;
	int	i;

	i = 0;
	while (i < 4)
	{
		new_x = current.x + g_directions[i][0];
		new_y = current.y + g_directions[i][1];
		if (is_valid_move(game->grid, new_x, new_y, game)
			&& !game->visited[new_y][new_x])
		{
			queue[(*back)++] = (t_node){new_x, new_y,
				current.dist + 1, current.parent};
			game->visited[new_y][new_x] = 1;
		}
		i++;
	}
}

int	bfs_helper(t_node *queue, t_map *game, t_point ghost)
{
	int		front;
	int		back;
	t_node	current;

	front = 0;
	back = 0;
	queue[back++] = (t_node){ghost.x, ghost.y, 0, '\0'};
	game->visited[ghost.y][ghost.x] = 1;
	while (front < back)
	{
		current = queue[front++];
		if (current.x == game->player_x && current.y == game->player_y)
			return (current.dist);
		check_neghbor(queue, current, &back, game);
	}
	return (INT_MAX);
}

int	bfs_to_target(t_point ghost, t_map *game)
{
	t_node	*queue;
	int		dist;

	dist = INT_MAX;
	queue = malloc(sizeof(t_node) * game->width * game->height);
	if (!queue)
		error_handler(game, "Error\n Can't allocate memory\n");
	if (!game->visited)
	{
		game->visited = init_visited(game);
		if (!game->visited)
			error_handler(game, "Error\n Can't allocate memory\n");
	}
	dist = bfs_helper(queue, game, ghost);
	reset_visited(game);
	free(queue);
	return (dist);
}
