/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 05:57:13 by oel-hadr          #+#    #+#             */
/*   Updated: 2025/01/17 06:39:04 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_bounds(int x, int y, int width, int height)
{
	return (x >= 0 && x < width && y >= 0 && y < height);
}

int	isghost(t_map *Game, int x, int y)
{
	if (Game->grid[y][x] == 'G' || Game->grid[y][x] == 'R'
		|| Game->grid[y][x] == 'B')
		return (1);
	return (0);
}

int	bfs_find_exit(t_map *Game, t_queue *queue, int **visited, int i)
{
	t_point	current;
	int		new_x;
	int		new_y;

	while (!is_empty(queue))
	{
		current = dequeue(queue);
		i = 0;
		while (i < 4)
		{
			new_x = current.x + g_directions[i][0];
			new_y = current.y + g_directions[i][1];
			if (check_bounds(new_x, new_y, Game->width, Game->height)
				&& !visited[new_y][new_x] && Game->grid[new_y][new_x] != '1'
				&& !isghost(Game, new_x, new_y))
			{
				if (Game->grid[new_y][new_x] == 'E')
					return (1);
				enqueue(queue, (t_point){new_x, new_y});
				visited[new_y][new_x] = 1;
			}
			i++;
		}
	}
	return (0);
}

int	has_valid_path(t_map *Game)
{
	int		**visited;
	t_queue	*queue;
	int		result;
	int		i;

	i = 0;
	visited = init_visited(Game);
	queue = init_queue();
	enqueue(queue, (t_point){Game->player_x, Game->player_y});
	visited[Game->player_y][Game->player_x] = 1;
	result = bfs_find_exit(Game, queue, visited, i);
	cleanup(queue, visited, Game->height);
	return (result);
}

int	validate_map(t_map *Game)
{
	initialize_game(Game);
	if (Game->height >= MAX_Y)
		error_handler(Game, "The map is too big");
	if (!check_is_rectangular(Game->map))
		error_handler(Game, "The map is not rectangular");
	Game->width = ft_strlen((char *)Game->map->content);
	if (Game->width >= MAX_X)
		error_handler(Game, "The map is too big");
	if (!check_is_closed(Game->map, Game->width, Game->height))
		error_handler(Game, "The map is not closed");
	if (!check_is_valid(Game))
		error_handler(Game, "The map is not valid");
	Game->grid = ft_lst_to_array(Game);
	if (!Game->grid)
		error_handler(Game, "Can't allocate memory");
	if (!has_valid_path(Game))
		error_handler(Game, "No valid path in the map");
	return (1);
}
