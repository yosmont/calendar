/*
** EPITECH PROJECT, 2018
** SYN_calendar_2017
** File description:
** sort function
*/

#include <string.h>
#include "project.h"

void meet_swap(meeting_t *one, meeting_t *two, meeting_t **head)
{
	meeting_t *prev = NULL;

	if ((*head)->id != one->id) {
		prev = *head;
		while (prev->next && one->id != prev->next->id) {
			prev = prev->next;
		}
	}
	one->next = two->next;
	two->next = one;
	if (prev) {
		prev->next = two;
	} else {
		*head = two;
	}
}

void meet_sortbydate(meeting_t **m_begin)
{
	meeting_t *m_tmp = *m_begin;
	int check = 0;

	while (m_tmp && m_tmp->next) {
		if (strcmp(m_tmp->day, m_tmp->next->day) > 0) {
			check = 1;
			meet_swap(m_tmp, m_tmp->next, m_begin);
		}
		m_tmp = m_tmp->next;
	}
	if (check == 1)
		meet_sortbydate(m_begin);
}

void meet_sortbyzip(meeting_t **m_begin)
{
	meeting_t *m_tmp = *m_begin;
	int check = 0;

	while (m_tmp && m_tmp->next) {
		if (strcmp(m_tmp->zipcode, m_tmp->next->zipcode) > 0) {
			check = 1;
			meet_swap(m_tmp, m_tmp->next, m_begin);
		}
		m_tmp = m_tmp->next;
	}
	if (check == 1)
		meet_sortbyzip(m_begin);
}

void meet_sortbyid(meeting_t **m_begin)
{
	meeting_t *m_tmp = *m_begin;
	int check = 0;

	while (m_tmp && m_tmp->next) {
		if (m_tmp->id > m_tmp->next->id) {
			check = 1;
			meet_swap(m_tmp, m_tmp->next, m_begin);
		}
		m_tmp = m_tmp->next;
	}
	if (check == 1)
		meet_sortbyid(m_begin);
}
