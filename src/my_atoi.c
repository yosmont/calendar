/*
** EPITECH PROJECT, 2018
** SYN_calendar_2017
** File description:
** my atoi
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "project.h"

void exit_comment(int fd, char *str, int rtn)
{
	write(fd, str, strlen(str));
	exit(rtn);
}

int my_atoi(char *str)
{
	int nb = 0;

	if (str == NULL || str[0] == '\0')
		return (-84);
	for (size_t i = 0; str[i] != '\0'; i++) {
		if (isdigit(str[i]) == 0)
			return (-84);
		nb = (nb * 10) + (str[i] - '0');
	}
	return (nb);
}
