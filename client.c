/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutahi <mboutahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:07:51 by mboutahi          #+#    #+#             */
/*   Updated: 2025/03/10 20:21:41 by mboutahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_sig(pid_t pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				write(2, "Error: Invalid PID\n", 19);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				write(2, "Error: Invalid PID\n", 19);
				exit(EXIT_FAILURE);
			}
		}
		usleep(100);
		i--;
	}
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	int		i;

	i = 0;
	if (argc != 3)
	{
		write(1, "Usage: ./client <PID> <message>\n", 33);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	if (ft_atoi(argv[1]) == 0)
	{
		write(2, "Error: Invalid PID\n", 19);
		exit(EXIT_FAILURE);
	}
	while (argv[2][i])
	{
		send_sig(server_pid, argv[2][i]);
		i++;
	}
	send_sig(server_pid, '\0');
	return (0);
}
