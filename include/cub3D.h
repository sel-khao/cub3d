/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sara <sara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:28:01 by plichota          #+#    #+#             */
/*   Updated: 2025/09/19 18:44:56 by sara             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef TILE
#  define TILE 64
# endif

# include "libft.h"
//# include "mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>

typedef struct s_config
{
	int		x;
	int		y;
	char	**map;
	char	*no;//texture
	char	*so;
	char	*we;
	char	*ea;
	int		floor;//color
	int		ceiling;
}	t_config;

char	*extract_path(char *line);
void	initial(t_config *config);
void	ft_free(char **str);
int		parse_rgb(char *line);
int		check_open(char *file);
int		configure(char *file, t_config *config);
int		count_line(char *file);
void	fill_map(char *file, t_config *config);

#endif