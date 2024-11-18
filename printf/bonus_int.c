/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:27:18 by oel-hadr          #+#    #+#             */
/*   Updated: 2024/11/18 16:13:34 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_left_align(int num, t_flags *flags,
		char **buffer, int buffer_len)
{
	int	printed;

	printed = 0;
	if (flags->plus && num >= 0)
		printed += write(1, "+", 1);
	else if (flags->space && num >= 0)
		printed += write(1, " ", 1);
	if (**buffer == '-')
	{
		printed += write(1, "-", 1);
		(*buffer)++;
		buffer_len--;
	}
	if (flags->precision > buffer_len)
		printed += print_zeros(flags->precision - buffer_len);
	ft_putstr_fd(*buffer, 1);
	printed += buffer_len;
	printed += print_space(flags->width - printed);
	return (printed);
}

static int	handle_padding_and_sign(int num, t_flags *flags,
		char **buffer, int buffer_len)
{
	int	printed;
	int	sign;

	sign = 0;
	printed = 0;
	if ((flags->plus && num >= 0) || (flags->space && num >= 0))
		sign = 1;
	if (flags->zero && !flags->precision)
	{
		handle_sign(num, buffer, flags, &printed);
		printed += print_zeros(flags->width - buffer_len - sign);
	}
	else
	{
		if (flags->precision >= buffer_len)
		{
			printed += print_space(flags->width - flags->precision - sign
					- (**buffer == '-'));
		}
		else
			printed += print_space(flags->width - buffer_len - sign);
	}
	return (printed);
}

static int	handle_right_align(int num, t_flags *flags,
		char **buffer, int buffer_len)
{
	int	printed;

	printed = 0;
	printed += handle_padding_and_sign(num, flags, buffer, buffer_len);
	if (!flags->zero)
	{
		if (flags->plus && num >= 0)
			printed += write(1, "+", 1);
		else if (flags->space && num >= 0)
			printed += write(1, " ", 1);
	}
	if (flags->precision && **buffer == '-')
	{
		printed += write(1, "-", 1);
		(*buffer)++;
		buffer_len--;
	}
	if (flags->precision > buffer_len)
		printed += print_zeros(flags->precision - buffer_len);
	ft_putstr_fd(*buffer, 1);
	printed += buffer_len;
	return (printed);
}

static int	without_align(int num, t_flags *flags,
		char **buffer, int buffer_len)
{
	int	printed;

	printed = 0;
	if (flags->plus && num >= 0)
		printed += write(1, "+", 1);
	else if (flags->space && num >= 0)
		printed += write(1, " ", 1);
	if (flags->precision && **buffer == '-')
	{
		printed += write(1, "-", 1);
		(*buffer)++;
		buffer_len--;
	}
	if (flags->precision > buffer_len)
		printed += print_zeros(flags->precision - buffer_len);
	ft_putstr_fd(*buffer, 1);
	printed += buffer_len;
	return (printed);
}

int	ft_putnbr_bonus(int num, t_flags *flags)
{
	int		printed;
	int		buffer_len;
	char	*original;
	char	*buffer;

	printed = 0;
	original = ft_itoa(num);
	if (!original)
		return (-1);
	buffer = original;
	buffer_len = ft_strlen(buffer);
	if (handle_zero_precision(num, flags, &original, &printed))
		return (printed);
	if (flags->width)
	{
		if (flags->minus)
			printed += handle_left_align(num, flags, &buffer, buffer_len);
		else
			printed += handle_right_align(num, flags, &buffer, buffer_len);
	}
	else
		printed += without_align(num, flags, &buffer, buffer_len);
	free(original);
	return (printed);
}
