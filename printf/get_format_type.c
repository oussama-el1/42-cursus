/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 00:16:16 by oel-hadr          #+#    #+#             */
/*   Updated: 2024/11/17 01:38:40 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_format_type(char format_specifier)
{
	if (format_specifier == 'c')
		return (FORMAT_TYPE_CHAR);
	else if (format_specifier == 'd' || format_specifier == 'i')
		return (FORMAT_TYPE_INT);
	else if (format_specifier == 'p')
		return (FORMAT_TYPE_PTR);
	else if (format_specifier == 's')
		return (FORMAT_TYPE_STRING);
	else if (format_specifier == 'x' || format_specifier == 'X')
		return (FORMAT_TYPE_HEXADECIMAL);
	else if (format_specifier == 'u')
		return (FORMAT_TYPE_UNSIGNED);
	else
		return (FORMAT_TYPE_PERCENT);
}
