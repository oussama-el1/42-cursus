/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:30:43 by oel-hadr          #+#    #+#             */
/*   Updated: 2024/10/26 17:04:27 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t					i;
	const unsigned char		*src_ptr;
	unsigned char			*dest_ptr;

	src_ptr = (const unsigned char *) src;
	dest_ptr = (unsigned char *) dest;
	if (dest_ptr == src_ptr || n == 0)
		return (dest);
	i = 0;
	while (i < n)
	{
		dest_ptr[i] = src_ptr[i];
		i++;
	}
	return (dest);
}
