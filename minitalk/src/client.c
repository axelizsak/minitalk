/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aizsak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 08:19:00 by aizsak            #+#    #+#             */
/*   Updated: 2022/12/21 17:18:33 by aizsak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int *message, pid_t pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (message[i] == 1)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_printf("%s", "kill");
				exit(1);
			}
		}
		else if (message[i] == 0)
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_printf("%s", "kill");
				exit (1);
			}
		}
		i++;
		usleep(300);
	}
	free(message);
}

int	*encoder(char c)
{
	int	*message;
	int	i;
	int	decimal;

	message = malloc(sizeof(*message) * 8);
	if (!message)
	{
		ft_printf("%s", "erreur malloc");
		exit(1);
	}
	i = 7;
	decimal = (int)c;
	while (decimal)
	{
		message[i--] = decimal % 2;
		decimal /= 2;
	}
	while (i > -1)
		message[i--] = 0;
	return (message);
}

int	main(int argc, char **argv)
{
	int		*message;
	int		i;
	int		message_len;
	pid_t	server_pid;

	if (argc != 3)
	{
		ft_printf("Valid form : client <pid_serveur> <message>\n");
		return (1);
	}
	message_len = ft_strlen1(argv[2]);
	server_pid = ft_atoi(argv[1]);
	i = 0;
	while (i <= message_len)
	{
		message = encoder(argv[2][i]);
		send_signal(message, server_pid);
		i++;
	}
	return (0);
}
