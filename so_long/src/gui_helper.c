/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 05:26:19 by oel-hadr          #+#    #+#             */
/*   Updated: 2025/01/17 07:06:47 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_asset(t_map *game, t_assets *assets, int x, int y)
{
	if (game->grid[y][x] == '1')
		put_image(game, assets->wall, x, y);
	else if (game->grid[y][x] == 'E' && assets->show_exit)
		put_image(game, assets->exit, x, y);
	else if (game->grid[y][x] == 'C')
		put_image(game, assets->collectible, x, y);
	else if (game->grid[y][x] == 'P')
	{
		if (game->frame % 3 == 0)
			put_image(game, assets->player_closed, x, y);
		else if (game->frame % 3 == 1)
			put_image(game, assets->player, x, y);
		else
			put_image(game, assets->player_open, x, y);
	}
	else if (game->grid[y][x] == 'B')
		put_image(game, assets->ghost_blue, x, y);
	else if (game->grid[y][x] == 'G')
		put_image(game, assets->ghost_green, x, y);
	else if (game->grid[y][x] == 'R')
		put_image(game, assets->ghost_red, x, y);
}

void	render_map_elements(t_assets *assets, t_map *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while ((size_t)x < game->width)
		{
			put_asset(game, assets, x, y);
			x++;
		}
		y++;
	}
}

int	render_map(t_map *game)
{
	static int	frame;

	game->frame = frame;
	mlx_clear_window(game->mlx, game->win);
	render_background(game->mlx, game->win, game->assets, game);
	render_map_elements(game->assets, game);
	display_movements(game);
	if (game->sleep_enabled)
		usleep(66667);
	game->sleep_enabled = 1;
	frame++;
	return (0);
}

void	free_assets_helper(t_assets *assets, void *mlx)
{
	if (assets->background)
	{
		mlx_destroy_image(mlx, assets->background);
		assets->background = NULL;
	}
	if (assets->player_closed)
	{
		mlx_destroy_image(mlx, assets->player_closed);
		assets->player_closed = NULL;
	}
	if (assets->ghost_blue)
	{
		mlx_destroy_image(mlx, assets->ghost_blue);
		assets->ghost_blue = NULL;
	}
	if (assets->ghost_green)
	{
		mlx_destroy_image(mlx, assets->ghost_green);
		assets->ghost_green = NULL;
	}
	if (assets->ghost_red)
	{
		mlx_destroy_image(mlx, assets->ghost_red);
		assets->ghost_red = NULL;
	}
}

void	free_assets(t_assets *assets, void *mlx)
{
	if (!assets || !mlx)
		return ;
	if (assets->wall)
	{
		mlx_destroy_image(mlx, assets->wall);
		assets->wall = NULL;
	}
	if (assets->exit)
	{
		mlx_destroy_image(mlx, assets->exit);
		assets->exit = NULL;
	}
	if (assets->collectible)
	{
		mlx_destroy_image(mlx, assets->collectible);
		assets->collectible = NULL;
	}
	if (assets->player)
	{
		mlx_destroy_image(mlx, assets->player);
		assets->player = NULL;
	}
	if (assets->player_open)
		mlx_destroy_image(mlx, assets->player_open);
	free_assets_helper(assets, mlx);
}
