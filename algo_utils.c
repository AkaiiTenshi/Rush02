/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 00:57:25 by salsoysa          #+#    #+#             */
/*   Updated: 2026/01/22 01:00:16 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*get_zero_value(t_dict *dict)
{
	char	*value;

	value = lookup_value(dict, 0);
	if (!value)
		return (NULL);
	return (ft_strdup(value));
}

char	*process_large_scale(unsigned long number, unsigned long scale,
		t_dict *dict, char *result)
{
	char	*part;

	part = convert_number(number / scale, dict);
	if (!part)
		return (free(result), NULL);
	result = append_part(result, part);
	free(part);
	return (result);
}

char	*process_remainder(unsigned long number, unsigned long scale,
		t_dict *dict, char *result)
{
	char	*part;

	part = convert_number(number % scale, dict);
	if (!part)
		return (free(result), NULL);
	result = append_part(result, part);
	free(part);
	return (result);
}
