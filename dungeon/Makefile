CC      =       gcc -O3

RM      =       rm -f

NAME    =       dungeon

SRC     =       main.c			\
				init.c			\
				init_cell.c		\
				init_cell_next.c	\
				loop.c			\
				growing_tree.c	\
				growing_tree_utils.c	\
				room.c					\
				room_check.c			\
				corridor.c				\

OBJ     =       $(SRC:.c=.o)

CFLAGS  +=      -Wextra -Wunused -Werror -W -Wimplicit

all:            $(NAME)

$(NAME):        $(OBJ)
		$(CC) $(OBJ) -Llib/my -lmy -lcsfml-graphics -lcsfml-window -lc_graph_prog -lm -o $(NAME)

clean:
		$(RM) $(OBJ) $(HASHTAG)
		rm -f *~
		rm -f *#

fclean:         clean
		$(RM) $(NAME)

re:             fclean all

val:            re
		$(CC) -g3 $(SRC) -Llib/my -lmy -lcsfml-graphics -lcsfml-window -lc_graph_prog -lm -o $(NAME)

.PHONY:         all clean fclean re
