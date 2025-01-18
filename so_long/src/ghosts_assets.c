/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghosts_assets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 04:57:05 by oel-hadr          #+#    #+#             */
/*   Updated: 2025/01/17 08:40:25 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	update_red_ghost(t_map *game, int best_move)
{
	if (best_move == 0)
		game->assets->ghost_red = mlx_xpm_file_to_image(game->mlx,
				"textures/ghosts/red/ghost_red_up.xpm",
				&game->assets->width, &game->assets->height);
	else if (best_move == 1)
		game->assets->ghost_red = mlx_xpm_file_to_image(game->mlx,
				"textures/ghosts/red/ghost_red_down.xpm",
				&game->assets->width, &game->assets->height);
	else if (best_move == 2)
		game->assets->ghost_red = mlx_xpm_file_to_image(game->mlx,
				"textures/ghosts/red/ghost_red_left.xpm",
				&game->assets->width, &game->assets->height);
	else if (best_move == 3)
		game->assets->ghost_red = mlx_xpm_file_to_image(game->mlx,
				"textures/ghosts/red/ghost_red_right.xpm",
				&game->assets->width, &game->assets->height);
}

void	update_green_ghost(t_map *game, int best_move)
{
	if (best_move == 0)
		game->assets->ghost_green = mlx_xpm_file_to_image(game->mlx,
				"textures/ghosts/green/ghost_green_up.xpm",
				&game->assets->width, &game->assets->height);
	else if (best_move == 1)
		game->assets->ghost_green = mlx_xpm_file_to_image(game->mlx,
				"textures/ghosts/green/ghost_green_down.xpm",
				&game->assets->width, &game->assets->height);
	else if (best_move == 2)
		game->assets->ghost_green = mlx_xpm_file_to_image(game->mlx,
				"textures/ghosts/green/ghost_green_left.xpm",
				&game->assets->width, &game->assets->height);
	else if (best_move == 3)
		game->assets->ghost_green = mlx_xpm_file_to_image(game->mlx,
				"textures/ghosts/green/ghost_green_right.xpm",
				&game->assets->width, &game->assets->height);
}

void	update_blue_ghost(t_map *game, int best_move)
{
	if (best_move == 0)
		game->assets->ghost_blue = mlx_xpm_file_to_image(game->mlx,
				"textures/ghosts/blue/ghost_blue_up.xpm",
				&game->assets->width, &game->assets->height);
	else if (best_move == 1)
		game->assets->ghost_blue = mlx_xpm_file_to_image(game->mlx,
				"textures/ghosts/blue/ghost_blue_down.xpm",
				&game->assets->width, &game->assets->height);
	else if (best_move == 2)
		game->assets->ghost_blue = mlx_xpm_file_to_image(game->mlx,
				"textures/ghosts/blue/ghost_blue_left.xpm",
				&game->assets->width, &game->assets->height);
	else if (best_move == 3)
		game->assets->ghost_blue = mlx_xpm_file_to_image(game->mlx,
				"textures/ghosts/blue/ghost_blue_right.xpm",
				&game->assets->width, &game->assets->height);
}

void	update_ghost_assets(t_map *game, char ghost_color, int best_move)
{
	if (ghost_color == 'R')
		update_red_ghost(game, best_move);
	else if (ghost_color == 'G')
		update_green_ghost(game, best_move);
	else if (ghost_color == 'B')
		update_blue_ghost(game, best_move);
}

void	display_movements_in_shell(t_map *Game, int new_x, int new_y)
{
	char	*moves;

	if (Game->grid[new_y][new_x] != 'E')
	{
		moves = ft_itoa(Game->moves);
		if (!moves)
		{
			write(2, "Error\nCan't allocate memory\n", 29);
			exit_game(Game);
		}
		write(1, "Moves: ", 7);
		write(1, moves, ft_strlen(moves));
		write(1, "\n", 1);
		free(moves);
	}
}
