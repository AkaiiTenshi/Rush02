/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:43:10 by salsoysa          #+#    #+#             */
/*   Updated: 2026/01/22 12:10:08 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*lookup_value(t_dict *dict, unsigned long key)
{
	t_dict_pair	*current;

	if (!dict)
		return (NULL);
	current = dict->head;
	while (current)
	{
		if (current->nbr == key)
			return (current->value);
		current = current->next;
	}
	return (NULL);
}

unsigned long	find_largest_key_below(t_dict *dict, unsigned long number)
{
	t_dict_pair		*current;
	unsigned long	best_key;
	int				found;

	if (!dict)
		return (0);
	best_key = 0;
	found = 0;
	current = dict->head;
	while (current)
	{
		if (current->nbr <= number && current->nbr > best_key)
		{
			best_key = current->nbr;
			found = 1;
		}
		current = current->next;
	}
	if (!found)
		return (0);
	return (best_key);
}

static char	*process_scale(unsigned long number, unsigned long scale,
		t_dict *dict)
{
	char	*result;

	result = ft_strdup("");
	if (!result)
		return (NULL);
	if (scale >= 100)
	{
		result = process_large_scale(number, scale, dict, result);
		if (!result)
			return (NULL);
	}
	result = append_part(result, lookup_value(dict, scale));
	if (!result)
		return (NULL);
	if (number % scale > 0)
	{
		result = process_remainder(number, scale, dict, result);
		if (!result)
			return (NULL);
	}
	return (result);
}

char	*convert_number(unsigned long number, t_dict *dict)
{
	unsigned long	scale;
	char			*value;

	if (number < 100)
	{
		value = lookup_value(dict, number);
		if (value)
			return (ft_strdup(value));
	}
	scale = find_largest_key_below(dict, number);
	if (scale == 0)
		return (NULL);
	return (process_scale(number, scale, dict));
}

char	*number_to_words(char *number_str, t_dict *dict)
{
	unsigned long	number;
	int				i;

	if (ft_strcmp(number_str, "0") == 0)
		return (get_zero_value(dict));
	i = 0;
	while (number_str[i] == '0')
		i++;
	if (number_str[i] == '\0')
		return (get_zero_value(dict));
	number = str_to_ulong(number_str + i);
	return (convert_number(number, dict));
}
