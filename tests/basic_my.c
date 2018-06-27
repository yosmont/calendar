/*
** EPITECH PROJECT, 2018
** SYN_palindrome_2017
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include <ctype.h>
#include "project.h"

Test(basic_my, test_tab_and_intarr)
{
	char **tab = malloc(sizeof(char) * 10);
	int *arr;

	for (int i = 0; i < 9; i++) {
		tab[i] = malloc(sizeof(char) * 4);
		tab[i][0] = 'h';
		tab[i][1] = 'e';
		tab[i][2] = 'y';
		tab[i][3] = '\0';
	}
	tab[9] = NULL;
	cr_expect_str_eq(tab[3], "hey");
	cr_expect(tablen(tab) == 9);
	tab = my_str_to_word_array_synthesis("hello world of here");
	cr_expect_str_eq(tab[1], "world");
	cr_expect(tablen(tab) == 4);
	tab = my_str_to_word_array_synthesis("hey 10 111 9 54");
	arr = get_idlist(tab);
	cr_expect(arr[0] == 10 && arr[1] == 111 && arr[2] == 9 && arr[3] == 54);
}

Test(basic_my, test_atoi_isfunction)
{
	cr_expect(check_isfunction("hey", &isalpha) == 1);
	cr_expect(check_isfunction("h3110 7h3r3", &isalpha) == 0);
	cr_expect(check_isfunction("42", &isdigit) == 1);
	cr_expect(check_isfunction("quarante-deux", &isdigit) == 0);
	cr_expect(check_isfunction("hey", &isalpha) == 1);
	cr_expect(my_atoi("84") == 84);
	cr_expect(my_atoi("-10") == -84);
	cr_expect(my_atoi("hey") == -84);

}

Test(basic_my, test_intarr)
{
	char **tab = my_str_to_word_array_synthesis("hey 10 111 9 54");
	int *arr = get_idlist(tab);

	cr_expect(arr[0] == 10 && arr[1] == 111 && arr[2] == 9 && arr[3] == 54);
	arr = intarr_addnb(arr, 666);
	cr_expect(arr[4] == 666);
	tab = my_str_to_word_array_synthesis("42 84");
	arr = int_cat(arr, tab);
	cr_expect(arr[5] == 42 && arr[6] == 84);
	cr_expect(my_begincmp("hello", "hello there") == 0);
}
