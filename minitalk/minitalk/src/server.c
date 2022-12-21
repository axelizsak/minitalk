/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aizsak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 08:19:27 by aizsak            #+#    #+#             */
/*   Updated: 2022/12/19 13:58:26 by aizsak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

char	message[BUFFER_SIZE];
int	message_index = 0;

void	receive_signal(int signum)
{
	if (signum == SIGUSR1)
	{
		if (message_index == BUFFER_SIZE)
		{
			ft_memset(message, 0, BUFFER_SIZE);
			message_index = 0;
		}
		else
			message[message_index++] = '1';
	}
	else if (signum == SIGUSR2)
	{
		if (message_index == BUFFER_SIZE)
                {
                        ft_memset(message, 0, BUFFER_SIZE);
                        message_index = 0;
                }
                else
                        message[message_index++] = '0';
	}
}

int	main()
{
	ft_printf("%d\n", getpid());
	if (signal(SIGUSR1, receive_signal) == SIG_ERR)
	{
		perror("signal");
		exit(1);
	}
	if (signal(SIGUSR2, receive_signal) == SIG_ERR)
    	{
        	perror("signal");
        	exit(1);
    	}
	while (1)
	{
		pause();
		if (message_index > 0 && message[message_index - 1] == '1')
    		{
        		ft_printf("Message received: %s\n", message);
        		ft_memset(message, 0, BUFFER_SIZE);
        		message_index = 0;
    		}
	}
	return 0;
}
