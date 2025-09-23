/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:15:37 by sel-khao          #+#    #+#             */
/*   Updated: 2025/09/23 18:43:56 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	dest_img(t_config *config)
{
	if (config->floor)
		mlx_destroy_image(config->map, config->floor);
	if (config->ceiling)
		mlx_destroy_image(config->map, config->ceiling);
	if (config->ea)
		mlx_destroy_image(config->map, config->ea);
	if (config->so)
		mlx_destroy_image(config->map, config->so);
	if (config->we)
		mlx_destroy_image(config->map, config->we);
	if (config->no)
		mlx_destroy_image(config->map, config->no);
	dest_win(config);
}

void	dest_win(t_config *config)
{
	if (!config)
		return ;
	if (config->map)
		ft_free(config->map);
	if (config->map)
		ft_free(config-> map);
	if (config->map)
	{
		mlx_destroy_display(config->map);
		free(config->map);
	}
}

int	close_win(t_config *config)
{
	dest_img(config);
	exit(1);
	return (0);
}

void	ft_free(char **mxt)
{
	int	i;

	i = 0;
	if (!mxt)
		return ;
	while (mxt[i])
	{
		free(mxt[i]);
		i++;
	}
	free(mxt);
}
