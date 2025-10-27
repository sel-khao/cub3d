/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 10:47:06 by sel-khao          #+#    #+#             */
/*   Updated: 2025/10/27 18:01:09 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_open(char *file)
{
	int		fd;
	size_t	len;

	if (!file || ft_strlen(file) < 4)
		return (-1);
	len = ft_strlen(file) - 4;
	if (ft_strncmp(file + len, ".cub", 4) != 0)
		return (-1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	return (fd);
}

//more or less 3 num X
//values outside 0-255
int parse_rgb(char *line)
{
	int		r;
	int		g;
	int		b;
	char	**split;
	char	*str;
	
	str = line + 2;
	while (*str == ' ')
		str++;
	split = ft_split(str, ',');
	if (!split || !split[0] || !split[1] || !split[2] || split[3])
		return (-1);
	r = ft_atoi(split[0]);
	g = ft_atoi(split[1]);
	b = ft_atoi(split[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		ft_free(split);
		return (-1);
	}
	ft_free(split);
	return ((r << 16) | (g << 8) | b);
}

//line = "NO ./path/to/texture.xpm\n"
char	*extract_path(char *line)
{
	int		i;
	int		j;
	char	*path;

	j = 0;
	i = 3;
	path = malloc(sizeof(char) * (ft_strlen(line) - 3 + 1));
	if (!path)
		return (NULL);
	while (line[i] && line[i] != '\n')
	{
		path[j] = line[i];
		i++;
		j++;
	}
	path[j] = '\0';
	return (path);
}

int	configure(char *file, t_config *config)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	if (check_open(file) < 0)
		return (write(2, "invalid file\n", 14), -1);
	fill_map(file, config);
	fd = open(file, O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		if (extract_path(line) == -1 || extract_path(line) == NULL)
			return (1);
		if (ft_strncmp(line, "NO ", 3) == 0)
		{
			if (config->no != NULL)
				return (3);//close fd, free line, free map, free paths
			config->no = extract_path(line);
		}
		else if (ft_strncmp(line, "SO ", 3) == 0)
		{
			if (config->so != NULL)
				return (3);//duplicate error
			config->so = extract_path(line);
		}
		else if (ft_strncmp(line, "WE ", 3) == 0)
		{
			if (config->we != NULL)
				return (3);
			config->we = extract_path(line);
		}
		else if (ft_strncmp(line, "EA ", 3) == 0)
		{
			if (config->ea != NULL)
				return (3);
			config->ea = extract_path(line);	
		}
		else if (ft_strncmp(line, "F ", 2) == 0)
		{
			if (config->floor != -1)
				return (3);
			config->floor = parse_rgb(line);
		}
		else if (ft_strncmp(line, "C ", 2) == 0)
		{
			if (config->ceiling != -1)
				return (3);
			config->ceiling = parse_rgb(line);
		}	
		else if (line[0] && line[0] != '\n')
		{
			config->map[i] = remove_newline(ft_strdup(line));
			i++;
		}
		free(line);
	}
	if (config->ceiling == -1 || config->floor == -1 || config->no == NULL
		|| config->we == NULL || config->ea == NULL || config->so == NULL)//0,0,0,0 is valid tho
		return (4);//non existing error
	close (fd);
	return (0);
}
