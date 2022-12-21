/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phexa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aizsak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:07:11 by aizsak            #+#    #+#             */
/*   Updated: 2022/12/11 10:49:11 by aizsak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_phexa(unsigned long n, const char type)
{
	int	i;

	i = 0;
	if (n == 0)
		i += ft_pchar('0');
	else if (n >= 16)
	{
		i += ft_phexa(n / 16, type);
		i += ft_phexa(n % 16, type);
	}
	else
	{
		if (n <= 9)
			i += ft_pchar(n + '0');
		else
		{
			if (type == 'x')
				i += ft_pchar(n - 10 + 'a');
			else if (type == 'X')
				i += ft_pchar(n - 10 + 'A');
		}
	}
	return (i);
}
