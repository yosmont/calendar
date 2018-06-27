/*
** EPITECH PROJECT, 2018
** SYN_calendar_2017
** File description:
** command
*/

#include <stdlib.h>
#include <string.h>
#include "project.h"

static int check_valid_sort_e(char *str, char **tab, int *idlist)
{
	char sort[5][15] = {"sortByName", "sortByForename", "sortByJob",
		"sortByZip", "sortById"};

	for (int i = 0; i < 5; i++)
		if (strcmp(str, sort[i]) == 0)
			return (1);
	free_tab(tab);
	if (idlist)
		free(idlist);
	return (0);
}

void check_info_e(char *line, employee_t **e_begin, meeting_t *m_begin)
{
	char **tab = my_str_to_word_array_synthesis(line);
	int *idlist = (tab) ? get_idlist(tab) : NULL;

	if (!tab || check_valid_sort_e(tab[0], tab, idlist) == 0)
		return;
	emp_sortbyid(e_begin);
	if (strcmp(tab[0], "sortByName") == 0 ||
	strcmp(tab[0], "sortByJob") == 0 || strcmp(tab[0], "sortByZip") == 0) {
		emp_sortbyforename(e_begin);
		emp_sortbyname(e_begin);
	}
	if (strcmp(tab[0], "sortByForename") == 0) {
		emp_sortbyname(e_begin);
		emp_sortbyforename(e_begin);
	}
	if (strcmp(tab[0], "sortByJob") == 0)
		emp_sortbyjob(e_begin);
	if (strcmp(tab[0], "sortByZip") == 0)
		emp_sortbyzip(e_begin);
	display(*e_begin, m_begin, 1, idlist);
	free_tab(tab);
}

static int check_valid_sort_m(char *str, char **tab, int *idlist)
{
	char sort[3][11] = {"sortByDate", "sortByZip", "sortById"};

	for (int i = 0; i < 3; i++)
		if (strcmp(str, sort[i]) == 0)
			return (1);
	free_tab(tab);
	if (idlist)
		free(idlist);
	return (0);
}

void check_info_m(char *line, employee_t *e_begin, meeting_t **m_begin)
{
	char **tab = my_str_to_word_array_synthesis(line);
	int *idlist = (tab) ? get_idlist(tab) : NULL;

	if (!tab || check_valid_sort_m(tab[0], tab, idlist) == 0)
		return;
	meet_sortbyid(m_begin);
	if (strcmp(tab[0], "sortByDate") == 0)
		meet_sortbydate(m_begin);
	if (strcmp(tab[0], "sortByZip") == 0)
		meet_sortbyzip(m_begin);
	display(e_begin, *m_begin, 0, idlist);
	free_tab(tab);
}

void add_id_to_employee(employee_t *empbegin, meeting_t *m_tmp, int i)
{
	employee_t *e_tmp = empbegin;

	while (e_tmp && e_tmp->id != m_tmp->id_employee[i])
		e_tmp = e_tmp->next;
	if (!e_tmp)
		return;
	e_tmp->id_meeting = intarr_addnb(e_tmp->id_meeting, m_tmp->id);
}
