/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 10:47:06 by sel-khao          #+#    #+#             */
/*   Updated: 2025/11/17 15:38:34 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// line = "NO ./path/to/texture.xpm\n"
// TO DO check if the path is valid
char	*extract_path(char *line)
{
	int		i;
	int		j;
	char	*path;

	i = 2;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	j = 0;
	path = malloc(sizeof(char) * (ft_strlen(line + i) + 1));
	if (!path)
		return (NULL);
	while (line[i] && line[i] != '\n' && line[i] != ' ')
	{
		path[j] = line[i];
		i++;
		j++;
	}
	path[j] = '\0';
	return (path);
}

// Funzione helper per parsing singola texture
static void	parse_texture(t_window *win, char *line, int fd, char *id)
{
	char	**target;
	char	*name;
	char	*msg;

	if (ft_strncmp(id, "NO", 2) == 0)
		target = &win->path_no;
	else if (ft_strncmp(id, "SO", 2) == 0)
		target = &win->path_so;
	else if (ft_strncmp(id, "WE", 2) == 0)
		target = &win->path_we;
	else
		target = &win->path_ea;
	name = ft_strjoin(id, " texture");
	if (*target != NULL)
	{
		msg = ft_strjoin("Duplicate ", id);
		cleaning(win, line, fd, msg);
	}
	*target = extract_path(line);
	if (*target == NULL || !check_texture(*target))
	{
		msg = ft_strjoin("Invalid texture path:", id);
		cleaning(win, line, fd, msg);
	}
	free(name);
}

// Funzione helper per parsing colore
static void	parse_color(t_window *win, char *line, int fd, int is_floor)
{
	int		*rgb;
	int		*flag;
	char	*name;
	char	*msg;

	if (is_floor)
	{
		rgb = &win->rgb_floor;
		flag = &win->floor_set;
		name = "Floor";
	}
	else
	{
		rgb = &win->rgb_ceiling;
		flag = &win->ceiling_set;
		name = "Ceiling";
	}
	if (*flag)
	{
		msg = ft_strjoin("Duplicate ", name);
		cleaning(win, line, fd, msg);
	}
	*rgb = parse_rgb(line);
	if (*rgb < 0)
	{
		msg = ft_strjoin("Invalid ", name);
		cleaning(win, line, fd, msg);
	}
	*flag = 1;
}

static void	process_line(t_window *win, char *line, int fd)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		parse_texture(win, line, fd, "NO");
	else if (ft_strncmp(line, "SO ", 3) == 0)
		parse_texture(win, line, fd, "SO");
	else if (ft_strncmp(line, "WE ", 3) == 0)
		parse_texture(win, line, fd, "WE");
	else if (ft_strncmp(line, "EA ", 3) == 0)
		parse_texture(win, line, fd, "EA");
	else if (ft_strncmp(line, "F ", 2) == 0)
		parse_color(win, line, fd, 1);
	else if (ft_strncmp(line, "C ", 2) == 0)
		parse_color(win, line, fd, 0);
}

int	parse_paths(t_window *win, char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_program(win, "Error in file opening", 1);
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] != '\n' && line[0] != '\0')
			process_line(win, line, fd);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (!win->path_no || !win->path_so || !win->path_we || !win->path_ea
		|| !win->floor_set || !win->ceiling_set)
		exit_program(win, "Missing configuration", 1);
	return (0);
}