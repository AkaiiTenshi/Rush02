/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 00:57:25 by salsoysa          #+#    #+#             */
/*   Updated: 2026/01/22 17:01:00 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*get_zero_value(t_dict *dict)
{
	char	*value;

	value = lookup_value(dict, "0");
	if (!value)
		return (NULL);
	return (ft_strdup(value));
}

char	*process_large_scale(char *number, char *scale, t_dict *dict,
		char *result)
{
	char	*quotient;
	char	*part;

	quotient = divide_by_power_of_10(number, scale);
	if (!quotient)
		return (free(result), NULL);
	part = convert_number(quotient, dict);
	free(quotient);
	if (!part)
		return (free(result), NULL);
	result = append_part(result, part);
	free(part);
	return (result);
}

static int	is_remainder_zero(char *remainder)
{
	int	i;

	if (!remainder)
		return (1);
	i = 0;
	while (remainder[i])
	{
		if (remainder[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

char	*process_remainder(char *number, char *scale, t_dict *dict,
		char *result)
{
	char	*remainder;
	char	*part;

	if (is_power_of_ten(scale))
		remainder = modulo_by_power_of_10(number, scale);
	else
		remainder = subtract_strings(number, scale);
	if (!remainder)
		return (free(result), NULL);
	if (is_remainder_zero(remainder))
		return (free(remainder), result);
	part = convert_number(remainder, dict);
	free(remainder);
	if (!part)
		return (free(result), NULL);
	result = append_part(result, part);
	free(part);
	return (result);
}
