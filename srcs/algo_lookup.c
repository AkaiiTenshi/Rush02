/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_lookup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 12:00:00 by salsoysa          #+#    #+#             */
/*   Updated: 2026/03/24 12:00:00 by salsoysa         ###   ########.fr       */
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

char	*get_scale_name(int scale_index, t_dict *dict)
{
	char	key[50];
	int		i;

	if (scale_index == 0)
		return (NULL);
	key[0] = '1';
	key[1] = '\0';
	i = 0;
	while (i < scale_index * 3)
	{
		key[i + 1] = '0';
		key[i + 2] = '\0';
		i++;
	}
	return (lookup_value(dict, key));
}
