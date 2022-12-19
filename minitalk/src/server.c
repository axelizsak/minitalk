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

int	message_index = 0;
char	message[BUFFER_SIZE];

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

int	main(void)
{
	ft_printf("%i\n", getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
	{
		if (message_index > 0 && message[message_index - 1] == '\0')
		{
			ft_printf("Message recu : %s\n", message);
			message_index = 0;
			ft_memset(message, 0, BUFFER_SIZE);
		}
	}
	return (0);
}
