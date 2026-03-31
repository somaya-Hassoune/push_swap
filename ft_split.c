/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shassoun <shassoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:10:59 by shassoun          #+#    #+#             */
/*   Updated: 2024/04/07 02:24:07 by shassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i] != c && str[i])
			count++;
		while (str[i] != c && str[i])
			i++;
	}
	return (count);
}

static char	*ft_strndup(const char *s1, int n)
{
	int		i;
	char	*s;

	i = 0;
	s = (char *)malloc(sizeof(char) * (n + 1));
	if (s == NULL)
		return (NULL);
	while (n)
	{
		s[i] = s1[i];
		i++;
		n--;
	}
	s[i] = '\0';
	return (s);
}

static char	**free_memorry(char **st, int j)
{
	while (j > 0)
	{
		free(st[j - 1]);
		j--;
	}
	free(st);
	return (NULL);
}

static char	**populate_result(char **st, const char *s, char c)
{
	int	i;
	int	start;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		start = i;
		while ((s[i] != c) && s[i])
			i++;
		if (i > start)
		{
			st[j] = ft_strndup(s + start, i - start);
			if (st[j] == NULL)
			{
				return (free_memorry(st, j));
			}
			j++;
		}
	}
	st[j] = NULL;
	return (st);
}

char	**ft_split(const char *s, char c)
{
	int		words;
	char	**st;

	if (s == NULL)
		return (NULL);
	words = count_words(s, c);
	st = (char **)malloc(sizeof(char *) * (words + 1));
	if (st == NULL)
		return (NULL);
	return (populate_result(st, s, c));
}
