/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:25:45 by oel-hadr          #+#    #+#             */
/*   Updated: 2024/11/18 17:19:20 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	free_buffer(char **buffer)
{
	free(*buffer);
	*buffer = NULL;
}

static int	handle_left_align(unsigned int num, t_flags *flags)
{
	int		printed;
	char	*buffer;

	printed = 0;
	print_prefix(flags, &printed, num);
	buffer = ft_int_to_hex(num, flags->type);
	if (!buffer)
		return (-1);
	if ((size_t)flags->precision > ft_strlen(buffer))
		printed += print_zeros(flags->precision - ft_strlen(buffer));
	printed += put_buffer_reverse(buffer);
	if (flags->width)
		printed += print_space(flags->width - printed);
	free_buffer(&buffer);
	return (printed);
}

static int	calculate_min_length(unsigned int num, t_flags *flags, char *buffer)
{
	int	min_len;

	min_len = 0;
	if (flags->hash && num != 0)
		min_len += 2;
	if ((flags->precision && flags->given)
		&& (size_t)flags->precision > ft_strlen(buffer))
		min_len += flags->precision;
	else
		min_len += ft_strlen(buffer);
	return (min_len);
}

static int	handle_right_align(unsigned int num, t_flags *flags)
{
	int		printed;
	int		prefix;
	char	*buffer;

	printed = 0;
	buffer = ft_int_to_hex(num, flags->type);
	if (!buffer)
		return (-1);
	if (flags->width && !flags->zero)
		printed += print_space(flags->width \
		- calculate_min_length(num, flags, buffer));
	prefix = prefix_and_zeros(flags, &printed, num, buffer);
	if (!prefix)
		print_prefix(flags, &printed, num);
	if ((size_t)flags->precision > ft_strlen(buffer))
		printed += print_zeros(flags->precision - ft_strlen(buffer));
	printed += put_buffer_reverse(buffer);
	free_buffer(&buffer);
	return (printed);
}

int	ft_puthex_bonus(unsigned int num, t_flags *flags)
{
	int	printed;

	printed = 0;
	if ((flags->precision == -1 && num == 0)
		|| (!flags->precision && flags->given && num == 0))
	{
		printed += print_space(flags->width);
		return (printed);
	}
	if (flags->minus)
		printed = handle_left_align(num, flags);
	else
		printed = handle_right_align(num, flags);
	return (printed);
}
