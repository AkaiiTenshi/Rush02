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

static int	print_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	return (1);
}

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
	write(1, result, ft_strlen(result));
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
		return (print_error("Error\n"));
	parse_args(ac, av, &path, &nbr);
	if (!is_all_digits(nbr))
		return (print_error("Error\n"));
	dict = load_dictionary(path);
	if (!dict)
		return (print_error("Dict Error\n"));
	if (!process_number(nbr, dict))
	{
		free_dictionary(dict);
		return (print_error("Dict Error\n"));
	}
	free_dictionary(dict);
	return (0);
}
