/*
** EPITECH PROJECT, 2018
** SYN_calendar_2017
** File description:
** display two function
*/

#include "project.h"

int id_matches(int *idlist, int id)
{
	if (idlist == NULL)
		return (1);
	for (int i = 0; idlist[i] != -1; i++)
		if (idlist[i] == id)
			return (1);
	return (0);
}

int valid_meet(int *idlist, employee_t *e_begin)
{
	int check = 0;
	employee_t *e_tmp = NULL;

	for (int i = 0; idlist[i] != -1; i++) {
		e_tmp = e_begin;
		while (e_tmp && e_tmp->id != idlist[i])
			e_tmp = e_tmp->next;
		if (e_tmp)
			check++;
	}
	return ((check < 2) ? 0 : 1);
}
