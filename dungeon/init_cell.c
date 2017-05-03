/*
** init_cell.c for dante in /home/Rev/dante/dungeon
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Mon Apr	17 12:08:28 2017 Roméo Nahon
** Last update	Mon Apr	17 12:08:28 2017 Roméo Nahon
*/

#include "include/my.h"

void	set_texture(t_main *main)
{
	int	random;

	random = rand() % 4;
	if (random == 0)
		INIT->rect_t->left = 0;
	else if (random == 1)
		INIT->rect_t->left = 50;
	else if (random == 2)
		INIT->rect_t->left = 100;
	else if (random == 3)
		INIT->rect_t->left = 150;
}
void	init_map_cell(t_main *main, t_map **map)
{
	sfVector2f cell_dim;
	sfVector2f cell_pos;

	cell_pos.x = ALGO->pos.x;
	cell_pos.y = ALGO->pos.y;
	cell_dim.x = main->size_map;
	cell_dim.y = main->size_map;
	(*map)->rect = sfRectangleShape_create();
	sfRectangleShape_setSize((*map)->rect, cell_dim);
	sfRectangleShape_setPosition((*map)->rect, cell_pos);
	set_texture(main);
	(*map)->texture = sfTexture_createFromImage(INIT->texture_i, INIT->rect_t);
	sfRectangleShape_setTexture((*map)->rect, (*map)->texture, sfTrue);
}

char	create_cell(t_main *main)
{
	t_map	*map;
	char	error;

	map = malloc(sizeof(t_map));
	error = 1;
	if (map != NULL)
	{
		init_map_cell(main, &map);
		if (ALGO->pos.x < main->width - (main->size_map))
		{
			ALGO->pos.x += main->size_map;
			map->x = ALGO->x;
			map->y = ALGO->y;
			if (map->y <= 1 || (map->x < 2 || map->x >= ALGO->max_x - 2)
				|| (map->y >= ALGO->max_y))
				map->use = 1;
			else
				map->use = 0;
			ALGO->x += 1;
		}
		else if (ALGO->pos.y < main->height - main->size_map)
		{
			ALGO->pos.y += main->size_map;
			ALGO->pos.x = main->size_map;
			ALGO->x = 0;
			ALGO->y += 1;
			map->y = ALGO->y;
			map->x = ALGO->x;
			if (map->y <= 1 || (map->x < 2 || map->x >= ALGO->max_x - 2)
				|| (map->y >= ALGO->max_y))
				map->use = 1;
			else
				map->use = 0;
		}
		map->next = ALGO->first;
		ALGO->first = map;
		error = 0;
	}
	return (error);
}