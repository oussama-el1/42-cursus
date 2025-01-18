/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:52:39 by oel-hadr          #+#    #+#             */
/*   Updated: 2025/01/17 08:33:08 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	g_directions[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

static t_map	*check_and_parse(int argc, char **argv)
{
	t_map	*game;

	if (argc != 2)
	{
		write(2, "Error\nInvalid number of arguments\n", 35);
		exit(EXIT_FAILURE);
	}
	game = malloc(sizeof(t_map));
	game->map = NULL;
	if (!game)
	{
		write(2, "Error\nCan't allocate memory\n", 29);
		exit(EXIT_FAILURE);
	}
	game->map = parse_map(argv[1]);
	if (!game->map)
	{
		write(2, "Error\nInvalid map\n", 19);
		free(game);
		exit(EXIT_FAILURE);
	}
	return (game);
}

int	main(int argc, char **argv)
{
	t_map	*game;

	game = check_and_parse(argc, argv);
	if (validate_map(game))
	{
		game->sleep_enabled = 1;
		initialize_mlx(game);
		count_collectibles(game);
		if (game->ghost_mode)
			set_enemys(game);
		mlx_hook(game->win, 17, 0, (int (*)(void *))exit_game, game);
		mlx_key_hook(game->win, key_hook, game);
		mlx_loop_hook(game->mlx, (int (*)(void *))render_map, game);
		mlx_loop(game->mlx);
	}
	return (0);
}
