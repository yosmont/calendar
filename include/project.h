/*
** EPITECH PROJECT, 2018
** yet another header
** File description:
** header
*/

#include <stdio.h>

#ifndef PROJECT_H_
	#define PROJECT_H_

typedef struct employee {
	int id;
	char *last_name;
	char *first_name;
	char *pos;
	char *zipcode;
	int *id_meeting;
	struct employee *next;
} employee_t;

typedef struct meeting {
	int id;
	char *day;
	char *zipcode;
	int *id_employee;
	struct meeting *next;
} meeting_t;

int tablen(char **tab);
employee_t *new_employee(char *line);
meeting_t *new_meeting(char *line);
int *int_cat(int *arr, char **tab);
void invite(char *line, meeting_t *begin);
void intarr_suppr(int *arr, int test);
int *intarr_exc(int *arr, char **tab);
void exclude(char *line, meeting_t *begin);
void free_tab(char **tab);
char **my_str_to_word_array_synthesis(char const *str);
void exit_comment(int fd, char *str, int rtn);
int my_atoi(char *str);
void free_meet_node(meeting_t *node);
meeting_t *cancel(char *line, meeting_t *begin);
void free_emp_node(employee_t *node);
employee_t *fire(char *line, employee_t *begin);
int my_begincmp(char *begin, char *long_str);
int *intarr_addnb(int *arr, int nb);
char *gnl(FILE *fd);
void display(employee_t *e_begin, meeting_t *m_begin, int whatprint,
	int *idlist);
int id_matches(int *idlist, int id);
void create_list(void);
void free_emp(employee_t *list);
void free_meet(meeting_t *list);
void emp_swap_hard(employee_t *one, employee_t *two);
void emp_swap(employee_t *one, employee_t *two, employee_t **head);
void emp_sortbyname(employee_t **e_begin);
void emp_sortbyforename(employee_t **e_begin);
void emp_sortbyjob(employee_t **e_begin);
void emp_sortbyzip(employee_t **e_begin);
void emp_sortbyid(employee_t **e_begin);
void meet_swap_hard(meeting_t *one, meeting_t *two);
void meet_swap(meeting_t *one, meeting_t *two, meeting_t **head);
void meet_sortbydate(meeting_t **m_begin);
void meet_sortbyzip(meeting_t **m_begin);
void meet_sortbyid(meeting_t **m_begin);
void check_info_e(char *line, employee_t **e_begin, meeting_t *m_begin);
void check_info_m(char *line, employee_t *e_begin, meeting_t **m_begin);
int *get_idlist(char **tab);
int valid_meet(int *idlist, employee_t *e_begin);
int check_isfunction(char *str, int(*isf)(int c));
void add_id_to_employee(employee_t *empbegin, meeting_t *m_tmp, int i);
void get_id_employee_tab(employee_t *empbegin, meeting_t *meetbegin);

#endif /* !PROJECT_H_ */
