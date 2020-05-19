##
## EPITECH PROJECT, 2019
## PSU_my_sokoban_2019
## File description:
## Makefile
##

SRC    =  *.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:   $(NAME) clean

$(NAME):
			@echo -e "\033[1;33m[COMPILING LIB...]\033[0;30m"
			gcc -c $(SRC) -I../include/
			ar rc $(NAME) $(OBJ)
			@echo -e "\033[1;32m[SUCCESSFULLY LIB COMPLETED]\033[0;30m"

clean:
	rm -f $(OBJ)
