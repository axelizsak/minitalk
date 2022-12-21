/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aizsak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 08:19:27 by aizsak            #+#    #+#             */
/*   Updated: 2022/12/21 17:40:56 by aizsak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_iterative_power(int nb, int power)
{
	int	i;

	i = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power > 0)
	{
		if (power % 2 == 1)
			i *= nb;
		nb *= nb;
		power /= 2;
	}
	return (i);
}

char	decoder(int *message)
{
	int	i;
	int	n;
	int	result;

	i = 0;
	n = 7;
	result = 0;
	while (i < 8)
	{
		result += message[i] * ft_iterative_power(2, n);
		i++;
		n--;
	}
	return ((char)result);
}

void	receive_signal(int signal)
{
	static int	i;
	char		c;
	static int	message[8];

	if (signal == SIGUSR1)
		message[i++] = 1;
	else if (signal == SIGUSR2)
		message[i++] = 0;
	if (i == 8)
	{
		c = decoder(message);
		write (1, &c, 1);
		i = 0;
		if (c == '\0')
			write (1, "\n", 1);
	}
}

int	main(void)
{
	ft_printf("%d\n", getpid());
	if (signal(SIGUSR1, receive_signal) == SIG_ERR)
	{
		ft_putstr_fd("signal", 1);
		exit(1);
	}
	if (signal(SIGUSR2, receive_signal) == SIG_ERR)
	{
		ft_putstr_fd("signal", 1);
		exit(1);
	}
	while (1)
	{
		signal(SIGUSR1, receive_signal);
		signal(SIGUSR2, receive_signal);
		pause();
	}
	return (0);
}
