/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shassoun <shassoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:19:29 by shassoun          #+#    #+#             */
/*   Updated: 2024/03/20 01:16:39 by shassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen_(const char *theString)
{
	size_t	i;

	i = 0;
	if (theString == NULL)
		return (0);
	while (theString[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	s = (char *)malloc(sizeof(char) * (ft_strlen_(s1) + ft_strlen_(s2) + 1));
	if (s == NULL)
		return (NULL);
	while (i < ft_strlen_(s1))
	{
		s[i] = (s1)[i];
		i++;
	}
	while (j < ft_strlen_(s2))
	{
		s[i + j] = s2[j];
		j++;
	}
	s[i + j] = '\0';
	free(s1);
	return (s);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while ((s[i] != '\0') && (s[i] != (char)c))
	{
		i++;
	}
	if (s[i] == (char)c)
	{
		return ((char *)s + i);
	}
	return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

char	*ft_strdup(const char *source)
{
	char	*str;
	int		i;
	int		n;

	n = 0;
	i = 0;
	while (source[n])
		n++;
	str = (char *)malloc(sizeof(char) * (n + 1));
	if (str == NULL)
		return (NULL);
	while (source[i])
	{
		str[i] = source[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
