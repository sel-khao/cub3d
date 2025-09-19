/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sara <sara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 08:36:59 by sel-khao          #+#    #+#             */
/*   Updated: 2025/09/19 18:41:00 by sara             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_config config;
	int i;

	initial(&config);
	if (argc == 2)
	{
		if (configure(argv[1], &config) == -1)
		{
			printf("Error: Configuration failed\n");
			return (1);
		}
		
		// Test texture paths
		printf("=== TEXTURES ===\n");
		printf("NO: %s\n", config.no ? config.no : "NULL");
		printf("SO: %s\n", config.so ? config.so : "NULL");
		printf("WE: %s\n", config.we ? config.we : "NULL");
		printf("EA: %s\n", config.ea ? config.ea : "NULL");
		
		// Test colors
		printf("\n=== COLORS ===\n");
		printf("Floor RGB: %d (R:%d G:%d B:%d)\n", 
			config.floor, 
			(config.floor >> 16) & 0xFF,
			(config.floor >> 8) & 0xFF,
			config.floor & 0xFF);
		printf("Ceiling RGB: %d (R:%d G:%d B:%d)\n", 
			config.ceiling,
			(config.ceiling >> 16) & 0xFF,
			(config.ceiling >> 8) & 0xFF,
			config.ceiling & 0xFF);
		
		// Test map
		printf("\n=== MAP ===\n");
		if (config.map)
		{
			i = 0;
			while (config.map[i])
			{
				printf("Line %d: '%s'\n", i, config.map[i]);
				i++;
			}
			printf("Total map lines: %d\n", i);
		}
		else
		{
			printf("Map is NULL\n");
		}
	}
	else
	{
		printf("Usage: %s <file.cub>\n", argv[0]);
	}
	return (0);
}


/*int	main(int argc, char **argv)
{
	t_config config;

	initial(&config);
	if (argc == 2)
	{
		configure(argv[1], &config);
		//fill_map;
	}
	return (0);
}*/