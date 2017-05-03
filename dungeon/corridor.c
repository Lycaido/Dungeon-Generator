/*
** corridor.c for dungeon in /home/Rev/dante/dungeon
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Mon May	1 16:21:45 2017 Roméo Nahon
** Last update	Mon May	1 16:21:45 2017 Roméo Nahon
*/

#include "include/my.h"

void	display_wall(t_main *main)
{
	t_map	*map;

	map = ALGO->first;
	while (map)
	{
		if (map->use == 0 && map->x != -1 && map->y < ALGO->max_y + 2)
			sfRenderWindow_drawRectangleShape(INIT->window, map->rect, NULL);
		map = map->next;
	}
}

void	check_corridor(t_main *main)
{
	t_map *map;
	char	b_done;

	b_done = 0;
	map = ALGO->first;
	while (map)
	{
		if (map->use == 2)
		{
			if (map->up->up->use == 1 && b_done == 0 && map->left->use != 0 && map->right->use != 0)
			{
				if (rand() % 5 == 1)
				{
					INIT->rect_t->top = 53;
					INIT->rect_t->left = 0;
					sfRectangleShape_rotate (map->right->down->rect, 180);
					map->texture = sfTexture_createFromImage(INIT->texture_i, INIT->rect_t);
					sfRectangleShape_setTexture(map->right->down->rect, map->texture, sfTrue);
					sfRenderWindow_drawRectangleShape(INIT->window, map->right->down->rect, NULL);
					INIT->rect_t->left = 50;
					map->texture = sfTexture_createFromImage(INIT->texture_i, INIT->rect_t);
					sfRectangleShape_setTexture(map->up->rect, map->texture, sfTrue);
					sfRenderWindow_drawRectangleShape(INIT->window, map->up->rect, NULL);
					sfRenderWindow_display(INIT->window);
					b_done = 1;
				}
			}
			if (map->left->left->use == 1 && b_done == 0 && map->down->use != 0 && map->up->use != 0)
			{
				if (rand() % 5 == 1)
				{
					INIT->rect_t->top = 53;
					INIT->rect_t->left = 0;
					sfRectangleShape_rotate (map->right->rect, 90);
					map->texture = sfTexture_createFromImage(INIT->texture_i, INIT->rect_t);
					sfRectangleShape_setTexture(map->right->rect, map->texture, sfTrue);
					sfRenderWindow_drawRectangleShape(INIT->window, map->right->rect, NULL);
					INIT->rect_t->left = 50;
					map->texture = sfTexture_createFromImage(INIT->texture_i, INIT->rect_t);
					sfRectangleShape_setTexture(map->left->rect, map->texture, sfTrue);
					sfRenderWindow_drawRectangleShape(INIT->window, map->left->rect, NULL);
					sfRenderWindow_display(INIT->window);
					b_done = 1;
				}
			}
			if (map->right->right->use == 1 && b_done == 0 && map->up->use != 0 && map->down->use != 0)
			{
				if (rand() % 5 == 1)
				{
					INIT->rect_t->top = 53;
					INIT->rect_t->left = 0;
					sfRectangleShape_rotate (map->down->rect, 270);
					map->texture = sfTexture_createFromImage(INIT->texture_i, INIT->rect_t);
					sfRectangleShape_setTexture(map->down->rect, map->texture, sfTrue);
					sfRenderWindow_drawRectangleShape(INIT->window, map->down->rect, NULL);
					INIT->rect_t->left = 50;
					map->texture = sfTexture_createFromImage(INIT->texture_i, INIT->rect_t);
					sfRectangleShape_setTexture(map->right->rect, map->texture, sfTrue);
					sfRenderWindow_drawRectangleShape(INIT->window, map->right->rect, NULL);
					sfRenderWindow_display(INIT->window);
					b_done = 1;
				}
			}
			if (map->down->down->use == 1 && b_done == 0 && map->left->use != 0 && map->right->use != 0)
			{
				if (rand() % 5 == 1)
				{
					INIT->rect_t->top = 53;
					INIT->rect_t->left = 0;
					map->texture = sfTexture_createFromImage(INIT->texture_i, INIT->rect_t);
					sfRectangleShape_setTexture(map->rect, map->texture, sfTrue);
					sfRenderWindow_drawRectangleShape(INIT->window, map->down->up->rect, NULL);
					INIT->rect_t->left = 50;
					map->texture = sfTexture_createFromImage(INIT->texture_i, INIT->rect_t);
					sfRectangleShape_setTexture(map->down->rect, map->texture, sfTrue);
					sfRenderWindow_drawRectangleShape(INIT->window, map->down->rect, NULL);
					sfRenderWindow_display(INIT->window);
					b_done = 1;
				}
			}
		}
		else
			b_done = 0;
		map = map->next;
	}
	sfRenderWindow_display(INIT->window);
}