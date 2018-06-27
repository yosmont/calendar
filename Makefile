##
## EPITECH PROJECT, 2018
## yet another Makefile
## File description:
## not a copy of a exemple Makefile... not at all
##

NAME	=	calendar

SRC	=	src/main.c		\
		src/add_to_list.c	\
		src/free.c		\
		src/invite_exclude.c	\
		src/my_atoi.c		\
		src/strtowordtab.c	\
		src/delete_from_list.c	\
		src/lib.c		\
		src/command.c		\
		src/command_sort.c	\
		src/new_employee_tab.c	\
		src/gnl_redux.c		\
		src/display.c		\
		src/display_tools.c	\
		src/sort_emp.c		\
		src/sort_emp_id.c	\
		src/sort_meet.c

CFLAGS	+=	-Wall -Wextra -Iinclude/

DFLAG	+=	-g

OBJ	=	$(SRC:.c=.o)

all:		$(OBJ)
	gcc $(OBJ) -o $(NAME) $(CFLAGS) $(DFLAG)
	@echo "┌─┐┌┐┌┌┬┐  ┌─┐┌─┐┌┬┐┌─┐┬┬  ┬┌┐┌┌─┐   ┬ ┬┌─┐┌┬┐┬"
	@echo "├┤ │││ ││  │  │ ││││├─┘││  │││││ ┬   └┬┘├─┤││││"
	@echo "└─┘┘└┘─┴┘  └─┘└─┘┴ ┴┴  ┴┴─┘┴┘└┘└─┘┘   ┴ ┴ ┴┴ ┴o"

clean:
	rm -f $(OBJ)
	@echo "┌─┐┌┐┌┌┬┐  ┌─┐┬  ┌─┐┌─┐┌┐┌   ┬ ┬┌─┐┌┬┐┬"
	@echo "├┤ │││ ││  │  │  ├┤ ├─┤│││   └┬┘├─┤││││"
	@echo "└─┘┘└┘─┴┘  └─┘┴─┘└─┘┴ ┴┘└┘┘   ┴ ┴ ┴┴ ┴o"

fclean:		clean
	rm -f $(NAME)
	@echo "┌─┐┌┐┌┌┬┐  ┌─┐┌─┐┬  ┌─┐┌─┐┌┐┌   ┬ ┬┌─┐┌┬┐┬"
	@echo "├┤ │││ ││  ├┤ │  │  ├┤ ├─┤│││   └┬┘├─┤││││"
	@echo "└─┘┘└┘─┴┘  └  └─┘┴─┘└─┘┴ ┴┘└┘┘   ┴ ┴ ┴┴ ┴o"

re:		fclean all
	@echo "┌─┐┌┐┌┌┬┐  ┬─┐┌─┐   ┬ ┬┌─┐┌┬┐┬"
	@echo "├┤ │││ ││  ├┬┘├┤    └┬┘├─┤││││"
	@echo "└─┘┘└┘─┴┘  ┴└─└─┘┘   ┴ ┴ ┴┴ ┴o"

tests_run:
	make -C tests
	./tests/tests
	@echo "┌─┐┌┐┌┌┬┐  ┬─┐┬ ┬┌┐┌┌┐┌┬┌┐┌┌─┐  ┌┬┐┌─┐┌─┐┌┬┐  ┬ ┬┌─┐┌┬┐┬"
	@echo "├┤ │││ ││  ├┬┘│ ││││││││││││ ┬   │ ├┤ └─┐ │   └┬┘├─┤││││"
	@echo "└─┘┘└┘─┴┘  ┴└─└─┘┘└┘┘└┘┴┘└┘└─┘   ┴ └─┘└─┘ ┴┘   ┴ ┴ ┴┴ ┴o"

.PHONY: 	all clean fclean re tests_run
