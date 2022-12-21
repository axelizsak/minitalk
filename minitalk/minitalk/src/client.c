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
#include <stdio.h>

void send_signal(int signum, pid_t pid)
{
    if (kill(pid, signum) == -1)
    {
        perror("kill");
        exit(1);
    }
}

int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		ft_printf("Utilisation : client <pid_serveur> <message>\n");
		return 1;
	}
	pid_t server_pid = ft_atoi(argv[1]);
	char* message = argv[2];
	int message_len = ft_strlen1(message);
	for (int i = 0; i < message_len; i++)
	{
		send_signal((message[i] == '1') ? SIGUSR1 : SIGUSR2, server_pid);
		usleep(100000);
	}
	send_signal(SIGUSR1, server_pid);
	return 0;
}
