/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aizsak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:42:34 by aizsak            #+#    #+#             */
/*   Updated: 2022/11/10 19:19:32 by aizsak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dest1;
	char	*src1;

	if ((dest == src) || n == 0)
		return (dest);
	if (!dest && !src)
		return (0);
	dest1 = (char *)dest;
	src1 = (char *)src;
	while (n--)
		dest1[n] = src1[n];
	return (dest);
}
