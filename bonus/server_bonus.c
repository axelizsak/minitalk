/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aizsak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:27:43 by aizsak            #+#    #+#             */
/*   Updated: 2022/12/22 15:36:16 by aizsak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	signal_checker(int signum, siginfo_t *siginfo, void *ucontext)
{
	(void)ucontext;
	if (signum != SIGUSR1 && signum != SIGUSR2)
		exit(-1);
	if (siginfo->si_code != SI_USER)
		exit(-1);
}

static void	signal_handler(int signum, siginfo_t *siginfo, void *ucontext)
{
	static int	i;
	static char	c;

	signal_checker(signum, siginfo, ucontext);
	c <<= 1;
	i++;
	if (siginfo->si_signo == SIGUSR1)
		c += 1;
	if (siginfo->si_signo == SIGUSR2)
		c += 0;
	if (i == 8)
	{
		if (c != '\0')
			write (1, &c, 1);
		else if (c == '\0')
			write (1, "\n", 1);
		i = 0;
		c = 0;
	}
	kill(siginfo->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	signal_action;

	ft_printf("%d\n", getpid());
	signal_action.sa_sigaction = signal_handler;
	sigemptyset(&signal_action.sa_mask);
	signal_action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &signal_action, NULL);
	sigaction(SIGUSR2, &signal_action, NULL);
	while (1)
		pause();
	exit(0);
}
