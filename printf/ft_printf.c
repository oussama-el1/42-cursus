/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:33:29 by oel-hadr          #+#    #+#             */
/*   Updated: 2024/11/18 17:24:13 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_conversions(va_list args, t_flags *flags, int *printed_chars)
{
	int	format_type;
	int	prev;

	prev = *printed_chars;
	format_type = get_format_type(flags->type);
	if (format_type == FORMAT_TYPE_CHAR)
		*printed_chars += ft_putchar_bonus(va_arg(args, int), flags);
	else if (format_type == FORMAT_TYPE_STRING)
		*printed_chars += ft_putstr_bonus(va_arg(args, char *), flags);
	else if (format_type == FORMAT_TYPE_PTR)
		*printed_chars += ft_putptr_bonus(
				(unsigned long)va_arg(args, void *), flags);
	else if (format_type == FORMAT_TYPE_INT)
		*printed_chars += ft_putnbr_bonus(
				va_arg(args, int), flags);
	else if (format_type == FORMAT_TYPE_PERCENT)
		*printed_chars += put_percent(flags);
	else if (format_type == FORMAT_TYPE_HEXADECIMAL)
		*printed_chars += ft_puthex_bonus(va_arg(args, int), flags);
	else if (format_type == FORMAT_TYPE_UNSIGNED)
		*printed_chars += ft_putunigned_bonus(
				va_arg(args, unsigned int), flags);
	init(flags);
	return (*printed_chars == (prev - 1));
}

static int	iterate_format(const char *format, va_list args)
{
	int		index;
	int		printed_chars;
	t_flags	flags;

	ft_printf_init(&flags, &index, &printed_chars);
	while (format[index] != '\0')
	{
		if (format[index] == '%' && format[index + 1] == '\0')
			index++;
		else if (format[index] == '%'
			&& parsing_flag(format, &index, &flags, args))
		{
			if (handle_conversions(args, &flags, &printed_chars) == 1)
				return (-1);
			index++;
		}
		else
		{
			ft_putchar_fd(format[index], 1);
			printed_chars++;
			index++;
		}
	}
	return (printed_chars);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		printed_chars;

	if (write(1, "", 0) == -1)
		return (-1);
	va_start(args, format);
	printed_chars = iterate_format(format, args);
	va_end(args);
	return (printed_chars);
}
