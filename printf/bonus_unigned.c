/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_unigned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:15:58 by oel-hadr          #+#    #+#             */
/*   Updated: 2024/11/18 16:14:33 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_left_align(t_flags *flags,
		char **buffer, int buffer_len)
{
	int	printed;

	printed = 0;
	if (flags->precision > buffer_len)
		printed += print_zeros(flags->precision - buffer_len);
	ft_putstr_fd(*buffer, 1);
	printed += buffer_len;
	printed += print_space(flags->width - printed);
	return (printed);
}

static int	handle_padding_and_sign(unsigned int num, t_flags *flags,
		char **buffer, int buffer_len)
{
	int	printed;
	int	sign;

	printed = 0;
	sign = 0;
	if ((flags->plus && num > 0) || (flags->space && num >= 0))
		sign = 1;
	if (flags->zero && !flags->precision)
	{
		handle_sign(num, buffer, flags, &printed);
		printed += print_zeros(flags->width - buffer_len - sign);
	}
	else
	{
		if (flags->precision > buffer_len)
			printed += print_space(flags->width - flags->precision);
		else
			printed += print_space(flags->width - buffer_len);
	}
	return (printed);
}

static int	handle_right_align(unsigned int num, t_flags *flags,
		char **buffer, int buffer_len)
{
	int	printed;

	printed = 0;
	printed += handle_padding_and_sign(num, flags, buffer, buffer_len);
	if (flags->precision > buffer_len)
		printed += print_zeros(flags->precision - buffer_len);
	ft_putstr_fd(*buffer, 1);
	printed += buffer_len;
	return (printed);
}

static int	without_align(t_flags *flags,
		char **buffer, int buffer_len)
{
	int	printed;

	printed = 0;
	if (flags->precision > buffer_len)
		printed += print_zeros(flags->precision - buffer_len);
	ft_putstr_fd(*buffer, 1);
	printed += buffer_len;
	return (printed);
}

int	ft_putunigned_bonus(unsigned int num, t_flags *flags)
{
	int		printed;
	int		buffer_len;
	char	*original;
	char	*buffer;

	printed = 0;
	original = ft_itoa_unsigned(num);
	if (!original)
		return (-1);
	buffer = original;
	buffer_len = ft_strlen(buffer);
	if (handle_zero_precision(num, flags, &original, &printed))
		return (printed);
	if (flags->width)
	{
		if (flags->minus)
			printed += handle_left_align(flags, &buffer, buffer_len);
		else
			printed += handle_right_align(num, flags, &buffer, buffer_len);
	}
	else
		printed += without_align(flags, &buffer, buffer_len);
	free(original);
	return (printed);
}
