/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aizsak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 08:19:00 by aizsak            #+#    #+#             */
/*   Updated: 2022/12/19 14:17:03 by aizsak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	pid_serveur;
char	message[BUFFER_SIZE];
int	message_index = 0;

void	signal_handler(int signal_number)
{
	if (signal_number == SIGUSR1)
	{
		message[message_index] = '1';
		message_index++;
	}
	else if (signal_number == SIGUSR2)
	{
		message[message_index] = '0';
		message_index++;
	}
}

int main(int argc, char** argv)
{
	if(argc < 3)
	{
		ft_printf("Utilisation : client <pid_serveur> <message>\n");
		return 1;
	}
	pid_serveur = ft_atoi(argv[1]);
	strncpy(message, argv[2], BUFFER_SIZE);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	for (int i = 0; i < ft_strlen1(message); i++)
	{
		if (message[i] == '1')
			kill(pid_serveur, SIGUSR1);
		else
			kill(pid_serveur, SIGUSR2);
		i++;
	}
	return 0;
}
