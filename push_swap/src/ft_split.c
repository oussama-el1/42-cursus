/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:01:03 by oel-hadr          #+#    #+#             */
/*   Updated: 2024/12/25 09:18:16 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	count_word(char const *s, char c, int n)
{
	int	i;
	int	count;
	int	new_word;

	i = 0;
	count = 0;
	new_word = 1;
	while (i < n)
	{
		if (s[i] == c)
			new_word = 1;
		else if (new_word == 1)
		{
			count++;
			new_word = 0;
		}
		i++;
	}
	return (count);
}

static void	skip_whitspace(int *index, char const *s, char c, int n)
{
	while (*index < n && s[*index] == c)
		(*index)++;
}

static char	*get_word(const char *s, char c, int *index, int n)
{
	int		len;
	int		i;
	char	*word;

	len = 0;
	while (*index + len < n && s[*index + len] != c)
		len++;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[*index + i];
		i++;
	}
	word[i] = '\0';
	*index = *index + len;
	return (word);
}

static char	**set_memory(const char *s, char c, char **res)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < count_word(s, c, (int)ft_strlen(s)) && j < (int)ft_strlen(s))
	{
		skip_whitspace(&j, s, c, ft_strlen(s));
		if (j < (int)ft_strlen(s))
		{
			res[i] = get_word(s, c, &j, ft_strlen(s));
			if (res[i] == NULL)
			{
				while (i > 0)
					free(res[--i]);
				free(res);
				return (NULL);
			}
			i++;
		}
	}
	res[i] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = malloc(sizeof(char *) * (count_word(s, c, ft_strlen(s)) + 1));
	if (!res)
		return (NULL);
	return (set_memory(s, c, res));
}
