/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_pars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 22:40:00 by salsoysa          #+#    #+#             */
/*   Updated: 2026/03/24 12:00:00 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static void	free_parts(char **parts)
{
	if (!parts)
		return ;
	if (parts[0])
		free(parts[0]);
	if (parts[1])
		free(parts[1]);
	free(parts);
}

static char	**extract_parts(char *line, char *colon)
{
	char	**parts;

	parts = malloc(sizeof(char *) * 3);
	if (!parts)
		return (NULL);
	parts[1] = NULL;
	parts[0] = ft_substr(line, 0, colon - line);
	if (!parts[0])
	{
		free(parts);
		return (NULL);
	}
	parts[1] = ft_strtrim(parts[0], " \t\n\r");
	free(parts[0]);
	parts[0] = ft_strtrim(colon + 1, " \t\n\r");
	if (!parts[1] || !parts[0])
	{
		free_parts(parts);
		return (NULL);
	}
	parts[2] = NULL;
	return (parts);
}

static char	*entry_key(char **parts)
{
	if (!is_all_digits(parts[1]) || !parts[0][0])
		return (NULL);
	return (trim_leading_zeros(parts[1]));
}

static t_dict_pair	*build_entry(char **parts)
{
	char			*key;
	t_dict_pair		*entry;

	key = entry_key(parts);
	if (!key)
		return (NULL);
	entry = create_entry(key, parts[0]);
	free(key);
	return (entry);
}

static void	cleanup_dict_parse(t_dict *dict, char **lines)
{
	free_dictionary(dict);
	free_lines(lines);
}

t_dict_pair	*parse_dictionary_line(char *line)
{
	char			**parts;
	char			*colon;
	t_dict_pair		*entry;

	colon = ft_strchr(line, ':');
	if (!colon)
		return (NULL);
	parts = extract_parts(line, colon);
	if (!parts)
		return (NULL);
	entry = build_entry(parts);
	if (!entry)
	{
		free_parts(parts);
		return (NULL);
	}
	free_parts(parts);
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

	lines = NULL;
	dict = create_empty_dictionary();
	if (!dict)
		return (NULL);
	lines = ft_split(content, '\n');
	if (!lines)
	{
		free_dictionary(dict);
		return (NULL);
	}
	i = 0;
	while (lines[i])
	{
		if (!process_line(dict, lines[i]))
		{
			cleanup_dict_parse(dict, lines);
			return (NULL);
		}
		i++;
	}
	free_lines(lines);
	return (dict);
}
