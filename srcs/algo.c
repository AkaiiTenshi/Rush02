/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:43:10 by salsoysa          #+#    #+#             */
/*   Updated: 2026/01/23 13:27:21 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*lookup_value(t_dict *dict, char *key)
{
	t_dict_pair	*current;

	if (!dict || !key)
		return (NULL);
	current = dict->head;
	while (current)
	{
		if (ft_strcmp(current->key, key) == 0)
			return (current->value);
		current = current->next;
	}
	return (NULL);
}

char	*find_largest_key_below(t_dict *dict, char *number)
{
	t_dict_pair	*current;
	char		*best_key;

	if (!dict || !number)
		return (NULL);
	best_key = NULL;
	current = dict->head;
	while (current)
	{
		if (is_valid_scale(current->key) && compare_number_strings(current->key,
				number) <= 0)
		{
			if (!best_key || compare_number_strings(current->key, best_key) > 0)
				best_key = current->key;
		}
		current = current->next;
	}
	return (best_key);
}

static char	*process_scale(char *number, char *scale, t_dict *dict)
{
	char	*result;

	result = ft_strdup("");
	if (!result)
		return (NULL);
	if (ft_strlen(scale) >= 3)
	{
		result = process_large_scale(number, scale, dict, result);
		if (!result)
			return (NULL);
	}
	result = append_part(result, lookup_value(dict, scale));
	if (!result)
		return (NULL);
	result = process_remainder(number, scale, dict, result);
	return (result);
}

char	*convert_number(char *number, t_dict *dict)
{
	char	*scale;
	char	*value;

	value = lookup_value(dict, number);
	if (value)
		return (ft_strdup(value));
	scale = find_largest_key_below(dict, number);
	if (!scale)
		return (NULL);
	return (process_scale(number, scale, dict));
}

char	*number_to_words(char *number_str, t_dict *dict)
{
	char	*trimmed;
	char	*result;

	if (ft_strcmp(number_str, "0") == 0)
		return (get_zero_value(dict));
	trimmed = trim_leading_zeros(number_str);
	if (!trimmed)
		return (NULL);
	if (ft_strcmp(trimmed, "0") == 0)
	{
		free(trimmed);
		return (get_zero_value(dict));
	}
	result = convert_number(trimmed, dict);
	free(trimmed);
	return (result);
}
