/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 23:27:33 by oel-hadr          #+#    #+#             */
/*   Updated: 2024/10/26 17:12:29 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_ptr;
	const unsigned char	*src_ptr;

	dest_ptr = (unsigned char *)dest;
	src_ptr = (const unsigned char *)src;
	if (dest_ptr < src_ptr)
	{
		while (n--)
			*dest_ptr++ = *src_ptr++;
	}
	else if (dest_ptr > src_ptr)
	{
		dest_ptr += n;
		src_ptr += n;
		while (n--)
			*(--dest_ptr) = *(--src_ptr);
	}
	return (dest);
}
