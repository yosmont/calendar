/*
** EPITECH PROJECT, 2018
** SYN_calendar_2017
** File description:
** delete from linked list
*/

#include <stdlib.h>
#include <string.h>
#include "project.h"

void free_meet_node(meeting_t *node)
{
	if (node) {
		node->next = NULL;
		free(node->day);
		free(node->zipcode);
		free(node->id_employee);
		free(node);
	}
}

meeting_t *cancel(char *line, meeting_t *begin)
{
	char **tab = my_str_to_word_array_synthesis(line);
	meeting_t *tmp;
	int search_id = (tablen(tab) < 2) ? -1 : 0;
	void *to_free;

	for (int i = 1; tab[i] != NULL && search_id != -1; i++) {
		search_id = my_atoi(tab[i]);
		tmp = begin;
		if (tmp->id == search_id) {
			begin = begin->next;
			free_meet_node(tmp);
			continue;
		}
		while (tmp->next && tmp->next->id != search_id)
			tmp = tmp->next;
		to_free = tmp->next;
		tmp->next = (tmp->next) ? tmp->next->next : NULL;
		free_meet_node(to_free);
	}
	free_tab(tab);
	return (begin);
}

void free_emp_node(employee_t *node)
{
	if (node) {
		node->next = NULL;
		free(node->last_name);
		free(node->first_name);
		free(node->pos);
		free(node->zipcode);
		free(node->id_meeting);
		free(node);
	}
}

employee_t *fire(char *line, employee_t *begin)
{
	char **tab = my_str_to_word_array_synthesis(line);
	employee_t *tmp;
	int search_id = (tablen(tab) < 2) ? -1 : 0;
	void *to_free;

	for (int i = 1; tab[i] != NULL && search_id != -1; i++) {
		search_id = my_atoi(tab[i]);
		tmp = begin;
		if (tmp->id == search_id) {
			begin = begin->next;
			free_emp_node(tmp);
			continue;
		}
		while (tmp->next && tmp->next->id != search_id)
			tmp = tmp->next;
		to_free = tmp->next;
		tmp->next = (tmp->next) ? tmp->next->next : NULL;
		free_emp_node(to_free);
	}
	free_tab(tab);
	return (begin);
}
