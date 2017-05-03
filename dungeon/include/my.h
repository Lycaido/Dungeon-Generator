/*
** my.h for scroller in /home/Rev/scroller/include
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Fri Mar	31 21:17:05 2017 Roméo Nahon
** Last update	Fri Mar	31 21:17:05 2017 Roméo Nahon
*/


#ifndef MY_H
# define MY_H

# include <SFML/Graphics/RenderWindow.h>
# include <SFML/Graphics/Sprite.h>
# include <SFML/Graphics/Texture.h>
# include <SFML/Graphics.h>
# include <SFML/Window.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <time.h>

# define INIT main->init
# define ALGO main->algo

# define MAP ((main->height / main->size_map) * (main->width / main->size_map))

typedef struct s_map
{
	sfRectangleShape *rect;
	sfTexture		*texture;
	int			use;
	int			x;
	int			y;
	struct s_map *up;
	struct s_map *down;
	struct s_map *left;
	struct s_map *right;
	struct s_map *next;
	char	prev;
}				t_map;

typedef struct s_algo
{
	sfVector2f pos;
	int x;
	int y;
	int id;
	int frame;
	int	nb_cell;
	int max_x;
	int max_y;
	t_map *first;
}			   t_algo;

typedef struct s_init
{
	sfRenderWindow* window;
	sfVideoMode     mode;
	sfEvent  		event;

	sfImage			*texture_i;
	sfTexture		*texture;
	sfIntRect		*rect_t;
}				t_init;

typedef struct s_main
{
	t_init	*init;
	t_algo *algo;
	int		width;
	int		height;
	int		size_map;
	int		room_density;
}				t_main;

/*lib*/
int	my_printf(char *, ...);
void	my_memset(char *, char , int);
int	my_getnbr(char *str);

/*init.c*/
int 	init(t_main *main);

/*loop.c*/
void	loop(t_main *main);

/*generation.c*/
int	create_room(t_main *main);

/*growing_tree.c*/
void	growing_tree(t_main *main);

/*init_cell.c*/
char	create_cell(t_main *main);

/*init_cell_next.c*/
void	 apply_neighbors(t_main *main);

/*growing_tree_utils.c*/
void	resume_use(t_main *main);
void	adjust_coord(t_main *main);
void	create_border(t_main *main);
int	is_empty(t_main *main);
void	go_back(t_map **map);

/*room.c*/
void	display_room(t_main *main);
sfColor	grey_color();

/*room_check.c*/
char	prev_room(t_map *map, sfVector2i size, sfVector2i);
void	draw_room(t_map *, sfVector2i, sfVector2i, t_main*);

/*corridor.c*/
void	check_corridor(t_main *main);
void	display_wall(t_main *main);

#endif /* MY_H */