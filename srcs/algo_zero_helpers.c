/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_zero_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 12:00:00 by salsoysa          #+#    #+#             */
/*   Updated: 2026/03/24 12:00:00 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*dict_zero_value(t_dict *dict)
{
	char	*value;

	value = lookup_value(dict, "0");
	if (!value)
		return (NULL);
	return (ft_strdup(value));
}

char	*consume_zero_input(char *trimmed, t_dict *dict)
{
	char	*result;

	if (!is_zero_value(trimmed))
		return (NULL);
	result = dict_zero_value(dict);
	free(trimmed);
	return (result);
}
