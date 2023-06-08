/*
** SBML_PARSER PROJECT, 2023
** sbml-parser
** File description:
** parser
*/

#include "lib.h"
#include "my.h"
#include <stdlib.h>
#include <string.h>

#include <stdio.h>

static char *ignore_after_equal(char *str)
{
    char *new_str = NULL;
    int count = 0;
    int i = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '=') {
            break;
        }
        count++;
    }
    new_str = malloc(sizeof(char) * (count + 1));
    for (i = 0; i < count; i++) {
        new_str[i] = str[i];
    }
    new_str[count] = '\0';
    return new_str;
}

static int extract_tag_name(char* str)
{
    char **tab = NULL;

    if (strncmp(str, "<?xml", 5) == 0)
        return 0;
    str = replace_spaces_dollars(str);
    str = clean_str(str, "<>?");
    tab = my_word_array_delim(str, " ");
    for (int i = 0; tab[i] != NULL; i++) {
        tab[i] = ignore_after_equal(tab[i]);
        printf("[%s]\n", tab[i]);
    }
    return 0;
}

static int no_flag_loop(char *buffer)
{
    char **array = my_word_array_delim(buffer, "\n");
    int nb = 0;
    int nb_lines = get_nb_lines(array);

    array = remove_duplicates_lines(array, nb_lines);
    for (int i = 0; array[i] != NULL; i++) {
        array[i] = remove_spaces(array[i]);
        nb = count_class(array[i]);
        if (nb != 0) {
            extract_tag_name(array[i]);
        }
    }
    return 0;
}

int parser_loop(char *buffer)
{
    no_flag_loop(buffer);
    return 0;
}
