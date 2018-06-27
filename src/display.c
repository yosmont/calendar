/*
** EPITECH PROJECT, 2018
** SYN_calendar_2017
** File description:
** display function
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "project.h"

void print_employee_list(int *idlist, employee_t *e_begin, int skip)
{
	employee_t *e_tmp = e_begin;
	int check = 0;

	for (int i = 0; idlist[i] != -1; i++) {
		e_tmp = e_begin;
		if (idlist[i] == skip)
			continue;
		while (e_tmp && e_tmp->id != idlist[i])
			e_tmp = e_tmp->next;
		if (!e_tmp)
			continue;
		printf((check) ? ", %s %s" : "%s %s", e_tmp->first_name,
		e_tmp->last_name);
		check = 1;
	}
}

void print_meeting(employee_t *e_begin, meeting_t *m_begin, int *idlist)
{
	meeting_t *m_tmp = m_begin;

	while (m_tmp) {
		if (id_matches(idlist, m_tmp->id) &&
		valid_meet(m_tmp->id_employee, e_begin)) {
			printf("******************************\nMEETING\n");
			printf("date: %s\nplace: %s\n", m_tmp->day,
			m_tmp->zipcode);
			printf("with ");
			print_employee_list(m_tmp->id_employee, e_begin, -1);
			printf("\n");
		}
		m_tmp = m_tmp->next;
	}
}

void print_meeting_list(int *idlist, meeting_t *m_begin, employee_t *e_begin,
int id)
{
	meeting_t *m_tmp = m_begin;

	for (int i = 0; idlist[i] != -1; i++) {
		m_tmp = m_begin;
		while (m_tmp && m_tmp->id != idlist[i])
			m_tmp = m_tmp->next;
		if (!m_tmp || valid_meet(m_tmp->id_employee, e_begin) == 0)
			continue;
		printf("meeting on %s, %s, with ", m_tmp->day, m_tmp->zipcode);
		print_employee_list(m_tmp->id_employee, e_begin, id);
		printf("\n");
	}
}

void print_employee(employee_t *e_begin, meeting_t *m_begin, int *idlist)
{
	employee_t *e_tmp = e_begin;

	while (e_tmp) {
		if (id_matches(idlist, e_tmp->id)) {
			printf("******************************\n");
			printf("%s %s\nposition: %s\ncity: %s\n",
			e_tmp->first_name, e_tmp->last_name, e_tmp->pos,
			e_tmp->zipcode);
			print_meeting_list(e_tmp->id_meeting, m_begin, e_begin,
			e_tmp->id);
		}
		e_tmp = e_tmp->next;
	}
}

void display(employee_t *e_begin, meeting_t *m_begin, int whatprint,
int *idlist)
{
	if (whatprint == 0)
		print_meeting(e_begin, m_begin, idlist);
	else
		print_employee(e_begin, m_begin, idlist);
	if (idlist)
		free(idlist);
}
