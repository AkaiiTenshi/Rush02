/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 22:36:24 by salsoysa          #+#    #+#             */
/*   Updated: 2026/01/22 15:53:47 by salsoysa         ###   ########.fr       */
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

unsigned long	str_to_ulong(char *str)
{
	unsigned long long	result;
	int				i;

	if (!str)
		return (0);
	result = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

char	*join_with_space(char *s1, char *s2)
{
	char	*temp;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	temp = ft_strjoin(s1, " ");
	if (!temp)
		return (NULL);
	result = ft_strjoin(temp, s2);
	free(temp);
	return (result);
}

char	*append_part(char *result, char *new_part)
{
	char	*temp;

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
	temp = join_with_space(result, new_part);
	free(result);
	return (temp);
}
