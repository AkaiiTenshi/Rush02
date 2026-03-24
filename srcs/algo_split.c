/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 12:00:00 by salsoysa          #+#    #+#             */
/*   Updated: 2026/03/24 12:00:00 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	calc_num_groups(char *nbr)
{
	return ((ft_strlen(nbr) + 2) / 3);
}

static char	**allocate_groups(int num_groups)
{
	char	**groups;

	groups = malloc(sizeof(char *) * (num_groups + 1));
	if (!groups)
		return (NULL);
	groups[num_groups] = NULL;
	return (groups);
}

static int	fill_groups(char **groups, char *nbr, int num_groups, int start)
{
	int	i;

	groups[0] = ft_substr(nbr, 0, start);
	if (!groups[0])
		return (0);
	i = 1;
	while (i < num_groups)
	{
		groups[i] = ft_substr(nbr, start + (i - 1) * 3, 3);
		if (!groups[i])
			return (0);
		i++;
	}
	return (1);
}

static int	first_group_len(char *nbr)
{
	int	start;

	start = ft_strlen(nbr) % 3;
	if (start == 0)
		start = 3;
	return (start);
}

char	**split_into_groups(char *nbr)
{
	char	**groups;
	int		start;
	int		num_groups;

	num_groups = calc_num_groups(nbr);
	groups = allocate_groups(num_groups);
	if (!groups)
		return (NULL);
	start = first_group_len(nbr);
	if (!fill_groups(groups, nbr, num_groups, start))
	{
		free_split(groups);
		return (NULL);
	}
	return (groups);
}
