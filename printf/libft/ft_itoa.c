/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:03:38 by oel-hadr          #+#    #+#             */
/*   Updated: 2024/11/15 14:25:01 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		if (n == -2147483648)
			n = 2147483647;
		else
			n = -n;
	}
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static void	cpy_mem(int n, char *res, size_t len)
{
	size_t	i;

	if (n == 0)
		res[0] = '0';
	else if (n < 0)
		res[0] = '-';
	i = len - 1;
	if (n == -2147483648)
	{
		res[i--] = '8';
		n = -(n / 10);
	}
	else if (n < 0)
		n = -n;
	while (n != 0)
	{
		res[i--] = (n % 10) + '0';
		n /= 10;
	}
	res[len] = '\0';
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*res;

	len = get_len(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	cpy_mem(n, res, len);
	return (res);
}
