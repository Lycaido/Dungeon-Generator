/*
** init_cell_next.c for dante in /home/Rev/dante/dungeon
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Tue Apr	18 11:49:37 2017 Roméo Nahon
** Last update	Tue Apr	18 11:49:37 2017 Roméo Nahon
*/

#include "include/my.h"

void	neighbors_left(t_map **map, t_map *tmp, char b_done)
{
	while (tmp != NULL && b_done == 0)
	{
		if (tmp != NULL && tmp->x == (*map)->x - 1 && tmp->y == (*map)->y)
		{
			(*map)->left = tmp;
			b_done = 1;
		}
		tmp = tmp->next;
	}
}

void	neighbors_right(t_map **map, t_map *tmp, char b_done)
{
	while (tmp != NULL && b_done == 0)
	{
		if (tmp != NULL && tmp->x == (*map)->x + 1 && tmp->y == (*map)->y)
		{
			(*map)->right = tmp;
			b_done = 1;
		}
		tmp = tmp->next;
	}
}

void	neighbors_up(t_map **map, t_map *tmp, char b_done)
{
	while (tmp != NULL && b_done == 0)
	{
		if (tmp != NULL && tmp->x == (*map)->x && tmp->y == (*map)->y - 1)
		{
			(*map)->up = tmp;
			b_done = 1;
		}
		tmp = tmp->next;
	}
}

void	neighbors_down(t_map **map, t_map *tmp, char b_done)
{
	while (tmp != NULL && b_done == 0)
	{
		if (tmp != NULL && tmp->x == (*map)->x && tmp->y == (*map)->y + 1)
		{
			(*map)->down = tmp;
			b_done = 1;
		}
		tmp = tmp->next;
	}
}

void	neighbors(t_map **map, t_map *first, int x_limit, int y_limit)
{
	char	b_done;
	t_map	*tmp;

	tmp = first;
	b_done = 0;
	if ((*map)->x - 1 >= 0)
		neighbors_left(map, tmp, b_done);
	else
		(*map)->left = NULL;
	if ((*map)->x + 1 <= x_limit)
		neighbors_right(map, tmp, b_done);
	else
		(*map)->right = NULL;
	if ((*map)->y - 1 >= 0)
		neighbors_up(map, tmp, b_done);
	else
		(*map)->up = NULL;
	if ((*map)->y + 1 <= y_limit)
		neighbors_down(map, tmp, b_done);
	else
		(*map)->down = NULL;
}

void	 apply_neighbors(t_main *main)
{
	t_map *map;

	map = ALGO->first;
	while (map)
	{
		neighbors(&map, ALGO->first, ALGO->max_x, ALGO->max_y);
		map = map->next;
	}
}