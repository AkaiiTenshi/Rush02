/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_words_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 12:00:00 by salsoysa          #+#    #+#             */
/*   Updated: 2026/03/24 12:00:00 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*process_groups(char **groups, int num_groups, t_dict *dict)
{
	char	*group_words;
	char	*scale_name;
	char	*result;
	int		i;

	result = ft_strdup("");
	if (!result)
		return (NULL);
	i = 0;
	while (groups[i])
	{
		group_words = convert_group(groups[i], dict);
		if (group_words)
		{
			result = append_with_space(result, group_words);
			free(group_words);
			if (!result)
				return (NULL);
			if (num_groups - i - 1 > 0)
			{
				scale_name = get_scale_name(num_groups - i - 1, dict);
				result = append_with_space(result, scale_name);
				if (!result)
					return (NULL);
			}
		}
		i++;
	}
	return (result);
}

int	check_scale_limit(char **groups, t_dict *dict)
{
	int	num_groups;

	num_groups = count_split_groups(groups);
	if (get_scale_name(num_groups - 1, dict) == NULL && num_groups > 1)
		return (0);
	return (1);
}
