##
## EPITECH PROJECT, 2018
## palindrome
## File description:
## Makefile for units tests
##

NAME	=	tests

RM	=	rm -f

CC	=	gcc

SRC	=	../src/add_to_list.c		\
		../src/free.c			\
		../src/invite_exclude.c		\
		../src/my_atoi.c		\
		../src/strtowordtab.c		\
		../src/delete_from_list.c	\
		../src/lib.c			\
		../src/command.c		\
		../src/command_sort.c		\
		../src/new_employee_tab.c	\
		../src/gnl_redux.c		\
		../src/display.c		\
		../src/display_tools.c		\
		../src/sort_emp.c		\
		../src/sort_emp_id.c		\
		../src/sort_meet.c		\
		basic_my.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-I ../include/ --coverage

LDFLAGS	+=	-lcriterion

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)
		@echo "┌─┐┌┐┌┌┬┐  ┌─┐┌─┐┌┬┐┌─┐┬┬  ┬┌┐┌┌─┐   ┬ ┬┌─┐┌┬┐┬"
		@echo "├┤ │││ ││  │  │ ││││├─┘││  │││││ ┬   └┬┘├─┤││││"
		@echo "└─┘┘└┘─┴┘  └─┘└─┘┴ ┴┴  ┴┴─┘┴┘└┘└─┘┘   ┴ ┴ ┴┴ ┴o"

all:		$(NAME)

clean:
		$(RM) $(OBJ)
		rm *.gc*
		rm ../src/*.gc*
		@echo "┌─┐┌┐┌┌┬┐  ┌─┐┬  ┌─┐┌─┐┌┐┌   ┬ ┬┌─┐┌┬┐┬"
		@echo "├┤ │││ ││  │  │  ├┤ ├─┤│││   └┬┘├─┤││││"
		@echo "└─┘┘└┘─┴┘  └─┘┴─┘└─┘┴ ┴┘└┘┘   ┴ ┴ ┴┴ ┴o"

fclean:		clean
		$(RM) $(NAME)
		@echo "┌─┐┌┐┌┌┬┐  ┌─┐┌─┐┬  ┌─┐┌─┐┌┐┌   ┬ ┬┌─┐┌┬┐┬"
		@echo "├┤ │││ ││  ├┤ │  │  ├┤ ├─┤│││   └┬┘├─┤││││"
		@echo "└─┘┘└┘─┴┘  └  └─┘┴─┘└─┘┴ ┴┘└┘┘   ┴ ┴ ┴┴ ┴o"

re:		fclean all
		@echo "┌─┐┌┐┌┌┬┐  ┬─┐┌─┐   ┬ ┬┌─┐┌┬┐┬"
		@echo "├┤ │││ ││  ├┬┘├┤    └┬┘├─┤││││"
		@echo "└─┘┘└┘─┴┘  ┴└─└─┘┘   ┴ ┴ ┴┴ ┴o"

.PHONY:		all clean fclean re
