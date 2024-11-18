/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 22:33:24 by oel-hadr          #+#    #+#             */
/*   Updated: 2024/11/18 17:23:32 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

# define FORMAT_TYPE_CHAR        1
# define FORMAT_TYPE_INT         2
# define FORMAT_TYPE_STRING      3
# define FORMAT_TYPE_HEXADECIMAL 4
# define FORMAT_TYPE_UNSIGNED    5
# define FORMAT_TYPE_PERCENT     6
# define FORMAT_TYPE_PTR         7

typedef struct s_flags
{
	char	type;
	int		minus;
	int		zero;
	int		width;
	int		precision;
	int		given;
	int		dot;
	int		hash;
	int		space;
	int		plus;
}	t_flags;

int		get_format_type(char format_specifier);
char	*ft_int_to_hex(unsigned long num, char c);
int		ft_printf(const char *format, ...);
void	init(t_flags *flags);
void	parse_width(const char *format, int *index,
			t_flags *flags, va_list args);
void	parse_precision(const char *format, int *index,
			t_flags *flags, va_list args);
int		parsing_flag(const char *format, int *index,
			t_flags *flags, va_list args);
int		get_width(const char *format, int *index);
int		ft_putchar_bonus(char c, t_flags *flags);
int		ft_putstr_bonus(const char *s, t_flags *flags);
int		ft_puthex_bonus(unsigned int num, t_flags *flags);
int		ft_putptr_bonus(unsigned long num, t_flags *flags);
int		ft_putnbr_bonus(int num, t_flags *flags);
int		ft_putunigned_bonus(unsigned int num, t_flags *flags);
int		put_percent(t_flags *flags);
//helpers
int		get_len_int(int num);
int		print_space(int width);
int		print_prefix(t_flags *flags, int *printed, int num);
int		print_zeros(int len);
int		put_buffer_reverse(char *s);
void	handle_sign(int num, char **buffer, t_flags *flags, int *printed);
int		handle_zero_precision(int num, t_flags *flags,
			char **original, int *printed);
char	*ft_itoa_unsigned(unsigned int n);
int		prefix_and_zeros(t_flags *flags, int *printed,
			unsigned int num, char *buffer);
void	ft_printf_init(t_flags *flags, int *index, int *printed_chars);

#endif
