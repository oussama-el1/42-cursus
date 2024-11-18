/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_char_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:41:24 by oel-hadr          #+#    #+#             */
/*   Updated: 2024/11/17 12:11:14 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_space(int width)
{
	int	i;
	int	printed;

	i = 0;
	printed = 0;
	while (i < width)
	{
		write(1, " ", 1);
		printed++;
		i++;
	}
	return (printed);
}

int	ft_putchar_bonus(char c, t_flags *flags)
{
	int	printed;

	printed = 0;
	if (flags->minus)
	{
		printed += write(1, &c, 1);
		printed += print_space(flags->width - 1);
	}
	else
	{
		printed += print_space(flags->width - 1);
		printed += write(1, &c, 1);
	}
	return (printed);
}

static void	ft_putspace(t_flags *flags, const char *s, int *printed)
{
	size_t	str_len;

	if (!s)
		s = "(null)";
	str_len = ft_strlen(s);
	if (flags->precision == -1 || (flags->given && flags->precision == 0))
		*printed += print_space(flags->width);
	else if (!flags->precision || (size_t)flags->precision > str_len)
		*printed += print_space(flags->width - str_len);
	else
		*printed += print_space(flags->width - flags->precision);
}

static void	ft_putstr_helper(t_flags *flags, const char *s, int *printed)
{
	size_t	str_len;

	if (!s)
		s = "(null)";
	str_len = ft_strlen(s);
	if (flags->precision == -1 || (flags->given && flags->precision == 0))
		return ;
	else if (!flags->given || (size_t)flags->precision > str_len)
		*printed += write(1, s, str_len);
	else if (flags->precision > 0)
		*printed += write(1, s, flags->precision);
}

int	ft_putstr_bonus(const char *s, t_flags *flags)
{
	int	printed;

	printed = 0;
	if (flags->minus)
	{
		ft_putstr_helper(flags, s, &printed);
		ft_putspace(flags, s, &printed);
	}
	else
	{
		ft_putspace(flags, s, &printed);
		ft_putstr_helper(flags, s, &printed);
	}
	return (printed);
}
