/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shassoun <shassoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:19:39 by shassoun          #+#    #+#             */
/*   Updated: 2023/12/30 21:36:07 by shassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*end(char *save, char *buffer)
{
	free(buffer);
	free(save);
	return (NULL);
}

static char	*save_and_free(char *save, int fd)
{
	int		x;
	char	*buffer;

	x = 1;
	while (!ft_strchr(save, '\n'))
	{
		buffer = (char *)malloc(BUFFER_SIZE * (sizeof(char) + 1));
		if (buffer == NULL)
			return (NULL);
		x = read(fd, buffer, BUFFER_SIZE);
		if (x < 0)
			return (end(save, buffer));
		buffer[x] = '\0';
		if (x == 0 && (!save || save[0] == '\0'))
			return (end(save, buffer));
		if (x == 0)
		{
			free(buffer);
			break ;
		}
		save = ft_strjoin(save, buffer);
		free(buffer);
	}
	return (save);
}

static char	*put_in_line(int len, char *save)
{
	char	*ligne;
	int		j;

	j = 0;
	ligne = (char *)malloc(sizeof(char) * (len + 1));
	if (ligne == NULL)
		return (NULL);
	while (j < len)
	{
		ligne[j] = save[j];
		j++;
	}
	ligne[j] = '\0';
	return (ligne);
}

static char	*save_after(char *save, int len)
{
	char	*str;
	int		b;
	int		a;

	b = len;
	a = 0;
	while (save[len] != '\0')
	{
		len++;
		a++;
	}
	str = (char *)malloc(sizeof(char) * (a + 1));
	if (str == NULL)
		return (NULL);
	a = 0;
	while (save[b] != '\0')
	{
		str[a] = save[b];
		b++;
		a++;
	}
	str[a] = '\0';
	free(save);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*save[10240];
	char		*line;
	int			len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	len = 0;
	save[fd] = save_and_free(save[fd], fd);
	if (save[fd] == NULL)
		return (NULL);
	while (save[fd][len] && save[fd][len] != '\n')
		len++;
	if (save[fd][len] == '\n')
		len++;
	line = put_in_line(len, save[fd]);
	save[fd] = save_after(save[fd], len);
	return (line);
}
