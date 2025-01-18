/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 02:45:53 by oel-hadr          #+#    #+#             */
/*   Updated: 2025/01/17 08:40:02 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	change_player_direction(t_map *Game, int keycode)
{
	change_player_direction_helper(keycode, Game->assets, Game->mlx);
	if (!Game->assets->player || !Game->assets->player_open)
	{
		write(2, "Error\nCan't load player assets\n", 31);
		free_assets(Game->assets, Game->mlx);
		free(Game->assets);
		mlx_destroy_window(Game->mlx, Game->win);
		free(Game->mlx);
	}
}

void	perform_move(t_map *Game, int new_x, int new_y, int keycode)
{
	change_player_direction(Game, keycode);
	if (isghost(Game, new_x, new_y))
		check_game_over(Game, "Game Over! You lost!");
	else if (Game->grid[new_y][new_x] == 'C')
	{
		Game->collectibles--;
		if (Game->collectibles == 0)
		{
			Game->assets->exit = mlx_xpm_file_to_image(Game->mlx,
					"textures/exit.xpm", &Game->assets->width,
					&Game->assets->height);
			Game->assets->show_exit = 1;
		}
	}
	else if (Game->grid[new_y][new_x] == 'E' && Game->collectibles == 0)
		check_game_over(Game, "Congratulations! You won!");
	else if (Game->grid[new_y][new_x] == 'E' && Game->collectibles != 0)
		return ;
	Game->grid[Game->player_y][Game->player_x] = '0';
	Game->grid[new_y][new_x] = 'P';
	Game->player_x = new_x;
	Game->player_y = new_y;
	Game->moves++;
	Game->sleep_enabled = 0;
}

void	move_player(t_map *Game, int keycode)
{
	int		new_x;
	int		new_y;

	new_x = Game->player_x;
	new_y = Game->player_y;
	if (keycode == UP_KEY)
		new_y--;
	else if (keycode == DOWN_KEY)
		new_y++;
	else if (keycode == LEFT_KEY)
		new_x--;
	else if (keycode == RIGHT_KEY)
		new_x++;
	if (check_bounds(new_x, new_y, Game->width, Game->height)
		&& Game->grid[new_y][new_x] != '1')
	{
		perform_move(Game, new_x, new_y, keycode);
		display_movements_in_shell(Game, new_x, new_y);
	}
	move_ghosts(Game);
}

void	check_game_over(t_map *Game, char *message)
{
	write(1, message, ft_strlen(message));
	write(1, "\n", 1);
	exit_game(Game);
}

void	error_handler_helper(t_map *Game)
{
	if (Game->ghosts)
	{
		free(Game->ghosts);
		Game->ghosts = NULL;
	}
	if (Game->win)
	{
		mlx_destroy_window(Game->mlx, Game->win);
		Game->win = NULL;
	}
	if (Game->assets)
	{
		free_assets(Game->assets, Game->mlx);
		free(Game->assets);
		Game->assets = NULL;
	}
}
