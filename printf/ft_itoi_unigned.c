/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoi_unigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:25:12 by oel-hadr          #+#    #+#             */
/*   Updated: 2024/11/15 14:25:21 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	get_len_unsigned(unsigned int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void	cpy_mem_unsigned(unsigned int n, char *res, size_t len)
{
	size_t	i;

	if (n == 0)
		res[0] = '0';
	i = len - 1;
	while (n != 0)
	{
		res[i--] = (n % 10) + '0';
		n /= 10;
	}
	res[len] = '\0';
}

char	*ft_itoa_unsigned(unsigned int n)
{
	size_t	len;
	char	*res;

	len = get_len_unsigned(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	cpy_mem_unsigned(n, res, len);
	return (res);
}
