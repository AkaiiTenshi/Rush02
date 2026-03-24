/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_copy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 12:00:00 by salsoysa          #+#    #+#             */
/*   Updated: 2026/03/24 12:00:00 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	word_len(char *str, char c)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	return (len);
}

static char	*dup_word(char *str, char c)
{
	char	*word;
	int		len;
	int		i;

	len = word_len(str, c);
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

int	fill_words(char **newstr, char *str, char c, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		while (*str == c && *str)
			str++;
		newstr[i] = dup_word(str, c);
		if (!newstr[i])
			return (0);
		str += word_len(str, c);
		i++;
	}
	return (1);
}
