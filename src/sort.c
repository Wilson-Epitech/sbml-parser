/*
** SBML_PARSER PROJECT, 2023
** sbml-parser
** File description:
** sort
*/

#include "lib.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>

static int sort_alphabetic_str_2(char **tab, int len, int swapped)
{
    for (int i = 1; i < len - 1; i++) {
            if (strcmp(tab[i], tab[i + 1]) > 0) {
                my_swap_str(&tab[i], &tab[i + 1]);
                swapped = 1;
            }
    }
    return swapped;
}

static char **sort_alphabetic_str(char **tab)
{
    int len = 0;
    int swapped = 1;

    for (int j = 0; tab[j] != NULL; j++) {
        len++;
    }
    while (swapped) {
        swapped = 0;
        swapped = sort_alphabetic_str_2(tab, len, swapped);
    }
    return tab;
}

int sort_alphabetic_buffer(char *buffer)
{
    char **array = my_word_array_delim(buffer, ".");
    char **tab = NULL;

    for (int i = 0; array[i] != NULL; i++) {
        tab = my_word_array_delim(array[i], "\n");
        tab = sort_alphabetic_str(tab);
    }
    for (int k = 0; tab[k] != NULL; k++) {
        printf("%s\n", tab[k]);
    }
    return 0;
}
