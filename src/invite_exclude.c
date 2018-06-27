/*
** EPITECH PROJECT, 2018
** SYN_calendar_2017
** File description:
** add to list function
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "project.h"

void invite(char *line, meeting_t *begin)
{
	meeting_t *tmp = begin;
	char **tab = my_str_to_word_array_synthesis(line);
	int len = tablen(tab);
	int search_id = 0;

	if (len > 2) {
		search_id = my_atoi(tab[1]);
		while (tmp && tmp->id != search_id)
			tmp = tmp->next;
		if (tmp)
			tmp->id_employee = int_cat(tmp->id_employee, &tab[2]);
	}
	free_tab(tab);
}

void intarr_suppr(int *arr, int test)
{
	if (arr[0] == test)
		for (int i = 0; arr[i] != -1; i++)
			arr[i] = arr[i + 1];
}

int *intarr_exc(int *arr, char **tab)
{
	int len = tablen(tab);
	int *tmp = malloc(sizeof(int) * (len + 1));

	for (int i = 0; i < len; i++)
		tmp[i] = my_atoi(tab[i]);
	tmp[len] = -1;
	for (int i = 0; arr[i] != -1; i++)
		for (int j = 0; tmp[j] != -1; j++)
			intarr_suppr(&arr[i], tmp[j]);
	free(tmp);
	return (arr);
}

void exclude(char *line, meeting_t *begin)
{
	meeting_t *tmp = begin;
	char **tab = my_str_to_word_array_synthesis(line);
	int search_id = 0;

	if (tablen(tab) > 2) {
		search_id = my_atoi(tab[1]);
		while (tmp && tmp->id != search_id)
			tmp = tmp->next;
		if (tmp)
			tmp->id_employee = intarr_exc(tmp->id_employee,
			&tab[2]);
	}
	free_tab(tab);
}
