/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:31:17 by oel-hadr          #+#    #+#             */
/*   Updated: 2024/10/27 16:01:53 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*memory;
	size_t	total_size;

	total_size = count * size;
	if (count != 0 && total_size / count != size)
		return (NULL);
	memory = malloc(total_size);
	if (!memory)
		return (NULL);
	ft_bzero(memory, total_size);
	return (memory);
}
