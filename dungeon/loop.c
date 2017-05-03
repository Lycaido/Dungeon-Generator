/*
** loop.c for main in /home/Rev/main
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Fri Mar	31 20:43:28 2017 Roméo Nahon
** Last update	Fri Mar	31 20:43:28 2017 Roméo Nahon
*/

#include "include/my.h"

void	loop(t_main *main)
{
	char	b_done;

	b_done = 0;
	sfRenderWindow_clear(main->init->window, sfBlack);
	while (sfRenderWindow_isOpen(main->init->window))
	{
		while (sfRenderWindow_pollEvent(main->init->window, &main->init->event))
		{
			if (main->init->event.key.code == sfKeyEscape)
				sfRenderWindow_close(main->init->window);
		}
		if (b_done == 0)
		{
			display_room(main);
			growing_tree(main);
			check_corridor(main);
			display_wall(main);
			b_done = 1;
		}
		if (b_done == 1)
		{
			my_printf("\033[31;1mGeneration terminée\033[0m. Appuyé sur echap pour quitter.\n");
			b_done = 2;
		}
		sfRenderWindow_display(INIT->window);
	}
	sfRenderWindow_destroy(main->init->window);
}