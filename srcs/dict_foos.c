/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_foos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 22:40:00 by salsoysa          #+#    #+#             */
/*   Updated: 2026/01/21 22:40:00 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

t_dict	*create_empty_dictionary(void)
{
	t_dict	*dict;

	dict = malloc(sizeof(t_dict));
	if (!dict)
		return (NULL);
	dict->head = NULL;
	dict->size = 0;
	return (dict);
}

t_dict_pair	*create_entry(char *key, char *value)
{
	t_dict_pair	*entry;

	if (!value || !key)
		return (NULL);
	entry = malloc(sizeof(t_dict_pair));
	if (!entry)
		return (NULL);
	entry->key = ft_strdup(key);
	if (!entry->key)
		return (free(entry), NULL);
	entry->value = ft_strdup(value);
	if (!entry->value)
		return (free(entry->key), free(entry), NULL);
	entry->next = NULL;
	return (entry);
}

void	add_entry(t_dict *dict, t_dict_pair *entry)
{
	t_dict_pair	*current;

	if (!dict || !entry)
		return ;
	if (!dict->head)
	{
		dict->head = entry;
	}
	else
	{
		current = dict->head;
		while (current->next)
			current = current->next;
		current->next = entry;
	}
	dict->size++;
}

int	key_exists(t_dict *dict, char *key)
{
	t_dict_pair	*current;

	if (!dict || !key)
		return (0);
	current = dict->head;
	while (current)
	{
		if (ft_strcmp(current->key, key) == 0)
			return (1);
		current = current->next;
	}
	return (0);
}

void	free_dictionary(t_dict *dict)
{
	t_dict_pair	*current;
	t_dict_pair	*next;

	if (!dict)
		return ;
	current = dict->head;
	while (current)
	{
		next = current->next;
		free(current->key);
		free(current->value);
		free(current);
		current = next;
	}
	free(dict);
}
