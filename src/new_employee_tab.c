/*
** EPITECH PROJECT, 2018
** SYN_calendar_2017
** File description:
** command
*/

#include <stdlib.h>
#include <string.h>
#include "project.h"

static void add_id_to_meeting(meeting_t *meetbegin, employee_t *e_tmp, int i)
{
	meeting_t *m_tmp = meetbegin;

	while (m_tmp && m_tmp->id != e_tmp->id_meeting[i])
		m_tmp = m_tmp->next;
	if (!m_tmp)
		return;
	m_tmp->id_employee = intarr_addnb(m_tmp->id_employee, e_tmp->id);
}

void get_id_employee_tab(employee_t *empbegin, meeting_t *meetbegin)
{
	employee_t *e_tmp = empbegin;
	meeting_t *m_tmp = meetbegin;

	while (m_tmp) {
		free(m_tmp->id_employee);
		m_tmp->id_employee = malloc(sizeof(int) * 2);
		m_tmp->id_employee[0] = -1;
		m_tmp = m_tmp->next;
	}
	while (e_tmp) {
		for (int i = 0; e_tmp->id_meeting[i] != -1; i++) {
			add_id_to_meeting(meetbegin, e_tmp, i);
		}
		e_tmp = e_tmp->next;
	}
}
