/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 00:22:40 by oel-hadr          #+#    #+#             */
/*   Updated: 2024/11/18 16:44:14 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_int_to_hex(unsigned long num, char c)
{
	char	base[17];
	char	*buffer;
	int		i;

	buffer = malloc(17 * sizeof(char));
	if (!buffer)
		return (NULL);
	i = 0;
	if (c == 'x')
		ft_strlcpy(base, "0123456789abcdef", 17);
	else if (c == 'X')
		ft_strlcpy(base, "0123456789ABCDEF", 17);
	if (num == 0)
	{
		buffer[0] = '0';
		i = 1;
	}
	while (num)
	{
		buffer[i] = base[num % 16];
		num = num / 16;
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}
