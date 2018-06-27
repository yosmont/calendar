/*
** EPITECH PROJECT, 2018
** SYN_calendar_2017
** File description:
** sort function
*/

#include <string.h>
#include "project.h"

void emp_sortbyid(employee_t **e_begin)
{
	employee_t *e_tmp = *e_begin;
	int check = 0;

	while (e_tmp && e_tmp->next) {
		if (e_tmp->id > e_tmp->next->id) {
			check = 1;
			emp_swap(e_tmp, e_tmp->next, e_begin);
		}
		e_tmp = e_tmp->next;
	}
	if (check == 1)
		emp_sortbyid(e_begin);
}
