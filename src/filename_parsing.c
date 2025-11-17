/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 17:21:19 by sel-khao          #+#    #+#             */
/*   Updated: 2025/11/17 15:41:49 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_valid_filename(char *filename)
{
	size_t	len;

	if (!filename)
		return (0);
	if (ft_strlen(filename) < 4)
		return (0);
	len = ft_strlen(filename) - 4;
	if (ft_strncmp(filename + len, ".cub", 4) != 0)
		return (0);
	return (1);
}

/// check if the filename is a directory
int	is_directory(char *filename)
{
	int	fd;

	fd = open(filename, O_DIRECTORY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

int	is_valid_file(char *filename)
{
	int	fd;
	if (!is_valid_filename(filename))
		return (ft_printf("Invalid file format\n"), 0);
	//fd = open(filename, O_RDONLY);
	//if (fd < 0)
	//	return (ft_printf("Cannot open file: %s\n", filename), 0);
	if (is_directory(filename))
		return (ft_printf("Directory instead of file provided\n"), 0);
	//close (fd);
	return (1);
}
