/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_compare.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:50:00 by salsoysa          #+#    #+#             */
/*   Updated: 2026/01/22 16:50:00 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	compare_number_strings(char *n1, char *n2)
{
	int	len1;
	int	len2;

	if (!n1 || !n2)
		return (0);
	len1 = ft_strlen(n1);
	len2 = ft_strlen(n2);
	if (len1 < len2)
		return (-1);
	if (len1 > len2)
		return (1);
	return (ft_strcmp(n1, n2));
}

int	is_power_of_ten(char *str)
{
	int	i;

	if (!str || str[0] != '1')
		return (0);
	i = 1;
	while (str[i])
	{
		if (str[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

char	*trim_leading_zeros(char *str)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] == '0' && str[i + 1])
		i++;
	return (ft_strdup(str + i));
}
