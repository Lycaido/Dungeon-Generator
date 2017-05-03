/*
** growing_tree.c for dungeon in /home/Rev/dante/dungeon
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Sat Apr	15 10:43:45 2017 Roméo Nahon
** Last update	Sat Apr	15 10:43:45 2017 Roméo Nahon
*/

#include "include/my.h"

char	check_neighbors(t_main *main, t_map *map)
{
	char	is_free;

	is_free = 0;
	if (map->y - 1 >= 0 && map->up->use == 0 &&
		map->up->up->use == 0 && map->up->left->use == 0 && map->up->right->use == 0)
		is_free = 1;
	if (map->y + 1 <= ALGO->max_y && map->down->use == 0 &&
		map->down->down->use == 0 && map->down->left->use == 0 && map->down->right->use == 0)
		is_free = 1;
	if (map->x - 1 >= 0 && map->left->use == 0 &&
		map->left->left->use == 0 && map->left->up->use == 0 && map->left->down->use == 0)
		is_free = 1;
	if (map->x + 1 <= ALGO->max_x && map->right->use == 0 &&
		map->right->right->use == 0 && map->right->up->use == 0 && map->right->down->use == 0)
		is_free = 1;
	return (is_free);
}

char	random_direction(t_main *main, t_map *map)
{
	int	i;
	char random[4];

	i = 0;
	my_memset(random, 0, 4);
	if (map->x + 1 <= ALGO->max_x && map->right->use == 0 &&
		map->right->right->use == 0 && map->right->up->use == 0 && map->right->down->use == 0)
	{
		random[i] = 'E';
		i += 1;
	}
	if (map->x - 1 >= 0 && map->left->use == 0 &&
		map->left->left->use == 0 && map->left->up->use == 0 && map->left->down->use == 0)
	{
		random[i] = 'O';
		i += 1;
	}
	if (map->y - 1 >= 0 && map->up->use == 0 &&
		map->up->up->use == 0 && map->up->left->use == 0 && map->up->right->use == 0)
	{
		random[i] = 'N';
		i += 1;
	}
	if (map->y + 1 <= ALGO->max_y && map->down->use == 0 &&
		map->down->down->use == 0 && map->down->left->use == 0 && map->down->right->use == 0)
	{
		random[i] = 'S';
		i += 1;
	}
	if (i == 0)
		return (0);
	return (random[rand() % i]);
}

void	apply_direction(t_map **map, char direction)
{
	if (direction == 'N')
	{
		*map = (*map)->up;
		(*map)->prev = 'S';
	}
	else if (direction == 'S')
	{
		*map = (*map)->down;
		(*map)->prev = 'N';
	}
	else if (direction == 'E')
	{
		*map = (*map)->right;
		(*map)->prev = 'O';
	}
	else if (direction == 'O')
	{
		*map = (*map)->left;
		(*map)->prev = 'E';
	}
}
void	growing_tree(t_main *main)
{
	t_map	*map;
	char	direction;
	char	b_done;

	b_done = 0;
	map = ALGO->first;
	map = map->right->right->down->down;
	while (b_done == 0)
	{
		sfRenderWindow_drawRectangleShape(INIT->window, map->rect, NULL);
		direction = random_direction(main, map);
		if (direction != 0)
		{
			map->use = 1;
			apply_direction(&map, direction);
		}
		else
		{
			if (map->x == 0 && map->y == 0)
				b_done = 1;
			map->use = 1;
			INIT->rect_t->left = 50;
			INIT->rect_t->top = 53;
			map->texture = sfTexture_createFromImage(INIT->texture_i, INIT->rect_t);
			sfRectangleShape_setTexture(map->rect, map->texture, sfTrue);
			sfRenderWindow_drawRectangleShape(INIT->window, map->rect, NULL);
			go_back(&map);
		}
		sfRenderWindow_display(INIT->window);
	}
}