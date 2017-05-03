/*
** room.c for dungeon in /home/Rev/dante/dungeon
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Sat Apr	29 14:49:50 2017 Roméo Nahon
** Last update	Sat Apr	29 14:49:50 2017 Roméo Nahon
*/

#include "include/my.h"

sfColor	grey_color()
{
	sfColor color;

	color.r = 153;
	color.g = 153;
	color.b = 102;
	color.a = 255;
	return (color);
}

int	init_gen(sfVector2i *size, sfVector2i *max, int *pos_x, t_main *main)
{
	int pos_y;

	size->x = rand() % (5 - 20) + 5;
	size->y = rand() % (5 - 20) + 5;
	max->x = ALGO->max_x;
	max->y = ALGO->max_y;
	*pos_x = rand() % max->x;
	pos_y = rand() % max->y;
	return (pos_y);
}

char	go_to_pos(t_map **map, t_map *first, int pos_y, int pos_x)
{
	char	b_done;

	*map = first;
	b_done = 0;
	while (*map && b_done == 0)
	{
		if ((*map)->x == pos_x && (*map)->y == pos_y)
			b_done = 1;
		*map = (*map)->next;
	}
	return (b_done);
}

int	gen_room(t_main	*main, int *air)
{
	sfVector2i	size;
	sfVector2i	max;
	int pos_x;
	int	pos_y;
	char	b_done;
	t_map	*map;
	
	pos_y = init_gen(&size, &max, &pos_x, main);
	if ((b_done = go_to_pos(&map, ALGO->first, pos_y, pos_x)) == 0)
		return (0);
	if (prev_room(map, size, max) == 0)
	{
		draw_room(map, size, max, main);
		*air += (size.x) * (size.y);
	}
	else
		*air += (size.x * size.y);
	return (0);
}

void	display_room(t_main *main)
{
	int	air;
	int	total_air;

	air = 0;
	total_air = (main->height / main->size_map) * (main->width  / main->size_map);
	while ((air * 100) / total_air < main->room_density)
		gen_room(main, &air);
}