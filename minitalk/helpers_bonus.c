/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 00:27:00 by oel-hadr          #+#    #+#             */
/*   Updated: 2025/01/28 00:51:33 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	init_handler(int sig, void (*f)(int, siginfo_t *, void *))
{
	struct sigaction	sa;

	sa.sa_sigaction = f;
	sa.sa_flags = SA_SIGINFO | SA_NODEFER | SA_RESTART;
	sigemptyset(&sa.sa_mask);
	if (sig == SIGUSR1)
	{
		if (sigaction(SIGUSR1, &sa, NULL) == -1)
		{
			write(1, "Error: Failed to register signal handler\n", 42);
			exit(EXIT_FAILURE);
		}
	}
	else if (sig == SIGUSR2)
	{
		if (sigaction(SIGUSR2, &sa, NULL) == -1)
		{
			write(1, "Error: Failed to register signal handler\n", 42);
			exit(EXIT_FAILURE);
		}
	}
}

void	check_client(pid_t *pid, siginfo_t *info,
		t_utf8_char *utf8_char, int *bit_count)
{
	if (*pid == 0 || *pid != info->si_pid)
	{
		*pid = info->si_pid;
		reset_utf8_char(utf8_char);
		*bit_count = 0;
	}
	if (kill(*pid, 0) == -1)
	{
		write(1, "Error: client is not responding\n", 33);
		exit(EXIT_FAILURE);
	}
}

void	ft_putnbr_fd_recursion(int n, int fd)
{
	char	digit;

	if (n > 9)
		ft_putnbr_fd_recursion(n / 10, fd);
	digit = (n % 10) + '0';
	write(fd, &digit, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		if (n == -2147483648)
		{
			write(fd, "2", 1);
			n = 147483648;
		}
		else
			n = -n;
	}
	ft_putnbr_fd_recursion(n, fd);
}
