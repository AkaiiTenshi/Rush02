/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:43:29 by salsoysa          #+#    #+#             */
/*   Updated: 2026/01/21 22:06:38 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include <fcntl.h>

void	parse_args(int ac, char **av, char **path, char **nbr)
{
	if (ac == 2)
	{
		*path = "rush02-numbers.dict";
		*nbr = av[1];
	}
	else if (ac == 3)
	{
		*path = av[1];
		*nbr = av[2];
	}
}

int	validate_nbr(char *nbr)
{
	int	i;

	if (!nbr || nbr[0] == '\0')
		return (0);
	i = 0;
	while (nbr[i])
	{
		if (nbr[i] < '0' || nbr[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
