/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:03:42 by sel-khao          #+#    #+#             */
/*   Updated: 2025/09/23 16:47:07 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	sign(t_config *config)
{
	int	i;
	int	j;

	i = 0;
	while (config->map[i])
	{
		j = 0;
		while (config->map[i][j])
		{
			if (config->map[i][j] == 'N' || config->map[i][j] == '0' || \
				config->map[i][j] == 'S' || config->map[i][j] == '1' || \
				config->map[i][j] == 'E' || config->map[i][j] == ' ' || \
				config->map[i][j] == 'W')
				j++;
			else
				return (-1);
		}
		i++;
	}
	return (-1);
}

char	*remove_newline(char *line)
{
	int	len;

	if (!line)
		return (NULL);
	len = ft_strlen(line);
	if (len > 0 && line[len -1] == '\n')
		line[len -1] = '\0';
	return (line);
}

int	set_hl(t_config *config)
{
	
}

int	check_wall(t_config *config)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	len = ft_strlen(config->map[0]) - 2;
	while (config->map[i])
	{
		j = 0;
		while (config->map[i][j] && config->map[i][j] != '\n')
		{
			if (i == 0 && config->map[i][j] != '1' && config->map[i][j] != ' ')
				return (-1);
			if ((i == config->h - 1) && config->map[i][j] != '1' && config->map[i][j] != ' ')
				return (-1);
			if (j == 0 && config->map[i][j] != '1' && config->map[i][j] != ' ')
				return (-1);
			if (j == len && config->map[i][j] != '1' && config->map[i][j] != ' ')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}
