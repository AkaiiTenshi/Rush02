/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 12:00:00 by salsoysa          #+#    #+#             */
/*   Updated: 2026/03/24 12:00:00 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	is_all_digits(char *str)
{
	int	i;

	if (!str || str[0] == '\0')
		return (0);
	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

char	*append_with_space(char *result, char *new_part)
{
	char	*temp;
	char	*with_space;

	if (!new_part)
	{
		free(result);
		return (NULL);
	}
	if (!result || !result[0])
	{
		free(result);
		return (ft_strdup(new_part));
	}
	with_space = ft_strjoin(result, " ");
	if (!with_space)
	{
		free(result);
		return (NULL);
	}
	temp = ft_strjoin(with_space, new_part);
	free(with_space);
	free(result);
	return (temp);
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
