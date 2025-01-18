/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 06:13:21 by oel-hadr          #+#    #+#             */
/*   Updated: 2025/01/17 08:29:17 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	cleanup(t_queue *queue, int **visited, int height)
{
	int	i;

	free_queue(queue);
	free(queue);
	i = 0;
	while (i < height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

char	**ft_lst_to_array(t_map *Game)
{
	char	**grid;
	int		i;
	t_list	*current;

	grid = malloc(sizeof(char *) * (Game->height + 1));
	if (!grid)
		error_handler(Game, "Error\n Can't allocate memory\n");
	current = Game->map;
	i = 0;
	while (current)
	{
		grid[i] = ft_strdup((char *)current->content);
		if (!grid[i])
			error_handler(Game, "Error\n Can't allocate memory\n");
		i++;
		current = current->next;
	}
	grid[i] = NULL;
	return (grid);
}

void	error_handler(t_map *Game, char *message)
{
	int	i;

	if (Game->map)
		ft_lstclear(&Game->map, free);
	if (Game->grid)
	{
		i = 0;
		while (i < Game->height)
		{
			free(Game->grid[i]);
			i++;
		}
		free(Game->grid);
	}
	if (Game->mlx)
		free(Game->mlx);
	if (Game->visited)
		free_visited(Game->visited, Game);
	error_handler_helper(Game);
	free(Game);
	if (!message)
		message = "Unknown error";
	write(1, message, ft_strlen(message));
	exit(EXIT_FAILURE);
}

void	initialize_game(t_map *Game)
{
	Game->height = ft_lstsize(Game->map);
	Game->player_x = -1;
	Game->player_y = -1;
	Game->exit = 0;
	Game->collectibles = 0;
	Game->ghost_mode = 0;
	Game->moves = 0;
	Game->grid = NULL;
	Game->ghosts = NULL;
	Game->visited = NULL;
	Game->assets = NULL;
	Game->mlx = NULL;
	Game->win = NULL;
}

void	count_collectibles(t_map *Game)
{
	int	i;
	int	j;

	i = 0;
	Game->collectibles = 0;
	Game->ghost_count = 0;
	while (i < Game->height)
	{
		j = 0;
		while ((size_t)j < Game->width)
		{
			if (Game->grid[i][j] == 'C')
				Game->collectibles++;
			else if (Game->grid[i][j] == 'G' || Game->grid[i][j] == 'R'
					|| Game->grid[i][j] == 'B')
				Game->ghost_count++;
			j++;
		}
		i++;
	}
}
