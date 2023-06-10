/*
** SBML_PARSER PROJECT, 2023
** sbml-parser
** File description:
** nothing
*/

#include "my.h"
#include "lib.h"
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static char **nothing_compartement(char *new_array)
{
    char **tab = my_word_array_delim(new_array, " ");
    char *name = NULL;
    char **array = NULL;
    int count = 0;

    for (int j = 0; tab[j] != NULL; j++) {
        if (strncmp(tab[j], "compartment=", 12) == 0) {
            count ++;
            name = strdup(tab[j + 1]);
            array = realloc(array, sizeof(char *) * (count + 1));
            array[count - 1] = strdup(name);
            array[count] = NULL;
            return array;
        }
    }
    return NULL;
}

static char **display_nothing2(char **array)
{
    char **tab = NULL;
    char *str = NULL;

    for (int i = 0; array[i] != NULL; i++) {
        tab = my_word_array_delim(array[i], "\n");
    }
    for (int j = 0; tab[j] != NULL; j++) {
            tab[j] = ignore_before_equal(tab[j]);
            tab[j] = replace_dollars_space(tab[j]);
            tab[j] = clean_str(tab[j], "\"");
            str = malloc(sizeof(char) * (strlen(tab[j]) + 5));
            str = strcat(str, "--->");
            str = strcat(str, tab[j]);
            tab[j] = strdup(str);
            str[0] = '\0';
    }
    for (int i = 0; tab[i] != NULL; i++) {
        printf("%s\n", tab[i]);
    }
    return tab;
}

char **display_nothing(char **new_array, char **tmp)
{
    for (int i = 0; new_array[i] != NULL; i++) {
        tmp = nothing_compartement(new_array[i]);
        if (tmp != NULL) {
            tmp = display_nothing2(tmp);
        }
    }
    return 0;
}

int nothing_loop(char *buffer)
{
    char **array = my_word_array_delim(buffer, "\n");
    char **new_array = NULL;
    char **tmp = NULL;
    int nb = 0;

    for (int i = 0; array[i] != NULL; i++) {
        array[i] = remove_spaces(array[i]);
        array[i] = replace_spaces_dollars(array[i]);
        array[i] = clean_str(array[i], "<>?");
        nb = count_class(array[i]);
        if (nb != 0) {
            new_array = keep_important_line(array[i]);
        }
    }
    new_array = sort_alphabetic_str(new_array);
    printf("List of species\n");
    display_nothing(new_array, tmp);
    return 0;
}
