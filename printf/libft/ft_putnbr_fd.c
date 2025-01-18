/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:38:57 by oel-hadr          #+#    #+#             */
/*   Updated: 2024/11/14 14:06:04 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd_recursion(int n, int fd)
{
	char	digit;

	if (n > 9)
		ft_putnbr_fd_recursion(n / 10, fd);
	digit = (n % 10) + '0';
	write(fd, &digit, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		if (n == -2147483648)
		{
			write(fd, "2", 1);
			n = 147483648;
		}
		else
			n = -n;
	}
	ft_putnbr_fd_recursion(n, fd);
}
