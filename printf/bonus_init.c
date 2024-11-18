/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:56:16 by oel-hadr          #+#    #+#             */
/*   Updated: 2024/11/18 17:13:47 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init(t_flags *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->precision = 0;
	flags->given = 0;
	flags->dot = 0;
	flags->hash = 0;
	flags->space = 0;
	flags->plus = 0;
}

int	print_prefix(t_flags *flags, int *printed, int num)
{
	if ((flags->hash && num != 0) || flags->type == 'p')
	{
		if (flags->type == 'x' || flags->type == 'p')
			write(1, "0x", 2);
		if (flags->type == 'X')
			write(1, "0X", 2);
		*printed += 2;
		return (1);
	}
	return (0);
}

int	prefix_and_zeros(t_flags *flags, int *printed,
unsigned int num, char *buffer)
{
	int	prefix;

	prefix = 0;
	if (flags->width && flags->zero)
	{
		prefix = print_prefix(flags, printed, num);
		if (prefix)
			*printed += print_zeros(flags->width - (ft_strlen(buffer) + 2));
		else
			*printed += print_zeros(flags->width - ft_strlen(buffer));
	}
	return (prefix);
}

void	ft_printf_init(t_flags *flags, int *index, int *printed_chars)
{
	init(flags);
	*index = 0;
	*printed_chars = 0;
}
