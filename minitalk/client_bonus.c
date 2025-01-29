/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 00:26:55 by oel-hadr          #+#    #+#             */
/*   Updated: 2025/01/28 00:26:57 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_ack_received = 0;

void	ack_handler(int sig)
{
	if (sig == SIGUSR1)
		g_ack_received = 1;
}

void	send_char(int server_pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
		{
			if (kill(server_pid, SIGUSR1) == -1)
			{
				write(1, "Error: Failed to send SIGUSR1\n", 31);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (kill(server_pid, SIGUSR2) == -1)
			{
				write(1, "Error: Failed to send SIGUSR2\n", 31);
				exit(EXIT_FAILURE);
			}
		}
		usleep(300);
		i--;
	}
}

void	send_message(int server_pid, char *message)
{
	while (*message)
	{
		send_char(server_pid, *message);
		message++;
	}
	send_char(server_pid, '\0');
}

int	main(int argc, char **argv)
{
	int	server_pid;

	if (argc != 3)
	{
		write(1, "Usage: ./client [server PID] [message]\n", 39);
		return (EXIT_FAILURE);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
	{
		write(1, "Error: Invalid server PID\n", 27);
		return (EXIT_FAILURE);
	}
	signal(SIGUSR1, ack_handler);
	send_message(server_pid, argv[2]);
	write(1, "Message sent to server.\n", 25);
	while (!g_ack_received)
		pause();
	write(1, "Server received the message.\n", 30);
	return (EXIT_SUCCESS);
}
