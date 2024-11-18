/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_helpers2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:17:51 by oel-hadr          #+#    #+#             */
/*   Updated: 2024/11/16 23:01:37 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_zeros(int len)
{
	int	i;
	int	printed;

	i = 0;
	printed = 0;
	while (i < len)
	{
		write(1, "0", 1);
		printed++;
		i++;
	}
	return (printed);
}

int	put_buffer_reverse(char *s)
{
	int	i;
	int	len;

	len = ft_strlen(s);
	i = len - 1;
	while (i >= 0)
	{
		write(1, &s[i], 1);
		i--;
	}
	return (len);
}

void	handle_sign(int num, char **buffer, t_flags *flags, int *printed)
{
	if (flags->plus && num >= 0)
		*printed += write(1, "+", 1);
	else if (flags->space && num >= 0)
		*printed += write(1, " ", 1);
	if (**buffer == '-')
	{
		write(1, "-", 1);
		(*buffer)++;
	}
}

void	handle_sign_in_zero_precision(int num, t_flags *flags,
	char **original, int *printed)
{
	if (flags->minus)
	{
		if (flags->plus && num >= 0)
			*printed += write(1, "+", 1);
		else if (flags->space && num >= 0)
			*printed += write(1, " ", 1);
	}
	free(*original);
	if (flags->width > 0)
		*printed += print_space(flags->width
				- (flags->plus || flags->space));
	if (!flags->minus)
	{
		if (flags->plus && num >= 0)
			*printed += write(1, "+", 1);
		else if (flags->space && num >= 0)
			*printed += write(1, " ", 1);
	}
}

int	handle_zero_precision(int num, t_flags *flags,
	char **original, int *printed)
{
	if (num == 0)
	{
		if ((flags->given && !flags->precision)
			|| (!flags->given && flags->precision == -1))
		{
			handle_sign_in_zero_precision(num, flags, original, printed);
			return (1);
		}
	}
	return (0);
}
