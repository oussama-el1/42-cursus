/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 00:01:24 by oel-hadr          #+#    #+#             */
/*   Updated: 2025/01/17 06:21:24 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	initialize_mlx_helper(t_map *game)
{
	void	*mlx;
	void	*win;
	int		win_width;
	int		win_height;

	mlx = mlx_init();
	if (!mlx)
		error_handler(game, "Error\n Can't initialize mlx\n");
	win_width = game->width * 32;
	win_height = game->height * 32 + 0.1 * (game->height * 32);
	win = mlx_new_window(mlx, win_width, win_height, WIN_TITLE);
	if (!win)
	{
		free(mlx);
		error_handler(game, "Error\n Can't create window\n");
	}
	game->mlx = mlx;
	game->win = win;
}

void	initialize_mlx(t_map *game)
{
	initialize_mlx_helper(game);
	game->assets = malloc(sizeof(t_assets));
	if (!game->assets)
	{
		mlx_destroy_window(game->mlx, game->win);
		free(game->mlx);
		error_handler(game, "Error\n Can't allocate memory\n");
	}
	if (!load_assets(game->assets, game))
	{
		mlx_destroy_window(game->mlx, game->win);
		free(game->mlx);
		free(game->assets);
		error_handler(game, "Error\n Can't load assets\n");
	}
	game->assets->show_exit = 0;
}

int	load_assets(t_assets *assets, t_map *game)
{
	set_assets(assets, game);
	if (game->ghost_mode)
	{
		assets->ghost_blue = mlx_xpm_file_to_image(game->mlx,
				"textures/ghosts/blue/ghost_blue_down.xpm",
				&assets->width, &assets->height);
		assets->ghost_green = mlx_xpm_file_to_image(game->mlx,
				"textures/ghosts/green/ghost_green_down.xpm",
				&assets->width, &assets->height);
		assets->ghost_red = mlx_xpm_file_to_image(game->mlx,
				"textures/ghosts/red/ghost_red_down.xpm",
				&assets->width, &assets->height);
	}
	if (!assets->wall || !assets->collectible || !assets->player
		|| !assets->player_closed || !assets->player || !assets->player_open
		||!assets->background
		|| (game->ghost_mode
			&& (!assets->ghost_blue
				||!assets->ghost_green || !assets->ghost_red)))
	{
		free_assets(assets, game->mlx);
		return (0);
	}
	return (1);
}

void	render_background(void *mlx, void *win, t_assets *assets, t_map *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height * TILE_SIZE)
	{
		x = 0;
		while ((size_t)x < game->width * TILE_SIZE)
		{
			mlx_put_image_to_window(mlx, win, assets->background, x, y);
			x += TILE_SIZE;
		}
		y += TILE_SIZE;
	}
}

void	exit_game_helper(t_map *Game)
{
	if (Game->grid)
		free_grid(Game->grid, Game->height);
	if (Game->visited)
		free_visited(Game->visited, Game);
	if (Game->ghosts && Game->ghost_mode)
		free(Game->ghosts);
}
