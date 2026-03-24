/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 00:20:38 by salsoysa          #+#    #+#             */
/*   Updated: 2026/01/22 00:20:49 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static void	ft_free(char **newstr, int u)
{
	while (u >= 0)
	{
		free(newstr[u]);
		u--;
	}
	free(newstr);
}

static int	count_words(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i])
			count++;
		while (str[i] != c && str[i])
			i++;
	}
	return (count);
}

static int	alloc_words(char const *s, char c, int len, char ***newstr)
{
	int	i;

	i = 0;
	*newstr = (char **)malloc(sizeof(char *) * (len + 1));
	if (!*newstr)
		return (0);
	while (i < len)
	{
		(*newstr)[i] = NULL;
		i++;
	}
	if (!fill_words(*newstr, (char *)s, c, len))
	{
		ft_free(*newstr, len - 1);
		return (0);
	}
	(*newstr)[len] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		len;
	char	**newstr;

	if (!s)
		return (NULL);
	len = count_words((char *)s, c);
	if (!alloc_words(s, c, len, &newstr))
		return (NULL);
	return (newstr);
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
