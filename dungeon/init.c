/*
** init.c for main in /home/Rev/main
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Fri Mar	31 20:42:28 2017 Roméo Nahon
** Last update	Fri Mar	31 20:42:28 2017 Roméo Nahon
*/

#include "include/my.h"

t_map	*reverse_list(t_map *map)
{
	t_map	*new_cell;
	t_map	*next;

	new_cell = NULL;
	while (map)
	{
		next = map->next;
		map->next = new_cell;
		new_cell = map;
		map = next;
	}
	return (new_cell);
}

void	init_texture(t_main *main)
{
	if ((INIT->rect_t = malloc(sizeof(sfIntRect))) == NULL)
		return ;
	INIT->texture_i = sfImage_createFromFile("ress/texture.png");
	if (INIT->texture_i == NULL)
	{
		my_printf("Error: can't load texture\n");
		exit (0);
	}
	INIT->rect_t->left = 0;
	INIT->rect_t->top = 1;
	INIT->rect_t->width = 32;
	INIT->rect_t->height = 32;
}
void	init_algo(t_main *main)
{
	ALGO->frame = 0;
	ALGO->x = 0;
	ALGO->y = 0;
	ALGO->nb_cell = 0;
	ALGO->first = NULL;
	ALGO->max_y = (main->height / main->size_map) - 2;
	ALGO->max_x = (main->width / main->size_map) - 2;
	ALGO->pos.y = main->size_map;
	ALGO->pos.x = main->size_map;
	ALGO->y = 0;
}

void	create_map(t_main *main)
{
	clock_t t;
	clock_t a;
	clock_t b;
	clock_t c;

	my_printf("\033[34;1mStart creating map of %d cases...\033[0m\n", ((main->width * main->height) - (((main->width / main->size_map) * 2) + ((main->height / main->size_map) * 2))) / main->size_map);
	while (ALGO->frame < MAP && ALGO->pos.y < main->height - main->size_map)
	{
		if (create_cell(main) == 1)
			return ;
		ALGO->frame++;
	}
	apply_neighbors(main);
	t = clock();
	printf("\033[32mApply neighbors done in %f\033[0m\n", (double)t / CLOCKS_PER_SEC);
	ALGO->first = reverse_list(ALGO->first);
	a = clock();
	printf("\033[32mReverse list done in %f\033[0m\n", ((double)a / CLOCKS_PER_SEC) - ((double)t / CLOCKS_PER_SEC));
	adjust_coord(main);
	b = clock();
	printf("\033[32mAdjust coord done in %f\033[0m\n", ((double)b / CLOCKS_PER_SEC) - ((double)t / CLOCKS_PER_SEC));
	resume_use(main);
	c = clock();
	printf("\033[32mResume use done in %f\033[0m\n", ((double)c / CLOCKS_PER_SEC) - ((double)t / CLOCKS_PER_SEC));
	t = clock();
	printf("\033[31;1mCreating map done in %f\033[0m\n", (double)t / CLOCKS_PER_SEC);
}

int		init(t_main *main)
{
	main->init->mode.width = main->width;
	main->init->mode.height = main->height;
	main->init->mode.bitsPerPixel = 32;
	main->init->window = sfRenderWindow_create(main->init->mode, "maze generator", sfResize | sfClose, NULL);
	if (main->init->window == NULL)
		return (-1);
	sfRenderWindow_setVerticalSyncEnabled(main->init->window, sfTrue);
	init_texture(main);
	init_algo(main);
	create_map(main);
	ALGO->max_y -= 8;
	ALGO->max_x -= 5;
	srand(time(NULL));
	return (0);
}