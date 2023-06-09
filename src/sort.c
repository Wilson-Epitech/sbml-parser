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

static char **sort_alphabetic_str(char **tab)
{
    int len = 0;

    for (int j = 0; tab[j] != NULL; j++) {
        len++;
    }
    for (int i = 1; i < len - 1; i++) {
        if (strcmp(tab[i], tab[i + 1]) > 0 && len > 0) {
            my_swap_str(&tab[i], &tab[i + 1]);
        }
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
