/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:15:37 by sel-khao          #+#    #+#             */
/*   Updated: 2025/11/17 15:03:47 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	cleaning(t_window *win, char *line, int fd, char *error_msg)
{
	free(line);
	close(fd);
	//free(error_msg);
	exit_program(win, error_msg, 1);
}

void	ft_free_mtx(char **mtx)
{
	int	i;

	i = 0;
	if (!mtx)
		return ;
	while (mtx[i])
	{
		free(mtx[i]);
		i++;
	}
	free(mtx);
}

void	free_win(t_window *win)
{
	if (win->path_no)
	{
		free(win->path_no);
		win->path_no = NULL;
	}
	if (win->path_so)
	{
		free(win->path_so);
		win->path_so = NULL;
	}
	if (win->path_ea)
	{
		free(win->path_ea);
		win->path_ea = NULL;
	}
	if (win->path_we)
	{
		free(win->path_we);
		win->path_we = NULL;
	}
	if (win->map)
	{
		ft_free_mtx(win->map);
		win->map = NULL;
	}
}


