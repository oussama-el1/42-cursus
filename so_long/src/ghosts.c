/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghosts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 05:02:14 by oel-hadr          #+#    #+#             */
/*   Updated: 2025/01/15 22:34:55 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	**init_visited(t_map *game)
{
	int	**visited;
	int	i;

	i = 0;
	visited = malloc(sizeof(int *) * game->height);
	if (!visited)
		error_handler(game, "Error\n Can't allocate memory\n");
	while (i < game->height)
	{
		visited[i] = malloc(sizeof(int) * game->width);
		if (!visited[i])
		{
			while (i >= 0)
			{
				free(visited[i]);
				i--;
			}
			free(visited);
			error_handler(game, "Error\n Can't allocate memory\n");
		}
		ft_memset(visited[i], 0, game->width * sizeof(int));
		i++;
	}
	return (visited);
}

void	free_visited(int **visited, t_map *game)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

void	check_directions(t_map *game, int g, int *best_move)
{
	int		d;
	int		nx;
	int		ny;
	int		dist;
	int		shortest_dist;

	d = 0;
	shortest_dist = INT_MAX;
	while (d < 4)
	{
		nx = game->ghosts[g].x + g_directions[d][0];
		ny = game->ghosts[g].y + g_directions[d][1];
		if (is_valid_move(game->grid, nx, ny, game))
		{
			dist = bfs_to_target((t_point){nx, ny}, game);
			if (dist < shortest_dist)
			{
				shortest_dist = dist;
				*best_move = d;
			}
		}
		d++;
	}
}

void	update_ghost_pos(t_map *game, int g, int best_move, t_point player)
{
	int		new_x;
	int		new_y;
	char	ghost_color;

	new_x = game->ghosts[g].x + g_directions[best_move][0];
	new_y = game->ghosts[g].y + g_directions[best_move][1];
	ghost_color = game->grid[game->ghosts[g].y][game->ghosts[g].x];
	game->grid[game->ghosts[g].y][game->ghosts[g].x] = game->ghosts[g].parent;
	game->ghosts[g].parent = game->grid[new_y][new_x];
	game->grid[new_y][new_x] = ghost_color;
	game->ghosts[g].x = new_x;
	game->ghosts[g].y = new_y;
	update_ghost_assets(game, ghost_color, best_move);
	if (game->ghosts[g].x == player.x && game->ghosts[g].y == player.y)
		check_game_over(game, "game Over! You lost!");
}

void	move_ghosts(t_map *game)
{
	t_point	player;
	int		best_move;
	int		g;

	g = 0;
	player = (t_point){game->player_x, game->player_y};
	while (g < game->ghost_count)
	{
		best_move = -1;
		check_directions(game, g, &best_move);
		update_ghost_pos(game, g, best_move, player);
		g++;
	}
}
