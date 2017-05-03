/*
** main.c for main in /home/Rev/main
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Fri Mar	31 20:43:22 2017 Roméo Nahon
** Last update	Fri Mar	31 20:43:22 2017 Roméo Nahon
*/

#include "include/my.h"

int	init_struct(t_main *main)
{
	if ((main->init = malloc(sizeof(t_init))) == NULL)
		return (-1);
	if ((main->algo = malloc(sizeof(t_algo))) == NULL)
		return (-1);
	return (0);
}

int		main(int ac, char **av)
{
	t_main	*main;

	if(ac != 5)
	{
		my_printf("USAGE: ./%s [width] [height] [size cell] [density 1 - 90]\n", av[0]);
		return (84);
	}
	if ((main = malloc(sizeof(t_main))) == NULL)
		return (84);
	if (init_struct(main) == -1)
		return (84);
	main->height = my_getnbr(av[2]);
	main->width = my_getnbr(av[1]);
	main->size_map = my_getnbr(av[3]);
	main->room_density = my_getnbr(av[4]);
	if (main->room_density > 200 || main->room_density < 10)
	{
		my_printf("Error: size of room have to be between 10 - 200\n");
		return (84);
	}
	init(main);
	loop(main);
}