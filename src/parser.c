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

static char *stock_tag(const char *str, int i)
{
    int len = strlen(str);
    int buffer_len = (i == 0) ? len + 3 : len + 7;
    char *data = malloc(sizeof(char) * (buffer_len + 1));

    if (i == 0)
        sprintf(data, ".\n%s\n", str);
    else
        sprintf(data, "----->%s\n", str);
    return data;
}

static int extract_tag_name(char* str)
{
    char **tab = NULL;
    char *data = NULL;
    char *buffer = malloc(sizeof(char));

    if (strncmp(str, "<?xml", 5) == 0)
        return 0;
    str = replace_spaces_dollars(str);
    str = clean_str(str, "<>?");
    tab = my_word_array_delim(str, " ");
    *buffer = '\0';
    for (int i = 0; tab[i] != NULL; i++) {
        tab[i] = ignore_after_equal(tab[i]);
        data = stock_tag(tab[i], i);
        buffer = realloc(buffer, strlen(buffer) + strlen(data) + 1);
        strcat(buffer, data);
        free(data);
    }
    sort_alphabetic_buffer(buffer);
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
