/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:30:48 by oel-hadr          #+#    #+#             */
/*   Updated: 2025/01/27 22:56:54 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <limits.h>

# define UTF8_MAX_BYTES 4

typedef struct s_utf8_char
{
	unsigned char	bytes[UTF8_MAX_BYTES];
	int				byte_count;
	int				expected_bytes;
}	t_utf8_char;

void	reset_utf8_char(t_utf8_char *utf8_char);
int		get_utf8_length(unsigned char first_byte);
void	process_byte(t_utf8_char *utf8_char, pid_t prev_client);
void	sig_handler(int sig, siginfo_t *info, void *context);
int		ft_atoi(const char *nptr);
void	ft_putnbr_fd(int n, int fd);
void	ft_putnbr_fd_recursion(int n, int fd);
void	init_handler(int sig, void (*f)(int, siginfo_t *, void *));
void	check_client(pid_t *pid, siginfo_t *info,
			t_utf8_char *utf8_char, int *bit_count);
void	ack_handler(int sig);
void	send_char(int server_pid, char c);
void	send_message(int server_pid, char *message);

#endif
