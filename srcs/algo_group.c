/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_group.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 12:00:00 by salsoysa          #+#    #+#             */
/*   Updated: 2026/03/24 12:00:00 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static char	*convert_tens(char *group, t_dict *dict)
{
	char	*direct;
	char	*result;
	char	tens_key[3];
	char	ones_key[2];

	direct = lookup_value(dict, group);
	if (direct)
		return (ft_strdup(direct));
	tens_key[0] = group[0];
	tens_key[1] = '0';
	tens_key[2] = '\0';
	result = ft_strdup(lookup_value(dict, tens_key));
	if (!result)
		return (NULL);
	if (group[1] != '0')
	{
		ones_key[0] = group[1];
		ones_key[1] = '\0';
		result = append_with_space(result, lookup_value(dict, ones_key));
	}
	return (result);
}

static char	*convert_short_group(char *trimmed, t_dict *dict)
{
	char	*result;

	result = convert_tens(trimmed, dict);
	free(trimmed);
	return (result);
}

static char	*group_is_zero(char *trimmed)
{
	if (!is_zero_value(trimmed))
		return (NULL);
	free(trimmed);
	return (NULL);
}

char	*convert_group(char *group, t_dict *dict)
{
	char	*trimmed;
	char	*result;
	char	h_digit[2];
	char	remainder[3];

	trimmed = trim_leading_zeros(group);
	if (is_zero_value(trimmed))
		return (group_is_zero(trimmed));
	if (ft_strlen(trimmed) <= 2)
		return (convert_short_group(trimmed, dict));
	h_digit[0] = trimmed[0];
	h_digit[1] = '\0';
	result = ft_strdup(lookup_value(dict, h_digit));
	result = append_with_space(result, lookup_value(dict, "100"));
	remainder[0] = trimmed[1];
	remainder[1] = trimmed[2];
	remainder[2] = '\0';
	if (!is_zero_value(remainder))
		result = append_with_space(result, convert_tens(remainder, dict));
	free(trimmed);
	return (result);
}
