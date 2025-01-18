/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 02:39:19 by oel-hadr          #+#    #+#             */
/*   Updated: 2025/01/15 08:06:57 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_list	*parse_map(char *path)
{
	int		file;
	char	*line;
	t_list	*map;

	if (!path || !check_extention(path))
		return (NULL);
	file = open(path, O_RDONLY);
	if (file < 0)
		return (NULL);
	map = NULL;
	line = get_next_line(file);
	while (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		ft_lstadd_back(&map, ft_lstnew(ft_strdup(line)));
		free(line);
		line = get_next_line(file);
	}
	close(file);
	return (map);
}

int	check_is_rectangular(t_list *map)
{
	size_t	width;
	int		i;
	t_list	*current;

	width = ft_strlen((char *)map->content);
	current = map->next;
	i = 1;
	while (current)
	{
		if (ft_strlen((char *)current->content) != width)
			return (0);
		current = current->next;
		i++;
	}
	return (1);
}

int	check_is_closed(t_list *map, int width, int height)
{
	int		i;
	int		j;
	t_list	*current;

	current = map;
	i = 0;
	while (current)
	{
		j = 0;
		while (((char *)current->content)[j])
		{
			if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
			{
				if (((char *)current->content)[j] != '1')
					return (0);
			}
			j++;
		}
		i++;
		current = current->next;
	}
	return (1);
}

int	validate_char(t_map *Game, char c, int *start, t_point current)
{
	if (!ft_strchr(VALIDCHARS, c))
		return (0);
	else if (c == 'P')
	{
		*start += 1;
		Game->player_x = current.x;
		Game->player_y = current.y;
	}
	else if (c == 'E')
		Game->exit++;
	else if (c == 'C')
		Game->collectibles++;
	else if (ft_strchr("RGB", c))
		Game->ghost_mode = 1;
	return (1);
}

int	check_is_valid(t_map *Game)
{
	int		i;
	int		j;
	int		start;
	t_list	*current;

	current = Game->map;
	i = 0;
	start = 0;
	while (current)
	{
		j = 0;
		while (((char *)current->content)[j])
		{
			if (!validate_char(Game, ((char *)current->content)[j],
				&start, (t_point){j, i}))
				return (0);
			j++;
		}
		i++;
		current = current->next;
	}
	if (start != 1 || Game->exit != 1 || Game->collectibles == 0)
		return (0);
	return (1);
}
