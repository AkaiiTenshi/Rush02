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

static int	ft_dup(char **newstr, char *str, char c, int len)
{
	int	d;
	int	u;
	int	p;

	d = 0;
	u = -1;
	while (++u < len)
	{
		while (str[d] == c && str[d])
			d++;
		p = 0;
		while (str[d + p] != c && str[d + p])
			p++;
		newstr[u] = (char *)malloc(sizeof(char) * (p + 1));
		if (!newstr[u])
		{
			ft_free(newstr, u);
			return (0);
		}
		p = 0;
		while (str[d] != c && str[d])
			newstr[u][p++] = str[d++];
		newstr[u][p] = '\0';
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		len;
	char	**newstr;

	if (!s)
		return (NULL);
	len = count_words((char *)s, c);
	newstr = (char **)malloc(sizeof(char *) * (len + 1));
	if (!newstr)
		return (NULL);
	if (!ft_dup(newstr, (char *)s, c, len))
		return (NULL);
	newstr[len] = NULL;
	return (newstr);
}
