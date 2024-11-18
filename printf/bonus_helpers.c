/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:48:13 by oel-hadr          #+#    #+#             */
/*   Updated: 2024/11/16 18:46:16 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	get_width(const char *format, int *index)
{
	char	buffer[12];
	int		i;
	int		temp_index;

	i = 0;
	temp_index = *index;
	while (format[temp_index] != '\0' && ft_isdigit(format[temp_index]))
	{
		buffer[i] = format[temp_index];
		i++;
		temp_index++;
	}
	buffer[i] = '\0';
	*index = temp_index - 1;
	if (!ft_strlen(buffer))
		return (-1);
	return (ft_atoi(buffer));
}

void	parse_width(const char *format, int *index,
			t_flags *flags, va_list args)
{
	if (format[*index] == '*')
	{
		flags->width = va_arg(args, int);
		if (flags->width < 0)
		{
			flags->minus = 1;
			flags->width *= -1;
			flags->zero = 0;
		}
		return ;
	}
	flags->width = get_width(format, index);
}

void	parse_precision(const char *format,
			int *index, t_flags *flags, va_list args)
{
	int	arg;

	if (format[*index + 1] == '*')
	{
		arg = va_arg(args, int);
		flags->precision = arg;
		*index = *index + 1;
		return ;
	}
	*index = *index + 1;
	flags->precision = get_width(format, index);
	if (flags->precision != -1)
		flags->given = 1;
}

void	check_flags(const char *format, int *temp_index,
			t_flags *flags, va_list args)
{
	if (format[*temp_index] == '-')
	{
		flags->minus = 1;
		flags->zero = 0;
	}
	else if (format[*temp_index] == '0'
		&& !flags->minus && !flags->precision)
		flags->zero = 1;
	else if (format[*temp_index] == '#')
		flags->hash = 1;
	else if (format[*temp_index] == ' ' && !flags->plus)
		flags->space = 1;
	else if (format[*temp_index] == '+')
	{
		flags->plus = 1;
		flags->space = 0;
	}
	else if (ft_isdigit(format[*temp_index])
		|| format[*temp_index] == '*')
		parse_width(format, temp_index, flags, args);
	else if (format[*temp_index] == '.')
	{
		parse_precision(format, temp_index, flags, args);
		flags->zero = 0;
	}
}

int	parsing_flag(const char *format, int *index, t_flags *flags, va_list args)
{
	int	temp_index;

	temp_index = *index + 1;
	while (format[temp_index] != '\0'
		&& !ft_strchr("cspdiuxX%", format[temp_index]))
	{
		check_flags(format, &temp_index, flags, args);
		temp_index++;
	}
	if (format[temp_index] != '\0')
	{
		flags->type = format[temp_index];
		*index = temp_index;
		return (1);
	}
	*index = temp_index;
	return (0);
}
