/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pnbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aizsak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 10:48:05 by aizsak            #+#    #+#             */
/*   Updated: 2022/12/11 10:49:26 by aizsak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pnbr(int n)
{
	long	ln;
	int		i;

	i = 0;
	ln = n;
	if (ln < 0)
	{
		i += ft_pchar('-');
		ln *= -1;
	}
	if (ln <= 9)
		i += ft_pchar(ln + '0');
	else
	{
		i += ft_pnbr(ln / 10);
		i += ft_pnbr(ln % 10);
	}
	return (i);
}
