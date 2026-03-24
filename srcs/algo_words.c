/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_words.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 12:00:00 by salsoysa          #+#    #+#             */
/*   Updated: 2026/03/24 12:00:00 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*number_to_words(char *number_str, t_dict *dict)
{
	char	*trimmed;
	char	**groups;
	char	*result;
	int		num_groups;

	if (is_zero_value(number_str))
		return (dict_zero_value(dict));
	trimmed = trim_leading_zeros(number_str);
	if (!trimmed)
		return (NULL);
	if (is_zero_value(trimmed))
		return (consume_zero_input(trimmed, dict));
	groups = split_into_groups(trimmed);
	free(trimmed);
	if (!groups)
		return (NULL);
	if (!check_scale_limit(groups, dict))
	{
		free_split(groups);
		return (NULL);
	}
	num_groups = count_split_groups(groups);
	result = process_groups(groups, num_groups, dict);
	free_split(groups);
	return (result);
}
