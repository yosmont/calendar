/*
** EPITECH PROJECT, 2018
** SYN_calendar_2017
** File description:
** lib my function
*/

#include <stdlib.h>
#include <string.h>
#include "project.h"

int my_begincmp(char *begin, char *long_str)
{
	int tmp = 0;

	for (tmp = 0; begin[tmp] == long_str[tmp]; tmp++);
	if (begin[tmp] == '\0')
		return (0);
	else
		return (begin[tmp] - long_str[tmp]);
}

int *intarr_addnb(int *arr, int nb)
{
	int emptablen = 0;
	int *new = NULL;

	for (; arr[emptablen] != -1; emptablen++);
	new = malloc(sizeof(int) * (emptablen + 2));
	for (int i = 0; arr[i] != -1; i++)
		new[i] = arr[i];
	free(arr);
	new[emptablen] = nb;
	new[emptablen + 1] = -1;
	arr = new;
	return (arr);
}

static int intcatcheckexist(int *arr, int nb, int end)
{
	for (int i = 0; i < end; i++)
		if (arr[i] == nb)
			return (1);
	return (0);
}

int *int_cat(int *arr, char **tab)
{
	int len = tablen(tab);
	int emptablen = 0;
	int z = 0;
	int nb = 0;

	for (; arr[emptablen] != -1; emptablen++);
	arr = realloc(arr, sizeof(int) * (emptablen + len + 1));
	for (int i = 0; i < len; i++) {
		nb = my_atoi(tab[i + z]);
		if (intcatcheckexist(arr, nb, (i + emptablen))) {
			i--;
			z++;
			len--;
			continue;
		}
		arr[i + emptablen] = nb;
	}
	arr[emptablen + len] = -1;
	return (arr);
}

int check_isfunction(char *str, int(*isf)(int c))
{
	for (int i = 0; str[i] != '\0'; i++)
		if (isf(str[i]) == 0)
			return (0);
	return (1);
}
