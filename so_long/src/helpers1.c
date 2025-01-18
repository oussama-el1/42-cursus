/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 23:49:08 by oel-hadr          #+#    #+#             */
/*   Updated: 2025/01/17 02:13:08 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_extention(char *s1)
{
	int		i;
	int		j;
	char	*s2;

	i = ft_strlen(s1) - 1;
	j = 3;
	s2 = ".ber";
	while (i >= 0 && j >= 0)
	{
		if (s1[i] != s2[j])
			return (0);
		i--;
		j--;
	}
	return (1);
}

void	display_movements(t_map *game)
{
	char	*str;
	char	*moves;
	int		text_x;
	int		text_y;
	int		reserved_space;

	moves = ft_itoa(game->moves);
	if (!moves)
		error_handler(game, "Error\n Can't allocate memory\n");
	str = ft_strjoin("Moves: ", moves);
	if (!str)
	{
		free(moves);
		error_handler(game, "Error\n Can't allocate memory\n");
	}
	reserved_space = 0.1 * (game->height * TILE_SIZE);
	text_x = (game->width * TILE_SIZE) / 2 - (ft_strlen(str) * 5);
	text_y = (game->height * TILE_SIZE) + (reserved_space / 2) - 10;
	mlx_string_put(game->mlx, game->win, text_x, text_y, 0x00FFFFFF, str);
	free(moves);
	free(str);
}

void	set_assets(t_assets *assets, t_map *game)
{
	assets->wall = NULL;
	assets->collectible = NULL;
	assets->background = NULL;
	assets->player = NULL;
	assets->player_closed = NULL;
	assets->player_open = NULL;
	assets->ghost_blue = NULL;
	assets->ghost_green = NULL;
	assets->ghost_red = NULL;
	assets->exit = NULL;
	assets->wall = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &assets->width, &assets->height);
	assets->collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &assets->width, &assets->height);
	assets->background = mlx_xpm_file_to_image(game->mlx,
			"textures/background.xpm", &assets->width, &assets->height);
	assets->player_open = mlx_xpm_file_to_image(game->mlx,
			"textures/player_open_right.xpm", &assets->width, &assets->height);
	assets->player = mlx_xpm_file_to_image(game->mlx,
			"textures/player_right.xpm", &assets->width, &assets->height);
	assets->player_closed = mlx_xpm_file_to_image(game->mlx,
			"textures/player_closed.xpm", &assets->width, &assets->height);
}

void	put_image(t_map *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		img, x * TILE_SIZE, y * TILE_SIZE);
}

void	reset_visited(t_map *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < (int)game->width)
		{
			game->visited[i][j] = 0;
			j++;
		}
		i++;
	}
}
