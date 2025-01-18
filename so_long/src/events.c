/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 08:35:28 by oel-hadr          #+#    #+#             */
/*   Updated: 2025/01/17 07:05:28 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	key_hook(int keycode, t_map *Game)
{
	if (keycode == ESC_KEY)
		exit_game(Game);
	else if (keycode == UP_KEY || keycode == DOWN_KEY
		|| keycode == LEFT_KEY || keycode == RIGHT_KEY)
		move_player(Game, keycode);
	return (0);
}

void	free_grid(char **grid, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

int	exit_game(t_map *Game)
{
	write(1, "Exiting the game\n", 17);
	if (Game->assets)
	{
		free_assets(Game->assets, Game->mlx);
		free(Game->assets);
		Game->assets = NULL;
	}
	if (Game->mlx && Game->win)
	{
		mlx_destroy_window(Game->mlx, Game->win);
		Game->win = NULL;
		free(Game->mlx);
		Game->mlx = NULL;
	}
	if (Game->map)
		ft_lstclear(&Game->map, free);
	exit_game_helper(Game);
	free(Game);
	exit(EXIT_SUCCESS);
	return (0);
}

void	set_player(char *path_player, char *path_open,
		void *mlx, t_assets *assets)
{
	assets->player = mlx_xpm_file_to_image(mlx, path_player,
			&assets->width, &assets->height);
	assets->player_open = mlx_xpm_file_to_image(mlx, path_open,
			&assets->width, &assets->height);
}

void	change_player_direction_helper(int keycode, t_assets *assets, void *mlx)
{
	if (keycode == UP_KEY)
		set_player("textures/player_up.xpm",
			"textures/player_open_up.xpm", mlx, assets);
	else if (keycode == DOWN_KEY)
		set_player("textures/player_down.xpm",
			"textures/player_open_down.xpm", mlx, assets);
	else if (keycode == LEFT_KEY)
		set_player("textures/player_left.xpm",
			"textures/player_open_left.xpm", mlx, assets);
	else if (keycode == RIGHT_KEY)
		set_player("textures/player_right.xpm",
			"textures/player_open_right.xpm", mlx, assets);
}
