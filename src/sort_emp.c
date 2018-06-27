/*
** EPITECH PROJECT, 2018
** SYN_calendar_2017
** File description:
** sort function
*/

#include <string.h>
#include "project.h"

void emp_swap(employee_t *one, employee_t *two, employee_t **head)
{
	employee_t *prev = NULL;

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

void emp_sortbyname(employee_t **e_begin)
{
	employee_t *e_tmp = *e_begin;
	int check = 0;

	while (e_tmp && e_tmp->next) {
		if (strcmp(e_tmp->last_name, e_tmp->next->last_name) > 0) {
			check = 1;
			emp_swap(e_tmp, e_tmp->next, e_begin);
		}
		e_tmp = e_tmp->next;
	}
	if (check == 1)
		emp_sortbyname(e_begin);
}

void emp_sortbyforename(employee_t **e_begin)
{
	employee_t *e_tmp = *e_begin;
	int check = 0;

	while (e_tmp && e_tmp->next) {
		if (strcmp(e_tmp->first_name, e_tmp->next->first_name) > 0) {
			check = 1;
			emp_swap(e_tmp, e_tmp->next, e_begin);
		}
		e_tmp = e_tmp->next;
	}
	if (check == 1)
		emp_sortbyforename(e_begin);
}

void emp_sortbyjob(employee_t **e_begin)
{
	employee_t *e_tmp = *e_begin;
	int check = 0;

	while (e_tmp && e_tmp->next) {
		if (strcmp(e_tmp->pos, e_tmp->next->pos) > 0) {
			check = 1;
			emp_swap(e_tmp, e_tmp->next, e_begin);
		}
		e_tmp = e_tmp->next;
	}
	if (check == 1)
		emp_sortbyjob(e_begin);
}

void emp_sortbyzip(employee_t **e_begin)
{
	employee_t *e_tmp = *e_begin;
	int check = 0;

	while (e_tmp && e_tmp->next) {
		if (strcmp(e_tmp->zipcode, e_tmp->next->zipcode) > 0) {
			check = 1;
			emp_swap(e_tmp, e_tmp->next, e_begin);
		}
		e_tmp = e_tmp->next;
	}
	if (check == 1)
		emp_sortbyzip(e_begin);
}
