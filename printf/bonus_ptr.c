/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:00:09 by oel-hadr          #+#    #+#             */
/*   Updated: 2024/11/18 16:33:07 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_left_align(char *buffer, t_flags *flags, int *printed)
{
	print_prefix(flags, printed, 1);
	*printed += put_buffer_reverse(buffer);
	if (*printed < flags->width)
		*printed += print_space(flags->width - *printed);
	return (*printed);
}

static int	handle_right_align(char *buffer, t_flags *flags, int *printed)
{
	*printed += print_space(flags->width - ft_strlen(buffer) - 2);
	print_prefix(flags, printed, 1);
	*printed += put_buffer_reverse(buffer);
	return (*printed);
}

static int	handle_no_width(char *buffer, t_flags *flags, int *printed)
{
	print_prefix(flags, printed, 1);
	*printed += put_buffer_reverse(buffer);
	return (*printed);
}

int	ft_putptr_bonus(unsigned long num, t_flags *flags)
{
	char	*buffer;
	int		printed;

	printed = 0;
	buffer = ft_int_to_hex(num, 'x');
	if (!buffer)
		return (-1);
	if (flags->minus)
		handle_left_align(buffer, flags, &printed);
	else if (flags->width)
		handle_right_align(buffer, flags, &printed);
	else
		handle_no_width(buffer, flags, &printed);
	free(buffer);
	buffer = NULL;
	return (printed);
}
