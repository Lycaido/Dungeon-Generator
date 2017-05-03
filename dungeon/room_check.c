/*
** room_check.c for dungeon in /home/Rev/dante/dungeon
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Sat Apr	29 15:53:51 2017 Roméo Nahon
** Last update	Sat Apr	29 15:53:51 2017 Roméo Nahon
*/

# include "include/my.h"

char	prev_room_check(sfVector2i coord, sfVector2i max,
	sfVector2i size, t_map *tmp, char b_done)
{
	if (coord.x >= max.x || tmp->use == 2 || tmp->x == -1 || tmp->y == -1)
		b_done = 1;
	if (coord.x == size.x)
	{
		if (tmp->right->use == 2 || (tmp->right->right != NULL && tmp->right->right->use == 2))
			b_done = 1;
	}
	if (coord.x == 0)
		if (tmp->left->use == 2 || (tmp->left->left != NULL && tmp->left->left->use == 2))
			b_done = 1;
	if (coord.y == 0)
		if (tmp->up->use == 2 || (tmp->up->up != NULL && tmp->up->up->use == 2))
			b_done = 1;
	if (coord.y == size.y)
		if (tmp->down->use == 2 || (tmp->down->down != NULL && tmp->down->down->use == 2))
			b_done = 1;
	return (b_done);
}
char	prev_room(t_map *map, sfVector2i size, sfVector2i max)
{
	t_map		*tmp;
	sfVector2i	coord;
	char		b_done;
	t_map		*begin;

	b_done = 0;
	tmp = begin = map;
	coord.y = -1;
	while (tmp && b_done == 0)
	{
		if (coord.y >= max.y) b_done = 1;
		if (coord.y == size.y) b_done = 2;
		coord.x = -1;
		while (tmp && ++coord.x <= size.x && b_done != 1)
		{
			if (coord.x == 0) begin = tmp;
			b_done = prev_room_check(coord, max, size, tmp, b_done);
			tmp = tmp->right;
		}
		tmp = begin;
		tmp = tmp->down;
		coord.y += 1;
	}
	if (b_done == 0 || b_done == 1) return (1);
	return (0);
}
void	random_texture(t_main *main)
{
	int	random;

	random = rand() % 150;

	if (random == 0)
	{
		INIT->rect_t->left = 151;
		INIT->rect_t->top = 54;
	}
	else if (random == 1)
	{
		INIT->rect_t->left = 200;
		INIT->rect_t->top = 54;
	}
	else if (random == 2)
	{
		INIT->rect_t->left = 250;
		INIT->rect_t->top = 55;
	}
	else if (random == 3)
	{
		INIT->rect_t->left = 300;
		INIT->rect_t->top = 55;
	}
	else if (random == 4)
	{
		INIT->rect_t->left = 300;
		INIT->rect_t->top = 0;
	}
	else if (random == 5)
	{
		INIT->rect_t->left = 350;
		INIT->rect_t->top = 0;
	}
	else
	{
		INIT->rect_t->left = 50;
		INIT->rect_t->top = 53;
	}
}
void	draw_room(t_map *map, sfVector2i size, sfVector2i max, t_main *main)
{
	int		x;
	int		y;
	char	b_done;
	t_map	*begin;

	b_done = y = 0;
	begin = map;
	while (map && b_done == 0)
	{
		if (y >= max.y)
			b_done = 1;
		if (y == size.y)
			b_done = 2;
		x = -1;
		while (map && ++x <= size.x && b_done != 1)
		{
			if (x == 0)
				begin = map;
			if (x == 0 || y == 0 || x == size.x || y == size.y)
			{
				INIT->rect_t->left = 100;
				INIT->rect_t->top = 53;
				map->texture = sfTexture_createFromImage(INIT->texture_i, INIT->rect_t);
				sfRectangleShape_setTexture(map->rect, map->texture, sfTrue);
			}
			else
			{
				random_texture(main);
				map->texture = sfTexture_createFromImage(INIT->texture_i, INIT->rect_t);
				sfRectangleShape_setTexture(map->rect, map->texture, sfTrue);
			}
			map->use = 2;
			sfRenderWindow_drawRectangleShape(INIT->window, map->rect, NULL);
			map = map->right;
			if (x >= max.x)
			b_done = 1;
		}
		map = begin;
		map = map->down;
		y += 1;
	}
	sfRenderWindow_display(INIT->window);
}