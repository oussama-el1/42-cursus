/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 20:56:43 by oel-hadr          #+#    #+#             */
/*   Updated: 2024/11/18 16:07:08 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_left_align(t_flags *flags, int *printed)
{
	*printed += write(1, "%", 1);
	*printed += print_space(flags->width - 1);
}

static void	handle_right_align(t_flags *flags, int *printed)
{
	if (flags->zero)
		*printed += print_zeros(flags->width - 1);
	else
		*printed += print_space(flags->width - 1);
	*printed += write(1, "%", 1);
}

int	put_percent(t_flags *flags)
{
	int	printed;

	printed = 0;
	if (flags->width)
	{
		if (flags->minus)
			handle_left_align(flags, &printed);
		else
			handle_right_align(flags, &printed);
	}
	else
		printed += write(1, "%", 1);
	return (printed);
}
