/*
** growing_tree_utils.c for dante in /home/Rev/dante/dungeon
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Wed Apr	19 18:49:17 2017 Roméo Nahon
** Last update	Wed Apr	19 18:49:17 2017 Roméo Nahon
*/

#include "include/my.h"


void	resume_use(t_main *main)
{
	t_map *map;

	map = ALGO->first;
	while (map)
	{
		if (map->use == 1)
		{
			map->x = -1;
			map->y = -1;
			map->use = 0;
		}
		map = map->next;
	}
}

void	adjust_coord(t_main *main)
{
	int x;
	int y;
	t_map	*map;

	map = ALGO->first;
	x = y = 0;
	while (map)
	{
		if (map->use == 0)
		{
			if (x >= ALGO->max_x - 4)
			{
				y += 1;
				map->y = y;
				x = 0;
				map->x = 0;
			}
			map->x = x;
			map->y = y;
			x += 1;
		}
		map = map->next;
	}
}

void	go_back(t_map **map)
{
	if ((*map)->prev == 'S')
		*map = (*map)->down;
	else if ((*map)->prev == 'N')
		*map = (*map)->up;
	else if ((*map)->prev == 'E')
		*map = (*map)->right;
	else if ((*map)->prev == 'O')
		*map = (*map)->left;
}

int	is_empty(t_main *main)
{
	int error;
	t_map *cell;
	
	error = 0;
	cell = ALGO->first;
	while (cell && error == 0)
	{
		if (cell->use == 0)
			error = 1;
		cell = cell->next;
	}
	return (error);
}
