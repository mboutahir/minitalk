/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutahi <mboutahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:09:20 by mboutahi          #+#    #+#             */
/*   Updated: 2025/03/13 16:57:23 by mboutahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

pid_t	g_last_sender_pid = 0;

void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static int				bit_count = 0;
	static unsigned char	character = 0;

	(void) context;
	if (info->si_pid != g_last_sender_pid)
	{
		g_last_sender_pid = info->si_pid;
		bit_count = 0;
		character = 0;
	}
	if (sig == SIGUSR1)
		character |= (1 << (7 - bit_count));
	bit_count++;
	if (bit_count == 8)
	{
		write(1, &character, 1);
		bit_count = 0;
		character = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_putnbr (getpid());
	write(1, "\n", 1);
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
