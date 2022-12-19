/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aizsak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:25:34 by aizsak            #+#    #+#             */
/*   Updated: 2022/12/11 12:29:24 by aizsak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_file(char *buff, int fd)
{
	char	*reader;
	int		i;

	reader = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!reader)
		return (NULL);
	i = 1;
	while (i > 0)
	{
		i = read(fd, reader, BUFFER_SIZE);
		if (i < 0)
		{
			free(reader);
			return (NULL);
		}
		reader[i] = '\0';
		buff = ft_strjoin_gnl(reader, buff);
		if (check(buff))
			break ;
	}
	free(reader);
	return (buff);
}

char	*get_line(char *buff)
{
	char	*str;
	int		i;

	i = 0;
	if (buff[i] == 0)
		return (NULL);
	str = malloc(sizeof(char) * ft_strlen2(buff) + 1);
	if (!str)
		return (NULL);
	while (buff[i] && buff[i] != '\n')
	{
		str[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
	{
		str[i] = '\n';
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*trimmed_buff(char *buff)
{
	char		*str;
	int			i;
	int			j;
	int			size;

	i = 0;
	j = 0;
	size = ft_strlen1(buff) - ft_strlen2(buff);
	if (!size)
	{
		free(buff);
		return (NULL);
	}
	str = malloc(sizeof (char) * (size + 1));
	if (!str)
		return (NULL);
	i = ft_strlen2(buff);
	while (buff[i])
		str[j++] = buff[i++];
	str[j] = 0;
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char		*buff;
	char			*str;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buff = get_file(buff, fd);
	if (!buff)
		return (NULL);
	str = get_line(buff);
	buff = trimmed_buff(buff);
	if (!str)
		free(buff);
	return (str);
}
