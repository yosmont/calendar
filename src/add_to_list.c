/*
** EPITECH PROJECT, 2018
** SYN_calendar_2017
** File description:
** add to list function
*/

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "project.h"

int tablen(char **tab)
{
	int len = 0;

	for (len = 0; tab[len]; len++);
	return (len);
}

static int check_valid_employee(char **tab)
{
	if (check_isfunction(tab[5], &isdigit) == 0)
		return (0);
	for (int i = 1; i < 4; i++)
		if (check_isfunction(tab[i], &isalpha) == 0)
			return (0);
	return (1);
}

employee_t *new_employee(char *line)
{
	char **tab = my_str_to_word_array_synthesis(line);
	employee_t *new = malloc(sizeof(employee_t));

	if (tablen(tab) != 6 || check_valid_employee(tab) == 0) {
		free(new);
		free_tab(tab);
		return (NULL);
	}
	new->id = my_atoi(tab[5]);
	new->last_name = strdup(tab[1]);
	new->first_name = strdup(tab[2]);
	new->pos = strdup(tab[3]);
	new->zipcode = strdup(tab[4]);
	new->id_meeting = malloc(sizeof(int) * 2);
	new->id_meeting[0] = -1;
	new->next = NULL;
	free_tab(tab);
	return (new);
}

static int check_valid_meeting(char **tab)
{
	int day = 0;
	int month = 0;

	if (check_isfunction(tab[3], &isdigit) == 0)
		return (0);
	for (int i = 4; tab[i]; i++)
		if (check_isfunction(tab[i], &isdigit) == 0)
			return (0);
	if (strlen(tab[2]) < 10 || tab[2][2] != '/' || tab[2][5] != '/')
		return (0);
	day = (((tab[2][0] - '0') * 10) + (tab[2][1] - '0'));
	month = (((tab[2][3] - '0') * 10) + (tab[2][4] - '0'));
	if (day > 31 || month > 12)
		return (0);
	return (1);
}

meeting_t *new_meeting(char *line)
{
	char **tab = my_str_to_word_array_synthesis(line);
	meeting_t *new = malloc(sizeof(meeting_t));
	int len = tablen(tab);

	if (len < 6 || check_valid_meeting(tab) == 0) {
		free_tab(tab);
		free(new);
		return (NULL);
	}
	new->id = my_atoi(tab[3]);
	new->day = strdup(tab[2]);
	new->zipcode = strdup(tab[1]);
	new->id_employee = malloc(sizeof(int) * (len - 4 + 1));
	for (int i = 4; i < len; i++)
		new->id_employee[i - 4] = my_atoi(tab[i]);
	new->id_employee[len - 4] = -1;
	new->next = NULL;
	free_tab(tab);
	return (new);
}
