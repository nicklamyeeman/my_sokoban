##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC_DIR	=	./src/

SRC	=	$(SRC_DIR)score.c		\
		$(SRC_DIR)directions.c	\
		$(SRC_DIR)sokoban.c		\
		$(SRC_DIR)tools.c		\
		$(SRC_DIR)colors.c		\
		$(SRC_DIR)menu.c		\
		$(SRC_DIR)main.c

INC		=	-I ./include -I ./lib/my/include

LIB		= 	-L ./lib/my/ -lmy

CFLAGS	+= $(INC) -W -Wall -Wextra -g

NCFLAGS =	-lncurses

OBJ	=	$(SRC:.c=.o)

NAME	=	my_sokoban

all:	$(OBJ)
	make -sC ./lib/my
	gcc -o $(NAME) $(LIB) $(OBJ) $(NCFLAGS)

clean:
	make -sC ./lib/my clean
	rm -f $(OBJ)

fclean:	clean
	make -sC ./lib/my fclean
	rm -f $(NAME)

re:	fclean all
