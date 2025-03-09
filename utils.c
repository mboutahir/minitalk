/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutahi <mboutahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:09:24 by mboutahi          #+#    #+#             */
/*   Updated: 2025/03/04 20:33:46 by mboutahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr(int n)
{
	char	total;

	if (n < 10 && n >= 0)
	{
		n = n + '0';
		write(1, &n, 1);
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		total = (n % 10) + '0';
		write(1, &total, 1);
	}
}

int	ft_atoi(const char *str)
{
	int	total;
	int	j;
	int	i;

	i = 0; 
	j = 1;
	total = 0;
	while (str[i] <= '9' && str[i] >= '0')
	{
		total = 10 * total +(str[i] - '0');
		i++;
	}
	return (total);
}
