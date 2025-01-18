/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:18:32 by oel-hadr          #+#    #+#             */
/*   Updated: 2024/10/23 17:40:45 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	cpy(char *res, const char *s1, int start, int end)
{
	int	i;

	i = 0;
	while ((i + start) < end)
	{
		res[i] = s1[start + i];
		i++;
	}
	res[i] = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		s1_len;
	char	*trimed;

	if (!s1 || !set)
		return (NULL);
	if (!*set)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	start = 0;
	while (ft_strchr(set, s1[start]) && start < s1_len)
		start++;
	if (start == s1_len)
		return (ft_strdup(""));
	end = s1_len;
	while (ft_strchr(set, s1[end - 1]) && end > start)
		end--;
	trimed = malloc(sizeof(char) * (end - start + 1));
	if (!trimed)
		return (NULL);
	cpy(trimed, s1, start, end);
	return (trimed);
}
