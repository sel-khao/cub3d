/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 16:56:55 by plichota          #+#    #+#             */
/*   Updated: 2025/11/17 12:00:54 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// se fallisce exit program + svuota win e mappa
void	parse_map(t_window *win)
{
	if (!win || !win->map)
		exit_program(win, "Map not found", 1);
	if (sign(win) == -1)
		exit_program(win, "Invalid characters in map", 1);
	if (find_player(win) != 1)
		exit_program(win, "Invalid number of players", 1);
	// if (validate_textures(win) == -1)  // questa puoi lasciarla commentata per ora
	//	exit_program(win, "Invalid textures", 1);
	if (check_wall(win) == -1)
		exit_program(win, "Map not closed by walls", 1);
	// if (validate_map_enclosed(win) == -1)  // flood fill - da implementare dopo
	//	exit_program(win, "Map not properly enclosed", 1);
}
