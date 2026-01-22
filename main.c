/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:43:05 by salsoysa          #+#    #+#             */
/*   Updated: 2026/01/21 22:40:00 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static t_dict	*load_dictionary(char *path)
{
	char	*file_content;
	t_dict	*dict;

	file_content = read_dict(path);
	if (!file_content)
		return (NULL);
	dict = parse_dictionary_content(file_content);
	free(file_content);
	return (dict);
}

static int	process_number(char *nbr, t_dict *dict)
{
	char	*result;

	result = number_to_words(nbr, dict);
	if (!result)
		return (0);
	ft_putstr_fd(result, 1);
	write(1, "\n", 1);
	free(result);
	return (1);
}

int	main(int ac, char **av)
{
	char	*path;
	char	*nbr;
	t_dict	*dict;

	if (ac != 2 && ac != 3)
		return (write(2, "Error\n", 6), 1);
	parse_args(ac, av, &path, &nbr);
	if (!validate_nbr(nbr))
		return (write(2, "Error\n", 6), 1);
	dict = load_dictionary(path);
	if (!dict)
		return (write(2, "Dict Error\n", 11), 1);
	if (!process_number(nbr, dict))
		return (free_dictionary(dict), write(2, "Dict Error\n", 11), 1);
	free_dictionary(dict);
	return (0);
}
