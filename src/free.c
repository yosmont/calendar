/*
** EPITECH PROJECT, 2018
** SYN_calendar_2017
** File description:
** free function
*/

#include <stdlib.h>
#include <string.h>
#include "project.h"

void free_tab(char **tab)
{
	if (tab) {
		for (int i = 0; tab[i] != NULL; i++)
			free(tab[i]);
		free(tab);
	}
}

void free_emp(employee_t *list)
{
	employee_t *tmp = NULL;

	while (list) {
		tmp = list->next;
		free_emp_node(list);
		list = tmp;
	}
}

void free_meet(meeting_t *list)
{
	meeting_t *tmp = NULL;

	while (list) {
		tmp = list->next;
		free_meet_node(list);
		list = tmp;
	}
}
