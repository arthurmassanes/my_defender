##
## EPITECH PROJECT, 2019
## my_defender
## File description:
## short file description
##

SRC	=	src/menu.c	\
		src/main.c	\
		src/my_defender.c	\
		src/str.c	\
		src/sprite.c	\
		src/text.c	\
		src/scene.c	\
		src/button.c	\
		src/destroy.c	\
		src/create_linked_list.c	\
		src/options.c	\
		src/sound.c	\
		src/fps.c	\
		src/number.c	\
		src/opponents.c	\
		src/castle.c	\
		src/create_game_buttons.c	\
		src/wave.c	\
		src/create_game_object.c	\
		src/tower.c	\
		src/animate.c	\
		src/draw_list.c	\
		src/particules.c	\
		src/framebuffer_create.c	\
		src/create_sound.c	\
		src/pause.c	\
		src/bullet.c	\
		src/kill.c	\
		src/game_over.c

OBJ	=	$(SRC:.c=.o)

NAME	=	 my_defender

HEAD	=	-I./include

all:
	@gcc -g3 -o $(NAME) $(SRC) $(HEAD) -lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all
