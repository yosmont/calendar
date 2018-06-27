/*
** EPITECH PROJECT, 2018
** SYN_calendar_2017
** File description:
** command
*/

#include <stdlib.h>
#include <string.h>
#include "project.h"

static employee_t *check_employee_cmd(char *line, employee_t **begin)
{
	employee_t *tmp = *begin;
	int check = (*begin) ? 1 : 0;

	while (tmp && tmp->next)
		tmp = tmp->next;
	if (my_begincmp("new_employee", line) == 0) {
		if (check == 1)
			tmp->next = new_employee(line);
		else
			*begin = new_employee(line);
	}
	if (my_begincmp("fire", line) == 0)
		*begin = fire(line, *begin);
	return (*begin);
}

static meeting_t *check_meeting_cmd(char *line, meeting_t **begin)
{
	meeting_t *tmp = *begin;
	int check = (*begin) ? 1 : 0;

	while (tmp && tmp->next)
		tmp = tmp->next;
	if (my_begincmp("new_meeting", line) == 0) {
		if (check == 1)
			tmp->next = new_meeting(line);
		else
			*begin = new_meeting(line);
	}
	if (my_begincmp("cancel", line) == 0)
		*begin = cancel(line, *begin);
	if (my_begincmp("invite", line) == 0)
		invite(line, *begin);
	if (my_begincmp("exclude", line) == 0)
		exclude(line, *begin);
	return (*begin);
}

static void get_id_meeting_tab(employee_t **empbegin, meeting_t **meetbegin)
{
	employee_t *e_tmp = *empbegin;
	meeting_t *m_tmp = *meetbegin;

	meet_sortbyid(meetbegin);
	meet_sortbyzip(meetbegin);
	meet_sortbydate(meetbegin);
	emp_sortbyforename(empbegin);
	emp_sortbyname(empbegin);
	while (e_tmp) {
		free(e_tmp->id_meeting);
		e_tmp->id_meeting = malloc(sizeof(int) * 2);
		e_tmp->id_meeting[0] = -1;
		e_tmp = e_tmp->next;
	}
	while (m_tmp) {
		for (int i = 0; m_tmp->id_employee[i] != -1; i++) {
			add_id_to_employee(*empbegin, m_tmp, i);
		}
		m_tmp = m_tmp->next;
	}
	get_id_employee_tab(*empbegin, *meetbegin);
}

int *get_idlist(char **tab)
{
	int *idlist = NULL;

	if (tab[1]) {
		idlist = malloc(sizeof(int) * 2);
		idlist[0] = -1;
		for (int i = 1; tab[i]; i++)
			idlist = intarr_addnb(idlist, my_atoi(tab[i]));
	}
	return (idlist);
}

void create_list(void)
{
	employee_t *employee = NULL;
	meeting_t *meeting = NULL;
	char *line = gnl(stdin);

	while (line && my_begincmp("END", line) != 0) {
		employee = check_employee_cmd(line, &employee);
		meeting = check_meeting_cmd(line, &meeting);
		if (my_begincmp("info_employees", line) == 0)
			check_info_e(&line[15], &employee, meeting);
		else if (my_begincmp("info_meetings", line) == 0)
			check_info_m(&line[14], employee, &meeting);
		free(line);
		line = gnl(stdin);
		if (meeting)
			get_id_meeting_tab(&employee, &meeting);
	}
	if (line)
		free(line);
	free_emp(employee);
	free_meet(meeting);
}
