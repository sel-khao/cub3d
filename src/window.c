/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:23:27 by sel-khao          #+#    #+#             */
/*   Updated: 2025/09/23 18:41:19 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	place_img(t_config *config)
{
	config->no = creat_textu(config->map, "textur/no.xpm", config);
    config->ea = creat_textu(config->map, "textur/ea.xpm", config);
    config->so = creat_textu(config->map, "textur/so.xpm", config);
    config->we = creat_textu(config->map, "textur/we.xpm", config);
	config->floor = creat_textu(config->map, "textur/floor.xpm", config);
	config->ceiling = creat_textu(config->map, "textur/ceiling.xpm", config);
}
//to change
int	key_hook(int keycd, t_config *config)
{
	if (keycd == XK_w)
		mv_player(config, config->x, config->y -1);
	else if (keycd == XK_s)
		mv_player(config, config->x, config->y +1);
	else if (keycd == XK_a)
		mv_player(config, config->x - 1, config->y);
	else if (keycd == XK_d)
		mv_player(config, config->x + 1, config->y);
	else if (keycd == XK_Escape)
		cls_win(config);
	return (0);
}

int	img_check(char *file)
{
	int		fd;
	size_t	len;

	if (!file || ft_strlen(file) < 4)
		return (-1);
	len = ft_strlen(file) - 4;
	if (ft_strncmp(file + len, ".xpm", 4) != 0)
		return (-1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	return (fd);
}