##
## EPITECH PROJECT, 2024
## EPITECH | WORKSHOP | CSFML
## File description:
## Makefile
##

SRC_MAIN		=   src/main.c                              \

SRC             =   src/mon_rpg.c                    		\
					src/parallax.c							\

SRC_TEST		=	units_tests/test.c                      \

OBJ 			=	$(SRC_MAIN:.c=.o)						\
					$(SRC:.c=.o)

OBJ_TEST		=	$(SRC_TEST:.c=.o)						\
					$(SRC:.c=.o)

INC             =   -I./include

CFLAGS			=	-W -Wall -Werror -Wextra $(INC) -std=c11 -D_GNU_SOURCE

LDFLAGS         =   --coverage -lcriterion

SFMLFLAGS 		=  -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

NAME            =   mon_rpg

NAME_TEST		=   unit_tests

RM              =   rm -f

$(NAME):			$(OBJ)
					gcc -o $(NAME) $(OBJ) $(SFMLFLAGS) $(CFLAGS)

all:				$(NAME)

debug: 				CFLAGS += -g3 -ggdb
debug:              re

clean:
					$(RM) $(OBJ) $(OBJ_TEST)

fclean:             clean
					$(RM) $(NAME) $(NAME_TEST)
					find . -name "*.o" -delete -or -name "*.a" -delete
					find . -name "*.gcda" -delete -or -name "*.gcno" -delete
					find . -name "*.log" -delete

tests_run:			CFLAGS += $(LDFLAGS)
tests_run: 			$(OBJ_TEST)
					gcc -o $(NAME_TEST) $(OBJ_TEST) $(CFLAGS)
					./unit_tests --verbose

re:					fclean all

.PHONY:             all debug clean fclean tests_run re
