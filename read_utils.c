/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:42:35 by salsoysa          #+#    #+#             */
/*   Updated: 2026/01/21 22:58:33 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	file_size(char *path)
{
	int		size;
	char	temp[1024];
	int		bytes;
	int		fd;

	size = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (1)
	{
		bytes = read(fd, temp, 1024);
		if (bytes < 0)
		{
			close(fd);
			return (-1);
		}
		if (bytes == 0)
			break ;
		size = size + bytes;
	}
	close(fd);
	return (size);
}

static char	*file_alloc(int fd, int size, int total_read)
{
	char	*file;
	int		bytes;

	file = malloc(sizeof(char) * (size + 1));
	if (!file)
	{
		close(fd);
		return (NULL);
	}
	while (total_read < size)
	{
		bytes = read(fd, file + total_read, size - total_read);
		if (bytes <= 0)
		{
			free(file);
			close(fd);
			return (NULL);
		}
		total_read += bytes;
	}
	close(fd);
	file[size] = '\0';
	return (file);
}

char	*read_dict(char *path)
{
	int		size;
	char	*file;
	int		fd;

	file = NULL;
	size = file_size(path);
	if (size < 0)
		return (NULL);
	if (size == 0)
	{
		file = malloc(1);
		if (!file)
			return (NULL);
		file[0] = '\0';
		return (file);
	}
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	file = file_alloc(fd, size, 0);
	return (file);
}
