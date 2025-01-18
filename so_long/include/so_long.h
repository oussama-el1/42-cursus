/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:34:45 by oel-hadr          #+#    #+#             */
/*   Updated: 2025/01/17 08:44:33 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>

# define WIN_TITLE "Pacman game"
# define VALIDCHARS "01PECGRB"
# define MAX_X 80
# define MAX_Y 36
# define TILE_SIZE 32
# define ESC_KEY 53
# define UP_KEY 126
# define DOWN_KEY 125
# define LEFT_KEY 123
# define RIGHT_KEY 124

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_queue
{
	t_list	*front;
	t_list	*rear;
}	t_queue;

typedef struct s_assets
{
	void		*wall;
	void		*exit;
	void		*collectible;
	void		*player;
	void		*player_open;
	void		*player_closed;
	void		*ghost_red;
	void		*ghost_blue;
	void		*ghost_green;
	void		*background;
	int			width;
	int			height;
	int			show_exit;
}	t_assets;

typedef struct s_node
{
	int		x;
	int		y;
	int		dist;
	char	parent;
}	t_node;

typedef struct s_map
{
	t_list		*map;
	int			**visited;
	char		**grid;
	void		*mlx;
	void		*win;
	t_assets	*assets;
	size_t		width;
	t_node		*ghosts;
	int			height;
	int			player_x;
	int			player_y;
	int			exit;
	int			collectibles;
	int			moves;
	int			ghost_mode;
	int			ghost_count;
	int			frame;
	int			sleep_enabled;
}	t_map;

extern int	g_directions[4][2];

void	set_enemys(t_map *game);
int		is_valid_move(char **grid, int x, int y, t_map *game);
void	check_neghbor(t_node *queue, t_node current,
			int *back, t_map *game);
int		bfs_helper(t_node *queue, t_map *game, t_point ghost);
int		bfs_to_target(t_point ghost, t_map *game);

int		key_hook(int keycode, t_map *Game);
void	free_grid(char **grid, int height);
int		exit_game(t_map *Game);
void	set_player(char *path_player, char *path_open,
			void *mlx, t_assets *assets);
void	change_player_direction_helper(int keycode,
			t_assets *assets, void *mlx);

void	change_player_direction(t_map *Game, int keycode);
void	perform_move(t_map *Game, int new_x, int new_y, int keycode);
void	move_player(t_map *Game, int keycode);
void	check_game_over(t_map *Game, char *message);

void	update_red_ghost(t_map *game, int best_move);
void	update_green_ghost(t_map *game, int best_move);
void	update_blue_ghost(t_map *game, int best_move);
void	update_ghost_assets(t_map *game, char ghost_color, int best_move);

int		**init_visited(t_map *game);
void	free_visited(int **visited, t_map *game);
void	check_directions(t_map *game, int g, int *best_move);
void	update_ghost_pos(t_map *game, int g, int best_move, t_point player);
void	move_ghosts(t_map *game);

void	put_asset(t_map *game, t_assets *assets, int x, int y);
void	render_map_elements(t_assets *assets, t_map *game);
int		render_map(t_map *game);
void	free_assets_helper(t_assets *assets, void *mlx);
void	free_assets(t_assets *assets, void *mlx);

void	initialize_mlx(t_map *game);
int		load_assets(t_assets *assets, t_map *game);
void	render_background(void *mlx, void *win, t_assets *assets, t_map *game);

int		check_extention(char *s1);
void	display_movements(t_map *game);
void	set_assets(t_assets *assets, t_map *game);
void	put_image(t_map *game, void *img, int x, int y);

void	cleanup(t_queue *queue, int **visited, int height);
char	**ft_lst_to_array(t_map *Game);
void	error_handler(t_map *Game, char *message);
void	initialize_game(t_map *Game);
void	count_collectibles(t_map *Game);

t_list	*parse_map(char *path);
int		check_is_rectangular(t_list *map);
int		check_is_closed(t_list *map, int width, int height);
int		check_is_valid(t_map *Game);

int		check_bounds(int x, int y, int width, int height);
int		isghost(t_map *Game, int x, int y);
int		bfs_find_exit(t_map *Game, t_queue *queue, int **visited, int i);
int		has_valid_path(t_map *Game);
int		validate_map(t_map *Game);

t_queue	*init_queue(void);
void	enqueue(t_queue *queue, t_point point);
int		is_empty(t_queue *queue);
t_point	dequeue(t_queue *queue);
void	free_queue(t_queue *queue);

void	reset_visited(t_map *Game);
void	error_handler_helper(t_map *Game);
void	exit_game_helper(t_map *Game);
void	display_movements_in_shell(t_map *Game, int new_x, int new_y);

#endif
