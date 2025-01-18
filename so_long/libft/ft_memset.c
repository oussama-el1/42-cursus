/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:05:22 by oel-hadr          #+#    #+#             */
/*   Updated: 2024/10/27 14:33:55 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int x, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *) ptr;
	i = 0;
	while (i < n)
	{
		p[i] = (unsigned char)x;
		i++;
	}
	return (ptr);
}
