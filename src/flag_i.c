/*
** SBML_PARSER PROJECT, 2023
** sbml-parser
** File description:
** display_name
*/

#include "lib.h"
#include "my.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


char **keep_important_line(char *str)
{
    static char **array = NULL;
    static int count = 0;

    if (strncmp(str, "xml", 3) == 0)
        return NULL;
    if (strncmp(str, "compartment", 11) != 0 && strncmp(str, "species", 7) != 0
        && strncmp(str, "reaction", 8) != 0)
        return NULL;
    count++;
    char **temp = realloc(array, sizeof(char *) * (count + 1));
    array = temp;
    array[count - 1] = strdup(str);
    array[count] = NULL;
    return array;
}

static char **keep_name(char *new_array, char *check)
{
    char **tab = my_word_array_delim(new_array, " ");
    int len = strlen(check);
    char *str = malloc(sizeof(char) * (len + 15));
    char *name = NULL;
    char **array = NULL;
    int count = 0;

    sprintf(str, "compartment=\"%s\"", check);
    for (int j = 0; tab[j] != NULL; j++) {
        if (strcmp(tab[j], str) == 0) {
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

static char **display_name2(char **array)
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

char **display_name(char **new_array, char *check, char **tmp)
{
    printf("List of species in compartment %s\n", check);
    for (int i = 0; new_array[i] != NULL; i++) {
        tmp = keep_name(new_array[i], check);
        if (tmp != NULL) {
            tmp = display_name2(tmp);
        }
    }
    return 0;
}
