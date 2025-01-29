/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-hadr <oel-hadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 00:27:35 by oel-hadr          #+#    #+#             */
/*   Updated: 2025/01/28 00:27:37 by oel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	reset_utf8_char(t_utf8_char *utf8_char)
{
	int	i;

	i = -1;
	while (++i < UTF8_MAX_BYTES)
		utf8_char->bytes[i] = 0;
	utf8_char->byte_count = 0;
	utf8_char->expected_bytes = 0;
}

int	get_utf8_length(unsigned char first_byte)
{
	if ((first_byte & 0x80) == 0)
		return (1);
	else if ((first_byte & 0xE0) == 0xC0)
		return (2);
	else if ((first_byte & 0xF0) == 0xE0)
		return (3);
	else if ((first_byte & 0xF8) == 0xF0)
		return (4);
	return (1);
}

void	process_byte(t_utf8_char *utf8_char, pid_t prev_client)
{
	unsigned char	current_byte;

	current_byte = utf8_char->bytes[utf8_char->byte_count];
	if (utf8_char->byte_count == 0)
		utf8_char->expected_bytes = get_utf8_length(current_byte);
	utf8_char->byte_count++;
	if (utf8_char->byte_count == utf8_char->expected_bytes)
	{
		if (utf8_char->bytes[0] == '\0')
		{
			if (kill(prev_client, SIGUSR1) == -1)
			{
				write(1, "Error: Failed to send acknowledgment\n", 37);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			write(1, utf8_char->bytes, utf8_char->byte_count);
		}
		reset_utf8_char(utf8_char);
	}
}

void	sig_handler(int sig, siginfo_t *info, void *context)
{
	static t_utf8_char	utf8_char = {{0}, 0, 0};
	static int			bit_count = 0;
	static pid_t		prev_client = 0;

	(void)context;
	check_client(&prev_client, info, &utf8_char, &bit_count);
	if (sig == SIGUSR1)
		utf8_char.bytes[utf8_char.byte_count] |= (1 << (7 - (bit_count % 8)));
	bit_count++;
	if (bit_count % 8 == 0)
		process_byte(&utf8_char, prev_client);
}

int	main(void)
{
	init_handler(SIGUSR1, sig_handler);
	init_handler(SIGUSR2, sig_handler);
	write(1, "Server PID: ", 12);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
