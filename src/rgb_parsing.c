/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:18:25 by sel-khao          #+#    #+#             */
/*   Updated: 2025/11/17 15:02:38 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_valid_rgb(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
//		while (str[i] == ' ' || str[i] == '\t')
//			i++;
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

// more or less 3 num X
// values outside 0-255
int	parse_rgb(char *line)
{
	int		r;
	int		g;
	int		b;
	char	**split;
	char	*str;

	str = line + 1; // skip F or C line
	while (*str == ' ')
		str++;
	split = ft_split(str, ',');
	if (!split || !split[0] || !split[1] || !split[2] || split[3] != NULL)
		return (ft_free_mtx(split), write(2, "RGB must have 3 values\n", 23), -1);
	if (!is_valid_rgb(split[0]) || !is_valid_rgb(split[1]) || !is_valid_rgb(split[2]))
		return (ft_free_mtx(split), write(2, "RGB must be numbers\n", 20), -1);
	r = ft_atoi(split[0]);
	g = ft_atoi(split[1]);
	b = ft_atoi(split[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		ft_free_mtx(split);
		return (write(2, "Error Rgb\n", 10), -1);
	}
	ft_free_mtx(split);
	return ((r << 16) | (g << 8) | b);
}
