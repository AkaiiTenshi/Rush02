/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_pars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 22:40:00 by salsoysa          #+#    #+#             */
/*   Updated: 2026/01/21 22:40:00 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	free_entry(t_dict_pair *entry)
{
	if (!entry)
		return ;
	if (entry->key)
		free(entry->key);
	if (entry->value)
		free(entry->value);
	free(entry);
}

static char	**parse_line_parts(char *line, char *colon)
{
	char	**parts;

	parts = malloc(sizeof(char *) * 3);
	if (!parts)
		return (NULL);
	parts[0] = ft_substr(line, 0, colon - line);
	if (!parts[0])
		return (free(parts), NULL);
	parts[1] = ft_strtrim(parts[0], " \t\n\r");
	free(parts[0]);
	if (!parts[1])
		return (free(parts), NULL);
	parts[0] = ft_strdup(colon + 1);
	if (!parts[0])
		return (free(parts[1]), free(parts), NULL);
	parts[2] = ft_strtrim(parts[0], " \t\n\r");
	free(parts[0]);
	if (!parts[2])
		return (free(parts[1]), free(parts), NULL);
	parts[0] = parts[2];
	return (parts);
}

t_dict_pair	*parse_dictionary_line(char *line)
{
	char			**parts;
	char			*colon;
	char			*key;
	t_dict_pair		*entry;

	colon = ft_strchr(line, ':');
	if (!colon)
		return (NULL);
	parts = parse_line_parts(line, colon);
	if (!parts)
		return (NULL);
	if (!is_all_digits(parts[1]) || !parts[0][0])
		return (free(parts[0]), free(parts[1]), free(parts), NULL);
	key = trim_leading_zeros(parts[1]);
	entry = create_entry(key, parts[0]);
	free(key);
	free(parts[0]);
	free(parts[1]);
	free(parts);
	return (entry);
}

static int	process_line(t_dict *dict, char *line)
{
	t_dict_pair	*entry;

	if (is_empty_line(line))
		return (1);
	entry = parse_dictionary_line(line);
	if (!entry)
		return (0);
	if (key_exists(dict, entry->key))
	{
		free_entry(entry);
		return (0);
	}
	add_entry(dict, entry);
	return (1);
}

t_dict	*parse_dictionary_content(char *content)
{
	t_dict	*dict;
	char	**lines;
	int		i;

	dict = create_empty_dictionary();
	if (!dict)
		return (NULL);
	lines = ft_split(content, '\n');
	if (!lines)
		return (free_dictionary(dict), NULL);
	i = 0;
	while (lines[i])
	{
		if (!process_line(dict, lines[i]))
			return (free_dictionary(dict), free_lines(lines), NULL);
		i++;
	}
	free_lines(lines);
	return (dict);
}
