/*
** EPITECH PROJECT, 2018
** SYN_calendar_2017
** File description:
** requirement
*/

#include <stdlib.h>
#include <unistd.h>
#include "requirement.h"

int my_revlist_synthesis(list_t **begin)
{
	list_t *tmp = *begin;
	list_t *one = NULL;
	list_t *two = NULL;

	while (tmp) {
		two = tmp->next;
		tmp->next = one;
		one = tmp;
		tmp = two;
	}
	*begin = one;
	return (0);
}

list_t *my_findnodeeqinlist_synthesis(list_t *begin, void *data_ref,
	int(*cmp)(void *, void *))
{
	list_t *tmp = begin;

	while (tmp && cmp(data_ref, tmp->data) != 0)
		tmp = tmp->next;
	return (tmp);
}
